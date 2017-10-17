#include "Allocator.hpp"
#include <cassert>

Allocator::Allocator(size_t size)
{
	assert(size > 0);
	this->head = new void*[size];
	this->size = size;
	this->current_position_ptr = this->head;
	current_position = 0;
	used_memory = 0;
}

Allocator::~Allocator()
{
	assert(used_memory == 0);
	head = nullptr;
	size = 0;
}

void* Allocator::getHead() const
{
	return head;
}

size_t Allocator::getSize() const
{
	return size;
}

size_t Allocator::getUsedMemory() const
{
	return used_memory;
}

void Allocator::deallocate(void *ptr)
{
}

void* Allocator::operator[](const int i)
{
	return head[i];
}

const void* Allocator::operator[](const int i) const
{
	return head[i];
}