// GameServer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include "CorePch.h"

#include <thread>

void HelloThread()
{
    std::cout << "Hello Thread" << std::endl;
}

void HelloThread_2(int32 num)
{
    std::cout << num << std::endl;
}

int main()
{
    // System Call (OS 커널 요청)
    //std::cout << "Hello World" << std::endl;

    std::thread t;
    t = std::thread(HelloThread);

    int32 count = t.hardware_concurrency(); // CPU 코어 개수?
    auto id = t.get_id(); // 쓰레드마다 id
    t.detach(); // std::thread 객체에서 실제 쓰레드를 분리

    if (t.joinable())
        t.join();


    std::vector<std::thread> v;
    for (int32 i = 0; i < 10; i++)
    {
        v.push_back(std::thread(HelloThread_2, i));
    }

    for (int32 i = 0; i < 10; i++)
    {
        if (v[i].joinable())
            v[i].join();
    }


    std::cout << "Hello Main" << std::endl;

}