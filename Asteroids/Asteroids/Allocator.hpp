#pragma once
#include <cassert>
#include <cstdint>

using u64 = uint64_t;

class Allocator
{
public:
Allocator(size_t size, u64* head)
{
	_head = head;
	_size = size;
	_used_memory = 0;
	_num_allocations = 0;
}

~Allocator()
{
	if (_num_allocations != 0 && _used_memory != 0)
		throw "La memoire est encore utilisee.";

	_head = nullptr;
	_size = 0;
}

	virtual void* allocate(size_t size) = 0;

	virtual void deallocate() = 0;

	void* getStart() const
	{
		return _head;
	}

	size_t getSize() const
	{
		return _size;
	}

	size_t getUsedMemory() const
	{
		return _used_memory;
	}

	size_t getNumAllocations() const
	{
		return _num_allocations;
	}

protected:
	u64 *_head;
	size_t _size;
	size_t _used_memory;
	size_t _num_allocations;
};