// GameServer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <windows.h>

std::mutex m;
std::queue<int32> q;

HANDLE handle;

void Producer()
{
	while (true)
	{
		{
			std::unique_lock<std::mutex> lock(m);
			q.push(100);
		}
	
		::SetEvent(handle);


		std::this_thread::sleep_for(std::chrono::milliseconds(1000000));
	}
}

void Consumer()
{
	while (true)
	{
		::WaitForSingleObject(handle, INFINITE);

		std::unique_lock<std::mutex> lock(m);
		if (q.empty() == false)
		{
			int32 data = q.front();
			q.pop();
			std::cout << data << std::endl;
		}
	}
}

int main()
{
	// 커널 오브젝트
	// Usage Count
	// Signal (파란불) / Non-Signal (빨간불) << bool
	// Auto / Manual << bool
	handle = ::CreateEvent(NULL/*보안속성*/, FALSE/*bManualReset*/, FALSE/*bInitialState*/, NULL);

	std::thread t1(Producer);
	std::thread t2(Consumer);

	t1.join();
	t2.join();

	::CloseHandle(handle);
}