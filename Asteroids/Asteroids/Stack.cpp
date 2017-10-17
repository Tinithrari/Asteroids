#include "Stack.hpp"

Stack::Stack(size_t max_size)
{
	this->max_size = max_size;
	this->head = new size_t[max_size];
	this->current_ptr = this->head;
}

Stack::~Stack()
{
	delete[] head;
}

size_t Stack::operator[](const int i)
{
	return head[i];
}

const size_t Stack::operator[](const int i) const
{
	return head[i];
}

void Stack::push(size_t number)
{
	if((size_t) (current_ptr - head) < max_size)
		head[*current_ptr++] = number;
}

size_t Stack::pop()
{
	if(current_ptr != head)
		return *(--current_ptr);
	return *current_ptr;
}