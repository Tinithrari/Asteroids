#include "Allocator.h"

 void* Allocator::allocate(size_t  size)
{
	 assert(size > 0);

	 if (used_memory + size > this->size)
		 return nullptr;

	 current_position = (void*)current_position + size;
	 used_memory += size;
	 nb_allocations++;

	 return current_position;
}

 void Allocator::deallocate(void *ptr)
 {
	 //TODO
 }