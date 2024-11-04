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

int64 result;

int64 Calculate()
{
	int64 sum = 0;
	for (int32 i = 0; i < 1'000'000; i++)
		sum += i;

	result = sum;

	return sum;
}

void PromiseWorker(std::promise<std::string>&& promise)
{
	promise.set_value("Secret Message");
}

void TaskWorker(std::packaged_task<int64(void)>&& task)
{
	task();
}

int main()
{
	// 동기(synchronous) 실행
	// int64 sum = Calculate();

	// std::future
	{
		// std::launch 의 3가지 옵션
		// 1) deferred -> lazy evalution 지연해서 실행하세요.
		// 2) async -> 별도의 스레드를 만들어서 실행하세요.
		// 3) deferred | async -> 둘 중 알아서 골라주세요.

		// 언젠가 미래에 결과물을 뱉어줄거야!
		std::future<int64> future = std::async(std::launch::async, Calculate);

		// TODO


		//확인방법 1
		/*
		future.wait();
		*/
		int64 sum = future.get(); // 결과물이 이제서야 필요하다.

		//확인방법 2
		std::future_status status = future.wait_for(std::chrono::milliseconds(1));
		if (status == std::future_status::ready)
		{

		}

		// 멤버함수를 사용하는법
		class A
		{
		public:
			int64 GetHp() { return 100; }
		};
		A a;
		std::future<int64> future2 = std::async(std::launch::async, &A::GetHp, a);


	}

	// std::promise
	{
		// 미래(std::future) 에 결과물을 반환해줄꺼라 약속(std::promise) 해줘 (계약서?)
		std::promise<std::string> promise;
		std::future<std::string> future = promise.get_future();

		std::thread t(PromiseWorker, std::move(promise));

		std::string message = future.get();

		std::cout << message << std::endl;

		t.join();
	}

	// std::packaged_task
	{
		std::packaged_task<int64(void)> task(Calculate);
		std::future<int64> future = task.get_future();

		std::thread t(TaskWorker, std::move(task));

		int64 message = future.get();

		std::cout << message << std::endl;

		t.join();
	}

	// 결론)
	// std::mutex, std::condition_variable 까지 가지 않고 단순한 애들을 처리할 수 있는
	// 특히나, 한 번 발생하는 이벤트에 유용하다!
	// 닭잡는데 소잡는 칼을 쓸 필요 없다!

	// 1) async
	// 원하는 함수를 비동기적으로 실행

	// 2) promise
	// 결과물을 promise 를 통해 future 로 받아줌

	// 3) packaged_task
	// 원하는 함수의 실행 결과를 packaged_task 를 통해 future 로 받아줌
}