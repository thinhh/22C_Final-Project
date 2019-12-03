	// Binary tree abstract base class
// Created by A. Student
// Modified by: <=============================== ADD YOUR NAME HERE
 
#ifndef _BINARY_TREE
#define _BINARY_TREE

#include "BinaryNode.h"
#include "Queue.h"
#include "Stack.h"

template<class ItemType>
class BinaryTree
{
protected:
	BinaryNode<ItemType>* rootPtr;		// ptr to root node
	int count;							// number of nodes in tree

public:
	// "admin" functions
 	BinaryTree() {rootPtr = 0; count = 0;}
	BinaryTree(const BinaryTree<ItemType> & tree){ }
	virtual ~BinaryTree() { _destroyTree(rootPtr); }
   
	// common functions for all binary trees
 	bool isEmpty() const	{return count == 0;}
	int size() const	    {return count;}
	void clear()			{destroyTree(rootPtr); rootPtr = 0; count = 0;}
	void preOrder(void visit(ItemType &)) const {_preorder(visit, rootPtr);}
	void inOrder(void visit(ItemType &)) const  {_inorder(visit, rootPtr);}
	void postOrder(void visit(ItemType &)) const{_postorder(visit, rootPtr);}
	void breadthFirst(void visit(ItemType&)) const {_breadthFirst(visit, rootPtr); }
	//void iterativeInorder(void visit(ItemType&)) const { _iterativeInorder(visit, rootPtr); }
	//void iterativePreorder(void visit(ItemType&)) const { _iterativePreorder(visit, rootPtr); }
	//void iterativePostorder(void visit(ItemType&)) const { _iterativePostorder(visit, rootPtr); }
	//void displayIndentedList(void visit(ItemType&)) const { _displayIndentedList(visit, rootPtr, 0); }
	// abstract functions to be implemented by derived class
	virtual bool insert(const ItemType & newData) = 0; 
	virtual bool remove(const ItemType & data) = 0; 
	virtual bool getEntry(const ItemType & anEntry, ItemType & returnedItem) const = 0;

private:   
	// delete all nodes from the tree
	void _destroyTree(BinaryNode<ItemType>* nodePtr);

	// internal traverse
	void _preorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
	void _inorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
	void _postorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
	void _breadthFirst(void visit(ItemType&), BinaryNode<ItemType>* nodePtr) const;
	void _iterativeInorder(void visit(ItemType&), BinaryNode<ItemType>* nodePtr) const;
	void _iterativePreorder(void visit(ItemType&), BinaryNode<ItemType>* nodePtr) const;
	void _iterativePostorder(void visit(ItemType&), BinaryNode<ItemType>* nodePtr) const;
	void _displayIndentedList(void visit(ItemType&), BinaryNode<ItemType>* nodePtr, int level) const;
}; 

//Destroy the entire tree
template<class ItemType>
void BinaryTree<ItemType>::_destroyTree(BinaryNode<ItemType>* nodePtr)
{
	if (nodePtr != 0)
	{
		_destroyTree(nodePtr->getLeftPtr());
		_destroyTree(nodePtr->getRightPtr());
		cout << "NOW DELETING: \n" << nodePtr->getItem() << endl;
		delete nodePtr;
	}
}  
template<class ItemType>
void BinaryTree<ItemType>::_breadthFirst(void visit(ItemType &),BinaryNode<ItemType>* nodePtr) const
{
	Queue<BinaryNode<ItemType>*>* q= new Queue<BinaryNode<ItemType>*>;
	BinaryNode<ItemType>* curr;
	ItemType item;
	if(nodePtr== NULL)
	{
		return;
	}
	q->enqueue(nodePtr);
	while (q->isEmpty()!= true)
	{
		q->dequeue(curr);
		item = curr->getItem();
		visit(item);
		if (curr->getLeftPtr()!= NULL)
		{
			q->enqueue(curr->getLeftPtr());
		}
		if (curr->getRightPtr() != NULL)
		{
			q->enqueue(curr->getRightPtr());
		}
	}
}
template<class ItemType>
void BinaryTree<ItemType>::_iterativeInorder(void visit(ItemType&), BinaryNode<ItemType>* nodePtr) const
{
	Stack<BinaryNode<ItemType>*>* s = new Stack<BinaryNode<ItemType>*>;
	BinaryNode<ItemType>* curr= nodePtr;
	ItemType item;
	while (curr != NULL || s->isEmpty() == false)
	{
		while (curr != NULL)
		{
			s->push(curr);
			curr=curr->getLeftPtr();
		}
		s->pop(curr);
		item = curr->getItem();
		visit(item);
		curr= curr->getRightPtr();
	}
}


