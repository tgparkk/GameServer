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
	// RefCountable ���� ����Ʈ������ ���� ����
	// 1) �̹� ������� Ŭ���� ������� ��� �Ұ� - RefCountable �� ��۹޾ƾ� �ϱ� ������
	// 2) ��ȯ(Cycle) ���� - std:: ����Ʈ�����͵� ����



	// unique_ptr
	// 
	// shared_ptr
	// weak_ptr

	// shared_ptr
	/*
	shaerd_ptr �� ������
	[Knight][RefCountingBlock(uses, weak)]

	[T*][RefCountingBlocking*]
	�� �ΰ��� ������ �����.
	*/

	// [Knight][RefCountingBlock(usesCount(shared), weakCount)]
	shared_ptr<Knight> spr(new Knight());

	// �Ʒ� �ڵ��
	/*
	���������
	[Knight][RefCountingBlock]

	[T*][RefCountingBlocking*]
	[T*][RefCountingBlocking*]
	
	�� �������� ����ϴ�.
	*/
	shared_ptr<Knight> spr2 = spr;

	// make_shared �� [Knight | RefCountingBlock] �� �������� ����
	shared_ptr< Knight> sprm = make_shared<Knight>();


	weak_ptr<Knight> wpr = spr;
	
	bool expired = wpr.expired();
	shared_ptr<Knight> spr3 = wpr.lock();

}