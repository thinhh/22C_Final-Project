#pragma once
// Specification file for the LinkedList class
// Written By: A. Student
// Changed By:
// IDE: Xcode

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "ListNode.hpp"
using namespace std;

template<class ItemType>
class LinkedList
{
private:
	ListNode<ItemType>* head;
	int count;

public:
	LinkedList();   // Constructor
	~LinkedList() { clear(); }  // Destructor

	// Linked list operations
	void clear();
	bool getEntry(int index, ItemType& returnedEntry);
	int getCount() const { return count; }
	bool insertNode(ItemType);
	bool deleteNode(ItemType);
	bool searchList(ItemType, ItemType&);
	void tranverseForward(void visit(ItemType&)) const;
	void tranverseBack(void visit(ItemType&)) const;
	bool isEmpty() const;

};

//**************************************************
// Constructor
// This function allocates and initializes a sentinel node
//      A sentinel (or dummy) node is an extra node added before the first data record.
//      This convention simplifies and accelerates some list-manipulation algorithms,
//      by making sure that all links can be safely dereferenced and that every list
//      (even one that contains no data elements) always has a "first" node.
//**************************************************
template<class ItemType>
LinkedList<ItemType>::LinkedList()
{
	head = new ListNode<ItemType>();
	head->setNext(head);
	head->setBack(head);
	count = 0;
}

//**************************************************
// The searchList function looks for a target city
// in the sorted linked list: if found, returns true
// and copied the data in that node to the output parameter
//**************************************************
template<class ItemType>
bool LinkedList<ItemType>::searchList(ItemType target, ItemType& dataOut)
{
	bool found = false;
	ListNode<ItemType>* pCur = head->getNext();

	while (pCur != head && pCur->getItem() < target)
		pCur = pCur->getNext();

	if (pCur != head && pCur->getItem() == target)
	{
		dataOut = pCur->getItem();
		found = true;
	}

	return found;
}

//**************************************************
// The insertNode function inserts a new node in a
// sorted linked list
//**************************************************
template<class ItemType>
bool LinkedList<ItemType>::insertNode(ItemType dataIn)
{
	ListNode<ItemType>* newNode;
	ListNode<ItemType>* pPre;
	ListNode<ItemType>* pCur;

	newNode = new ListNode<ItemType>();
	newNode->setCity(dataIn);

	pPre = head;
	pCur = head->getNext();
	while (pCur != head && pCur->getItem() < dataIn)
	{
		pPre = pCur;
		pCur = pCur->getNext();
	}

	newNode->setNext(pCur);
	newNode->setBack(pPre);
	pPre->getNext()->setBack(newNode);
	pPre->setNext(newNode);


	if (newNode->getNext() == head)
	{
		head->setBack(newNode);
	}
	count++;

	return true;
}

//**************************************************
// The deleteNode function searches for a node
// in a sorted linked list; if found, the node is
// deleted from the list and from memory.
//**************************************************
template<class ItemType>
bool LinkedList<ItemType>::deleteNode(ItemType target)
{
	ListNode<ItemType>* pCur;
	ListNode<ItemType>* pPre;
	ListNode<ItemType>* pDel;
	bool deleted = false;

	pPre = head;
	pCur = head->getNext();
	pDel = new ListNode<ItemType>;
	pDel->setCity(target);
	while (pCur != head && pCur->getItem() < target)
	{
		pPre = pCur;
		pCur = pCur->getNext();
	}

	if (pCur != head && pCur->getItem() == target)
	{

		pCur->getBack()->setNext(pCur->getNext());
		pCur->getNext()->setBack(pCur->getBack());

		delete pCur;
		deleted = true;
		count--;
	}
	return deleted;
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************
template<class ItemType>
void LinkedList<ItemType>::clear()
{
	ListNode<ItemType>* pCur;
	ListNode<ItemType>* pNext;

	pCur = head->getNext();
	while (pCur != head)
	{
		pNext = pCur->getNext();
		cout << "DEBUG - Destructor: Now deleting " << endl;
		delete pCur;
		pCur = pNext;
	}
	cout << "DEBUG - Destructor: Now deleting the sentinel node: " << endl;
	delete head;
}

//**************************************************
// tranverseforward is the function to tranverse 
// the whole list from the front of the list.
//*************************************************

template<class ItemType>
void LinkedList<ItemType>::tranverseForward(void visit(ItemType&)) const
{
	ListNode<ItemType>* pWalk;
	pWalk = head->getNext();
	while (pWalk != head)
	{
		ItemType temp = pWalk->getItem();
		visit(temp); // overloaded << operator
		pWalk = pWalk->getNext();
	}
	//	cout << "===== ==================== ====" << endl;
}
template<class ItemType>
bool LinkedList<ItemType>::getEntry(int index, ItemType& returnedEntry)
{
	//if (index < itemCount || index >= itemCount)
	if (index < 0 || index >= count)
		return false;

	BinaryNode<ItemType>* current = head;

	for (int i = 0; i < index; i++)
		current = current->next;

	returnedEntry = current->getItem();
	return true;
}
//**************************************************
// tranverseBack is the fuction to tranverse
// the whole list from the back of the list.
//**************************************************
template<class ItemType>
void LinkedList<ItemType>::tranverseBack(void visit(ItemType&)) const
{
	ListNode<ItemType>* pWalk;
	pWalk = head->getBack();
	while (pWalk != head)
	{

		visit(pWalk->getItem());
		pWalk = pWalk->getBack();
	}
	cout << "===== ==================== ====" << endl;
}

//**************************************************
// isEmpty is used to check if the list is empty
// it returns true if it's an empty list
// false if it's not an empty list
//**************************************************
template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
	return count == 0;
}

#endif


