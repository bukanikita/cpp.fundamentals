#include "12_task_4_stack.h"

Stack::Stack(int n)    // create an empty stack
{
	top = 0;
	if (n > 0)
	{
		pitems = new Item [n];
		size = n;
	}
	else
	{
		size = 0;
		pitems = nullptr;
	}
}

Stack::Stack(const Stack & st)   
{
	top = st.top;
	size = st.size;
	if (size > 0)
	{
		pitems = new Item [size];
	}
	else
	{
		size = 0;
		pitems = nullptr;
	}
	for (int i = 0; i < size; ++i)
	{
		pitems[i] = st.pitems[i];
	}
}

Stack::~Stack()
{
	delete [] pitems;
}

Stack & Stack::operator=(const Stack & st)
{
	if (this == &st)
	{
		return *this;
	}
	top = st.top;
	size = st.size;
	delete [] pitems;
	if (size > 0)
	{
		pitems = new Item [size];
	}
	else
	{
		size = 0;
		pitems = nullptr;
	}
	for (int i = 0; i < size; ++i)
	{
		pitems[i] = st.pitems[i];
	}
	return *this;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == size;
}

bool Stack::push(const Item & item) 
{
	if (top < size)
	{
		pitems[top++] = item;
		return true;
	}
	else
		return false;
}

bool Stack::pop(Item & item)
{
	if (top > 0)
	{
		item = pitems[--top];
		return true;
	}
	else
		return false; 
}