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

int32 x = 0;
int32 y = 0;
int32 r1 = 0;
int32 r2 = 0;

volatile bool ready; // 컴파일러에게 최적화 하지말라고 하기 위해 volatile 붙임

void Thread_1()
{
	while (!ready);
	y = 1; // Store y
	r1 = x; // Load x
}

void Thread_2()
{
	while (!ready);
	x = 1; // Store x
	r2 = x; // Load y
}

int main()
{
	int32 count = 0;

	while (true)
	{
		ready = false;
		count++;

		x = y = r1 = r2 = 0;

		std::thread t1(Thread_1);
		std::thread t2(Thread_2);

		ready = true;

		t1.join();
		t2.join();

		if (r1 == 0 && r2 == 0)
			break;
	}


	std::cout << count << " 번만에 빠져나옴~" << std::endl;
}