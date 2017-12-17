/*
 * List.tpp
 *
 *  Created on: Mar 2, 2017
 *      Author: dev1
 *
 *  Simple list managment
 *
 */

/**
 * Default constructor, creates list with start and end as NULL
 */
template<typename T>
List<T>::List() {
	firstListNode = 0;
	lastListNode = 0;
	currentListNode = 0;
}

/**
 * Default destructor
 */
template<typename T>
List<T>::~List() {
	ListNode < T > *currentNode = firstListNode;
	ListNode < T > *tempNode;

	while (!isEmpty()) {
		tempNode = currentNode;
		currentNode = currentNode->getNextListNode();
		delete tempNode;
	}
}

/**
 * To know if the list is empty
 */
template<typename T>
bool List<T>::isEmpty() {
	return (firstListNode == 0);
}

/**
 * Ajout d'un element a la liste
 */
template<typename T>
void List<T>::add(T dataIn) {
	ListNode < T > *listNode = new ListNode<T>(dataIn);
	if (isEmpty()) {
		firstListNode = listNode;
	} else {
		lastListNode->setNextListNode(listNode);
	}
	lastListNode = listNode;
}

/**
 * Ajout d'un element a la liste
 */
template<typename T>
void List<T>::remove(T dataIn) {
	if (!this->isEmpty()) {
		if (firstListNode->getData() == dataIn) {
			firstListNode = firstListNode->getNextListNode();
			delete (currentListNode);
		} else {
			ListNode < T > *prevListNode = firstListNode;
			currentListNode = firstListNode->getNextListNode();
			while (currentListNode != 0) {
				if( currentListNode->getData() == dataIn) {
					prevListNode->setNextListNode(currentListNode->getNextListNode());
					currentListNode=0;
				} else {
					prevListNode=currentListNode;
					currentListNode=currentListNode->getNextListNode();
				}
			}
		}
		currentListNode = firstListNode->getNextListNode();
		while (this->hasNext()) {

		}
	}
}

/**
 * To use before iteration of the list
 */
template<typename T>
void List<T>::resetIterator() {
	currentListNode = firstListNode;
}

/**
 * Get the current node et skip to the next one
 */
template<typename T>
T List<T>::next() {
	ListNode < T > *currentNode = currentListNode;
	currentListNode = currentListNode->getNextListNode();
	return currentNode->getData();
}

/**
 * In the current iteration, is this the last element
 */
template<typename T>
bool List<T>::hasNext() {
	return (currentListNode != 0);
}
