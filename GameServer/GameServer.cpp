#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>
#include "ConcurrentQueue.h"
#include "ConcurrentStack.h"

LockQueue<int32> q;
LockFreeStack<int32> s;

void Push()
{
	while (true)
	{
		int32 value = rand() % 100;
		s.Push(value);

		//std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

void Pop()
{
	while (true)
	{
		auto data = s.TryPop();
		if (data != nullptr)
			std::cout << (*data) << std::endl;
	}
}


int main()
{
	//std::shared_ptr<int32> ptr;
	//bool value = std::atomic_is_lock_free(&ptr);

	std::thread t1(Push);
	std::thread t2(Pop);
	std::thread t3(Pop);

	t1.join();
	t2.join();
	t3.join();
}