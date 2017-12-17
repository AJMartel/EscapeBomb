/*
 * List.h (+cpp)
 *
 *  Created on: Mar 2, 2017
 *      Author: dev1
 *
 *  Simple list managment
 *
 */

#ifndef LIST_H
#define LIST_H

#include "ListNode.h"

template<typename T>
class List {
public:
	List();
	~List();
	void add(T);
	void remove(T);
	bool isEmpty();

	void resetIterator();
	T next();
	bool hasNext();

private:
	ListNode<T> *firstListNode; //stores the pointer of first object in the linked list
	ListNode<T> *lastListNode; //stored the pointer of the last object in the linked list
	ListNode<T> *currentListNode; //stored the pointer of the current object, use with next
};

#include "List.tpp"
#endif
