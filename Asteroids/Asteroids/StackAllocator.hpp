#pragma once

#include "Allocator.hpp"
class StackAllocator : public Allocator
{
public:
	StackAllocator(size_t size, char* head);
	~StackAllocator();
	virtual void* allocate(size_t size) override;
	virtual void deallocate() override;

private:
	StackAllocator(const StackAllocator&); //On empêche les instructions de copie
	StackAllocator& operator=(const StackAllocator&);
	void clear();
	u64* _current_pos;
};
