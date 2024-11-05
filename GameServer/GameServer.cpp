// GameServer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>

//__declspec(thread) int32 value;
thread_local int32 LThread = 0;


void ThreadMain(int32 threadId)
{
	LThread = threadId;

	while (true)
	{
		std::cout << "Hi ! I am Thread : " << LThread << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

int main()
{
	std::vector<std::thread> threads;
	for (int32 i = 0; i < 10; i++)
	{
		int32 threadId = i + 1;
		threads.push_back(std::thread(ThreadMain, threadId));
	}

	for (auto& t : threads)
		t.join();
}