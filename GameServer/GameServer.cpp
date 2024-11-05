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

std::atomic<bool> ready;
int32 value;

void Producer()
{
	value = 10;

	ready.store(true, std::memory_order_seq_cst);
}

void Consumer()
{
	while (ready.load(std::memory_order_seq_cst) == false)
		;

	std::cout << value << std::endl;
}


std::atomic<bool> flag = false;

int main()
{
	ready = false;
	value = 0;
	std::thread t1(Producer);
	std::thread t2(Consumer);
	t1.join();
	t2.join();


	// Memory Model (정책)
	// 1) Sequentially Consistent (seq_cst)
	// 가장 엄격 = 컴파일러 최적화 여지 적음 = 직관적
	// 
	// 2) Acquire-Release (acquire, release)
	// 3) Relaxed (relaxed)
	// 자유롭다 = 컴파일러 최적화 여지 많음 = 직관적이지 않음



	////flag = true;
	//flag.store(true, std::memory_order_seq_cst);

	////bool val = flag;
	//bool val = flag.load(std::memory_order_seq_cst);

	//// 이전 flag 값을 prev에 넣고, flag 값을 수정
	//{
	//	//bool prev = flag;
	//	//flag = true;
	//	bool prev = flag.exchange(true);
	//	
	//}

	//// CAS (Compare-And_Swap) 조건부 수정
	//{
	//	bool expected = false;
	//	bool desired = true;
	//	flag.compare_exchange_strong(expected, desired);

	//	/*
	//	아래는 flag.compare_exchange_strong(expected, desired); 의 의사코드
	//	if (flag == expected)
	//	{
	//		flag = desired;
	//		return true;
	//	}
	//	else
	//	{
	//		expected = flag;
	//		return false;
	//	}
	//	*/

	//	while (true)
	//	{
	//		bool expected = false;
	//		bool desired = true;
	//		flag.compare_exchange_weak(expected, desired);
	//		// compare_exchange_weak 는 if(flag == expected) 
	//		// 안으로 들어와도 memory interuption 발생시 return false;
	//	}
	//	
	//}

}