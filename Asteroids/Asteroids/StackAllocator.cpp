#include "StackAllocator.hpp"

StackAllocator::StackAllocator(size_t size, char* head)
	: Allocator(size, head), _current_pos(_head)
{
	assert(size > 0);
}

StackAllocator::~StackAllocator()
{
	_current_pos = nullptr;
}

void* StackAllocator::allocate(size_t size)
{
	if (size != 0)
		throw "La taille de la memoire a allouer doit etre positive.";

	if (size > (_head + size) - _current_pos)
		throw "Taille de la memoire trop petite pour l'allocation.";


	_current_pos += size;
	_used_memory += size;
	_num_allocations++;

	return (void*) _current_pos;
}

void StackAllocator::deallocate(void* p, size_t size)
{
	_current_pos -= size;
}

void StackAllocator::clear()
{
	_current_pos = _head;
	_used_memory = 0;
	_num_allocations = 0;
}