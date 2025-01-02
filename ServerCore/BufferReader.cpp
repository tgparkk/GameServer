#include "pch.h"
#include "BufferReader.h"

/*----------------
	BufferReader
-----------------*/

BufferReader::BufferReader()
{
}

BufferReader::BufferReader(BYTE* buffer, uint32 size, uint32 pos)
	: _buffer(buffer), _size(size), _pos(pos)
{

}

BufferReader::~BufferReader()
{

}

bool BufferReader::Peek(void* dest, uint32 len)
{
	if (FreeSize() < len) // 읽을 수 사이즈보다 작다면
		return false;

	::memcpy(dest, &_buffer[_pos], len);
	return true;
}

bool BufferReader::Read(void* dest, uint32 len)
{
	if (Peek(dest, len) == false)
		return false;

	_pos += len;
	return true;
}
