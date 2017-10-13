#pragma once
#include <cassert>

class Allocator {

protected:
	void *head;
	void *current_position;
	size_t size;
	size_t used_memory;
	size_t nb_allocations;

public:
	Allocator(const Allocator &alloc);
	Allocator& operator=(const Allocator &alloc);

	Allocator(size_t size, void *head)
	{
		assert(size > 0);
		this->head = head;
		this->size = size;
		this->current_position = this->head;
		used_memory = 0;
		nb_allocations = 0;
	}

	~Allocator() 
	{
		assert(nb_allocations == 0 && used_memory == 0);
		head = nullptr;
		size = 0;
	}

	virtual void* allocate(size_t size) = 0;
	virtual void deallocate(void *ptr) = 0;

	void* getHead() const
	{
		return head;
	}

	size_t getSize() const
	{
		return size;
	}

	size_t getUsedMemory() const
	{
		return used_memory;
	}

	size_t getNbAllocations() const
	{
		return nb_allocations;
	}
};