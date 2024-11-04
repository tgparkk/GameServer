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

#include <windows.h>

int32 buffer[10000][10000];

int main()
{
	memset(buffer, 0, sizeof(buffer));
	{
		uint64 start = GetTickCount64();

		int64 sum = 0;
		for (int32 i = 0; i < 10000; i++)
			for (int32 j = 0; j < 10000; j++)
				sum += buffer[i][j];

		uint64 end = GetTickCount64();

		std::cout << "Elapsed Tick" << (end - start) << std::endl;
	}

	memset(buffer, 0, sizeof(buffer));
	{
		uint64 start = GetTickCount64();

		int64 sum = 0;
		for (int32 i = 0; i < 10000; i++)
			for (int32 j = 0; j < 10000; j++)
				sum += buffer[j][i];

		uint64 end = GetTickCount64();

		std::cout << "Elapsed Tick" << (end - start) << std::endl;
	}
}