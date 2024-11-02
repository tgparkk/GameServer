// GameServer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>

std::vector<int32> v;

// Mutual Exclusive (상호배타적)
std::mutex m;

// RAII (Resource Acquisition Is Intialization)
template<typename T>
class LockGuard
{
public:
	LockGuard(T& m)
	{
		_mutex = &m;
		_mutex->lock();
	}
	~LockGuard()
	{
		_mutex->unlock();
	}

private:
	T* _mutex;
};

void Push()
{
	std::lock_guard<std::mutex> lockguard(m);
	for (int32 i= 0; i < 10000; i++)
	{
		// 자물쇠 잠그기
		//m.lock();
		//LockGuard<std::mutex> lockguard(m);
		//std::lock_guard<std::mutex> lockguard(m);

		//std::unique_lock<std::mutex> uniqueLock(m, std::defer_lock);


		// lock 을 뒤로 미를수있음
		//uniqueLock.lock();

		v.push_back(i);

		//if (i == 5000)
		//	break;
		
		// 자물쇠 풀기
		//m.unlock();
	}
}

int main()
{
	std::thread t1(Push);
	std::thread t2(Push);

	t1.join();
	t2.join();

	std::cout << v.size() << std::endl;
}