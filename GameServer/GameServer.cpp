// GameServer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>


class SpinLock 
{
public:
	void lock()
	{
		// CAS (Compare And Swap)

		bool expected = false;
		bool desired = true;

		// CAS 의사 코드
		/*if (_locked == expected)
		{
			expected = _locked;
			_locked = desired;
			return true;
		}
		else
		{
			expected = _locked;
			return false;
		}*/

		while (_locked.compare_exchange_strong(expected, desired) == false)
		{
			expected = false;

			//std::this_thread::sleep_for(std::chrono::milliseconds(100));
			using namespace std;
			std::this_thread::sleep_for(0ms);
			//std::this_thread::yield();

			/*
			std::this_thread::sleep_for(0ms);
			std::this_thread::yield();

			의미적으로 위 두 라인은 같음
			*/
		}
	}

	void unlock()
	{
		_locked.store(false);
	}
private:
	std::atomic<bool> _locked = false;
};

int32 sum = 0;
std::mutex m;
SpinLock spinLock;

void Add()
{
	for (int32 i = 0; i < 1'000'000; i++)
	{
		std::lock_guard<SpinLock> guard(spinLock);
		sum++;
	}
}

void Sub()
{
	for (int32 i = 0; i < 1'000'000; i++)
	{
		std::lock_guard<SpinLock> guard(spinLock);
		sum--;
	}
}

int main()
{


	std::thread t1(Add);
	std::thread t2(Sub);

	t1.join();
	t2.join();

	std::cout << sum << std::endl;
}