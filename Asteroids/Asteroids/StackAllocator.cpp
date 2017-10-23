#include "StackAllocator.hpp"

StackAllocator::StackAllocator(size_t size, void* start)
	: Allocator(size, start), _current_pos(start)
{
	assert(size > 0);
}

StackAllocator::~StackAllocator()
{
	_current_pos = nullptr;
}
void* StackAllocator::allocate(size_t size, u8 alignment)
{
	assert(size != 0);
	u8 adjustment = pointer_math::alignForwardAdjustmentWithHeader(_current_pos, alignment, sizeof(AllocationHeader));
	if (_used_memory + adjustment + size > _size)
		return nullptr;
	void* aligned_address = pointer_math::add(_current_pos, adjustment);
	//Add Allocation Header
	adjustment = (u8*)(pointer_math::subtract(aligned_address, sizeof(adjustment)));
	adjustment->adjustment = adjustment;

	_current_pos = pointer_math::add(aligned_address, size);
	_used_memory += size + adjustment;
	_num_allocations++;
	return aligned_address;
}
void StackAllocator::deallocate(void* p)
{
	//Access the AllocationHeader in the bytes before p
	adjustment = (adjustment)(pointer_math::subtract(p, sizeof(adjustment)));
	_used_memory -= (uptr)_current_pos - (uptr)p + header->adjustment;
	_current_pos = pointer_math::subtract(p, adjustment->adjustment);
	_num_allocations--;
}