#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>
#include "ThreadManager.h"

#include "RefCounting.h"

using KnightRef = TSharedPtr<class Knight>;
using InventoryRef = TSharedPtr<class Inventory>;

class Knight : public RefCountable
{
public:
	Knight()
	{
		cout << "Knight()" << endl;
	}
	
	~Knight()
	{
		cout << "~Knight()" << endl;

	}

	void SetTarget(KnightRef target) {
		_target = target;
	}

	KnightRef _target = nullptr;
	InventoryRef _inventory = nullptr;
};


class Inventory : public RefCountable
{
public:
	Inventory(KnightRef knight) : _knight(**knight)
	{

	}

	// 참조로 인벤토리가 나이트를 가지고 있으면 문제 없음
	Knight& _knight;
};

int main()
{
	// RefCountable 으로 스마트포인터 사용시 단점
	// 1) 이미 만들어진 클래스 대상으로 사용 불가 - RefCountable 를 상송받아야 하기 때문에
	// 2) 순환(Cycle) 문제 - std:: 스마트포인터도 문제

	KnightRef k1(new Knight());
	k1->ReleaseRef();

	k1->_inventory = new Inventory(k1);


}