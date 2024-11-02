// GameServer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>

std::atomic<int32> sum = 0;

void Add()
{
	for (int32 i = 0; i < 1'000'000; i++)
	{
		sum.fetch_add(1); // sum++;  같음 , 오버로딩
	}
}

void Sub()
{
	for (int32 i = 0; i < 1'000'000; i++)
	{
		sum.fetch_add(-1); // sum--;  같음 , 오버로딩
	}
}

int main()
{
	Add();
	Sub();
	std::cout << sum << std::endl;

	std::thread t1(Add);
	std::thread t2(Sub);
	t1.join();
	t2.join();

	std::cout << sum << std::endl;
}