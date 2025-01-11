#pragma once

class SendBufferChunk;

/*----------------
	SendBuffer
-----------------*/

class SendBuffer
{
public:
	SendBuffer(std::shared_ptr<SendBufferChunk> owner, BYTE* buffer, uint32 allocSize);
	~SendBuffer();

	BYTE* Buffer() { return _buffer; }
	uint32		AllocSize() { return _allocSize; }
	uint32		WriteSize() { return _writeSize; }
	void		Close(uint32 writeSize);

private:
	BYTE* _buffer;
	uint32				_allocSize = 0;
	uint32				_writeSize = 0;
	std::shared_ptr<SendBufferChunk>	_owner;
};

/*--------------------
	SendBufferChunk
--------------------*/

class SendBufferChunk : public enable_shared_from_this<SendBufferChunk> // 자기 자신에 대한 스마트 포인터가 필요할수 있으므로
{
	enum
	{
		SEND_BUFFER_CHUNK_SIZE = 6000
	};

public:
	SendBufferChunk();
	~SendBufferChunk();

	void				Reset();
	std::shared_ptr<SendBuffer>		Open(uint32 allocSize);
	void				Close(uint32 writeSize);

	bool				IsOpen() { return _open; }
	BYTE* Buffer() { return &_buffer[_usedSize]; }
	uint32				FreeSize() { return static_cast<uint32>(_buffer.size()) - _usedSize; }

private:
	Array<BYTE, SEND_BUFFER_CHUNK_SIZE>		_buffer = {};
	bool									_open = false;
	uint32									_usedSize = 0;
};

/*---------------------
	SendBufferManager
----------------------*/

class SendBufferManager
{
public:
	std::shared_ptr<SendBuffer>		Open(uint32 size);

private:
	std::shared_ptr<SendBufferChunk>	Pop();
	void				Push(std::shared_ptr<SendBufferChunk> buffer);

	static void			PushGlobal(SendBufferChunk* buffer);

private:
	USE_LOCK;
	std::vector<std::shared_ptr<SendBufferChunk>> _sendBufferChunks;
};