template<class ItemType>
void BinaryTree<ItemType>::_iterativePreorder(void visit(ItemType&), BinaryNode<ItemType>* nodePtr) const
{
	Stack<BinaryNode<ItemType>*>* s = new Stack<BinaryNode<ItemType>*>;
	BinaryNode<ItemType>* curr;
	ItemType item;
	if (nodePtr == NULL)
	{
		return;
	}
	s->push(nodePtr);
	while (s->isEmpty() != true)
	{
		s->pop(curr);
		item = curr->getItem();
		visit(item);
		if (curr->getRightPtr() !=NULL)
		{
			s->push(curr->getRightPtr());
		}
		if (curr->getLeftPtr() != NULL) 
		{
			s->push(curr->getLeftPtr());
		}
	}
	
}
template<class ItemType>
void BinaryTree<ItemType>::_iterativePostorder(void visit(ItemType&), BinaryNode<ItemType>* nodePtr) const
{
	Stack<BinaryNode<ItemType>*>* s = new Stack<BinaryNode<ItemType>*>;
	Stack<BinaryNode<ItemType>*>* out = new Stack<BinaryNode<ItemType>*>;
	if (nodePtr == NULL)
	{
		return;
	}
	BinaryNode<ItemType>* curr;
	ItemType item;
	if (nodePtr == NULL)
	{
		return;
	}
	s->push(nodePtr);
	while (s->isEmpty() != true)
	{
		s->pop(curr);
		out->push(curr);
		if (curr->getLeftPtr() != NULL)
		{
			s->push(curr->getLeftPtr());
		}
		if (curr->getRightPtr() != NULL)
		{
			s->push(curr->getRightPtr());
		}
	}
	while (!out->isEmpty())
	{
		out->pop(curr);
		item = curr->getItem();
		visit(item);
	}
}
template<class ItemType>
void BinaryTree<ItemType>::_displayIndentedList(void visit(ItemType&), BinaryNode<ItemType>* nodePtr, int level) const
{
	
	if (nodePtr != 0)
	{
		ItemType item= nodePtr->getItem();
		for (int i = level; i > 0; i--)
			cout << "\t";
		cout << "Level " << level + 1 << ": ";
		visit(item);
		_displayIndentedList(visit, nodePtr->getRightPtr(), level + 1);
		_displayIndentedList(visit, nodePtr->getLeftPtr(), level + 1);
	}
}
//Preorder Traversal
template<class ItemType>
void BinaryTree<ItemType>::_preorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
	if (nodePtr != 0)
	{
		ItemType item = nodePtr->getItem();
		visit(item);
		_preorder(visit, nodePtr->getLeftPtr());
		_preorder(visit, nodePtr->getRightPtr());
	} 
}  

//Inorder Traversal
template<class ItemType>
void BinaryTree<ItemType>::_inorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
	if (nodePtr != 0)
	{
		_inorder(visit, nodePtr->getLeftPtr());
		ItemType item = nodePtr->getItem();
		visit(item);
		_inorder(visit, nodePtr->getRightPtr());
	}
}  

//Postorder Traversal
template<class ItemType>
void BinaryTree<ItemType>::_postorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
	if (nodePtr != 0)
	{
		
		_postorder(visit, nodePtr->getLeftPtr());
		_postorder(visit, nodePtr->getRightPtr());
		ItemType item = nodePtr->getItem();
		visit(item);
	}
}  

#endif

