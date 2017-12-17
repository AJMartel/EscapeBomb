/*
 * ListNode.h (+cpp)
 *
 *  Created on: Mar 2, 2017
 *      Author: dev1
 *
 *  Node for simple list managment (List.h)
 *
 */
#ifndef LIST_NODE_H
#define LIST_NODE_H

template<typename T>
class ListNode {
public:
	ListNode(T);
	T getData();
	ListNode<T>* getNextListNode();
	void setNextListNode(ListNode<T>* newNextListNode);

private:
	T data; //templatized data stored in node
	ListNode* nextListNode; //pointer to the next node in list

};

#include "ListNode.tpp"
#endif
