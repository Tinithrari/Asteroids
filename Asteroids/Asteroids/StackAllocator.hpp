#pragma once

#include "Allocator.hpp"
class StackAllocator : public Allocator
{
public:
	StackAllocator(size_t size, void* start);
	~StackAllocator();
	void* allocate(size_t size, u8 alignment) override;
	void deallocate(void* p) override;

private:
	StackAllocator(const StackAllocator&); //On empêche les instructions de copie
	StackAllocator& operator=(const StackAllocator&);
	u8 adjustment;
	void* _current_pos;
};
