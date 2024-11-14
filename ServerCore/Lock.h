#pragma once
#include "Types.h"

/*----------------
    RW SpinLock
-----------------*/

/*--------------------------------------------
* 32비트
* int32 에서 한번에 관리 가능
* 
[WWWWWWWW][WWWWWWWW][RRRRRRRR][RRRRRRRR]
W : WriteFlag (Exclusive Lock Owner ThreadId)
R : ReadFlag (Shared Lock Count)
---------------------------------------------*/

// W -> W (O)
// W -> R (O)
// R -> W (X)
// read lock 에서 write lock 을 잡진 않는다.
class Lock
{
    enum : uint32
    {
        ACQUIRE_TIMEOUT_TICK = 10000,//10초
        MAX_SPIN_COUNT = 5000,
        WRITE_THREAD_MASK = 0xFFFF'0000,
        READ_COUNT_MASK = 0x0000'FFFF,
        EMPTY_FLAG = 0x0000'0000 // 아무도 소유 X
    };

public:
    void WriteLock();
    void WriteUnlock();
    void ReadLock();
    void ReadUnlock();


private:
    Atomic<uint32> _lockFlag = EMPTY_FLAG;
    uint16 _writeCount = 0;
};

/*----------------
    LockGuards
-----------------*/

class ReadLockGuard
{
public:
	ReadLockGuard(Lock& lock) : _lock(lock) {
        _lock.ReadLock(); 
    }
	~ReadLockGuard() { _lock.ReadUnlock(); }

private:
	Lock& _lock;
};

class WriteLockGuard
{
public:
	WriteLockGuard(Lock& lock) : _lock(lock) { _lock.WriteLock(); }
	~WriteLockGuard() { _lock.WriteUnlock(); }

private:
	Lock& _lock;
};