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
        WRITE_THREAD_MASK = 0xFFFF'0000, // write 를 추출하는
        READ_COUNT_MASK = 0x0000'FFFF,   // read 를 추출하는
        EMPTY_FLAG = 0x0000'0000 // 아무도 소유 X
    };

public:
    void WriteLock(const char* name);
    void WriteUnlock(const char* name);
    void ReadLock(const char* name);
    void ReadUnlock(const char* name);


private:
    std::atomic<uint32> _lockFlag = EMPTY_FLAG;
    uint16 _writeCount = 0;
};

/*----------------
    LockGuards
-----------------*/

class ReadLockGuard
{
public:
    ReadLockGuard(Lock& lock, const char* name)
        : _lock(lock), _name(name) { _lock.ReadLock(name); }
    ~ReadLockGuard() { _lock.ReadUnlock(_name); }

private:
    Lock& _lock;
    const char* _name;
};

class WriteLockGuard
{
public:
    WriteLockGuard(Lock& lock, const char* name)
        : _lock(lock), _name(name) { _lock.WriteLock(name); }
    ~WriteLockGuard() { _lock.WriteUnlock(_name); }

private:
    Lock& _lock;
    const char* _name;
};