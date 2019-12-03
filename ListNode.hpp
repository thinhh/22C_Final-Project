#pragma once
#ifndef LIST_NODE_H
#define LIST_NODE_H
#include <cstdlib>
template<class ItemType>
class ListNode
{
private:
	ItemType item;
	ListNode<ItemType>* next;
	ListNode<ItemType>* back;
public:
	//Constructor
	ListNode() {};
	ListNode(ItemType v, ListNode<ItemType>* n, ListNode<ItemType>* b) { item = v; next = n; back = b; }

	//Setter
	void setNext(ListNode<ItemType>* n) { next = n; }
	void setBack(ListNode<ItemType>* b) { back = b; }
	void setCity(ItemType c) {item = c; }

	//Getter
	ListNode<ItemType>* getNext()const { return next; }
	ListNode<ItemType>* getBack()const { return back; }
	ItemType getItem() const { return item; }
	
};
#endif