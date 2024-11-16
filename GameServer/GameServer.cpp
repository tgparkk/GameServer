#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>
#include "ThreadManager.h"

#include "RefCounting.h"


class Knight{
public:
	Knight()
	{
		cout << "Knight()" << endl;
	}
	
	~Knight()
	{
		cout << "~Knight()" << endl;

	}


};




int main()
{
	// RefCountable 으로 스마트포인터 사용시 단점
	// 1) 이미 만들어진 클래스 대상으로 사용 불가 - RefCountable 를 상송받아야 하기 때문에
	// 2) 순환(Cycle) 문제 - std:: 스마트포인터도 문제



	// unique_ptr
	// 
	// shared_ptr
	// weak_ptr

	// shared_ptr
	/*
	shaerd_ptr 로 생성시
	[Knight][RefCountingBlock(uses, weak)]

	[T*][RefCountingBlocking*]
	위 두개의 구조가 생긴다.
	*/

	// [Knight][RefCountingBlock(usesCount(shared), weakCount)]
	shared_ptr<Knight> spr(new Knight());

	// 아래 코드는
	/*
	결과적으로
	[Knight][RefCountingBlock]

	[T*][RefCountingBlocking*]
	[T*][RefCountingBlocking*]
	
	위 구조들이 생깁니다.
	*/
	shared_ptr<Knight> spr2 = spr;

	// make_shared 는 [Knight | RefCountingBlock] 한 공간으로 생성
	shared_ptr< Knight> sprm = make_shared<Knight>();


	weak_ptr<Knight> wpr = spr;
	
	bool expired = wpr.expired();
	shared_ptr<Knight> spr3 = wpr.lock();

}