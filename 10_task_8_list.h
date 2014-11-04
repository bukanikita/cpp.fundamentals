#ifndef _10_TASK_8_LIST_H_
#define _10_TASK_8_LIST_H_

#include "10_task_8_includes.h"

/* 
 * Description: List Template
 */
template <typename T>
class List
{
private:
	/* 
	 * Description: Class for every element of List
	 */
	class Node
	{
	public:
		T item; // information about every element in list
		Node *next; // pointer to the next element
		Node (const T& _item) : item(_item), next(nullptr) {}; // Constructor: every new element get value and show that it's last element
	};

	typedef void (*pf_list)(T &); // pointer to the function that make operation with every element in list

	Node *head; // head of elements
	int cur_size; // current size of list
	int max_size; // max size of list (argument of constructor

	Node *get_last() const; // function for getting last element of list
public:
	List(int _max_size = 10) : head(nullptr), cur_size(0), max_size(_max_size) {}; // Default constructor with max size of list 10
	bool push_back(const T &); // putting element to the end of list 
	bool is_empty() const { return cur_size == 0; }; 
	bool is_full() const { return cur_size == max_size; };
	void visit(void (*pf_list)(T &)); // function, which gets pointer to function, witch will process every element of list
	~List(); 
};

template <typename T>
typename List<T>::Node *List<T>::get_last() const
{
	Node *cur = head;
	while (cur->next)
	{
		cur = cur->next;
	}
	return cur; // last element of list
}

template <typename T>
bool List<T>::push_back(const T &elem)
{
	if (is_full())
	{
		cout << "List is full. Impossible to add element.\n";
		return false;
	}
	++cur_size;
	Node *node = new Node(elem);
	if (!head) // if the first element added
	{
		head = node;
	}
	else
	{
		Node *last = get_last();
		last->next = node;
		last = node;
	}
	return true;
}

template <typename T>
void List<T>::visit(pf_list pf)
{
	Node *cur = head;
	while (cur)
	{
		(*pf)(cur->item);
		cur = cur->next;
	}
}

template <typename T>
List<T>::~List()
{
	Node *temp;
	while (head != nullptr) // deleting all elements
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

#endif
