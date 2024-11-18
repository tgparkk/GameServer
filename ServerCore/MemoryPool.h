#pragma once

/*-----------------
	MemoryHeader
------------------*/

struct MemoryHeader
{
	// [MemoryHeader][Data]
	MemoryHeader(int32 size) : allocSize(size) { }

	static void* AttachHeader(MemoryHeader* header, int32 size)
	{
		new(header)MemoryHeader(size); // placement new

		// (++header) 는 [MemoryHeader][Data] 에서 한칸 움직여서(포인턴 연산)  [Data]
		return reinterpret_cast<void*>(++header); 
	}

	static MemoryHeader* DetachHeader(void* ptr)
	{
		// reinterpret_cast<MemoryHeader*>(ptr) 에서 1 을 뺀거는
		// [Data] 에서 한칸 뒤인 [MemoryHeader] 로 갑니다.
		MemoryHeader* header = reinterpret_cast<MemoryHeader*>(ptr) - 1;
		return header;
	}

	int32 allocSize;
	// TODO : 필요한 추가 정보
};

/*-----------------
	MemoryPool
------------------*/

class MemoryPool
{
public:
	MemoryPool(int32 allocSize);
	~MemoryPool();

	void			Push(MemoryHeader* ptr);
	MemoryHeader*	Pop();

private:
	int32 _allocSize = 0;
	atomic<int32> _allocCount = 0;

	USE_LOCK;
	queue<MemoryHeader*> _queue;
};

