/*
 * ListNode.h (+cpp)
 *
 *  Created on: Mar 2, 2017
 *      Author: dev1
 *
 *  Node for simple list managment (List.h)
 *
 */
/**
 * Constructor with templatized argument
 *
 * T dataIn : the date contained in the ListNode
 */
template<typename T>
ListNode<T>::ListNode(T dataIn) {
	data = dataIn;
	nextListNode = 0;
}

/**
 * Returns data stored in node
 *
 */
template<typename T>
T ListNode<T>::getData() {
	return data;
}

/**
 * Returns the nextListNode of the list
 */
template<typename T>
ListNode<T>* ListNode<T>::getNextListNode() {
	return nextListNode;
}

/**
 * Set the nextListNode for the current node
 */
template<typename T>
void ListNode<T>::setNextListNode(ListNode<T>* newNextListNode) {
	nextListNode = newNextListNode;
}
