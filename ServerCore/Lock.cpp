#include "pch.h"
#include "Lock.h"
#include "CoreTLS.h"
#include "DeadLockProfiler.h"


void Lock::WriteLock(const char* name)
{
#if _DEBUG
	GDeadLockProfiler->PushLock(name);
#endif

	// 동일한 쓰레드가 소유하고 있다면 무조건 성공.
									//상위 16비트를 내려서 LThreadId 가져오기
	const uint32 lockThreadId = (_lockFlag.load() & WRITE_THREAD_MASK) >> 16;
	if (LThreadId == lockThreadId)
	{
		_writeCount++;
		return;
	}

	// 아무도 소유 및 공유하고 있지 않을 때, 경합해서 소유권을 얻는다.
	const int64 beginTick = ::GetTickCount64();

							// 상위 16비트에 본인의 lock 번호 기입
							// 16비트 이동시켜서 WRITE_THREAD_MASK 대입
							// [thread_id][thread_id][00000000][00000000]
	const uint32 desired = ((LThreadId << 16) & WRITE_THREAD_MASK);
	while (true)
	{
		for (uint32 spinCount = 0; spinCount < MAX_SPIN_COUNT; spinCount++)
		{
			uint32 expected = EMPTY_FLAG;
			//_lockFlag 가 expected 와 같으면 (EMPTY_FLAG) 
			// 그때, _lockFlag 를 desired 로 변경
			if (_lockFlag.compare_exchange_strong(OUT expected, desired))
			{
				_writeCount++;
				return;
			}
		}

		if (::GetTickCount64() - beginTick >= ACQUIRE_TIMEOUT_TICK)
			CRASH("LOCK_TIMEOUT");

		// 소유권 놓기
		this_thread::yield();
	}
}

void Lock::WriteUnlock(const char* name)
{
#if _DEBUG
	GDeadLockProfiler->PopLock(name);
#endif
	// ReadLock 다 풀기 전에는 WriteUnlock 불가능.
	if ((_lockFlag.load() & READ_COUNT_MASK) != 0)
		CRASH("INVALID_UNLOCK_ORDER");

	const int32 lockCount = --_writeCount;
	if (lockCount == 0)
		_lockFlag.store(EMPTY_FLAG);
}

void Lock::ReadLock(const char* name)
{
#if _DEBUG
	GDeadLockProfiler->PushLock(name);
#endif
	// 동일한 쓰레드가 소유하고 있다면 무조건 성공.
	const uint32 lockThreadId = (_lockFlag.load() & WRITE_THREAD_MASK) >> 16;
	if (LThreadId == lockThreadId)
	{
		_lockFlag.fetch_add(1);
		return;
	}

	// 아무도 소유하고 있지(wwww~~ 구역(상위 16비트?)에 아무것도 없을때) 
	// 않을 때 경합해서 공유 카운트를 올린다.
	const int64 beginTick = ::GetTickCount64();
	while (true)
	{
		for (uint32 spinCount = 0; spinCount < MAX_SPIN_COUNT; spinCount++)
		{
			uint32 expected = (_lockFlag.load() & READ_COUNT_MASK);
			if (_lockFlag.compare_exchange_strong(OUT expected, expected + 1))
				return;
		}

		if (::GetTickCount64() - beginTick >= ACQUIRE_TIMEOUT_TICK)
			CRASH("LOCK_TIMEOUT");

		this_thread::yield();
	}
}

void Lock::ReadUnlock(const char* name)
{
#if _DEBUG
	GDeadLockProfiler->PopLock(name);
#endif
	// fetch_sub 은 파라미터 만큼 뺀 다음에
	// 이전 값을 리턴
	if ((_lockFlag.fetch_sub(1) & READ_COUNT_MASK) == 0)
		CRASH("MULTIPLE_UNLOCK");
}
