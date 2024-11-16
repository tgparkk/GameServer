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

	// ������ �κ��丮�� ����Ʈ�� ������ ������ ���� ����
	Knight& _knight;
};

int main()
{
	// RefCountable ���� ����Ʈ������ ���� ����
	// 1) �̹� ������� Ŭ���� ������� ��� �Ұ� - RefCountable �� ��۹޾ƾ� �ϱ� ������
	// 2) ��ȯ(Cycle) ���� - std:: ����Ʈ�����͵� ����

	KnightRef k1(new Knight());
	k1->ReleaseRef();

	k1->_inventory = new Inventory(k1);


}