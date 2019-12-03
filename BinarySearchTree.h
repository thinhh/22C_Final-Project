// Binary Search Tree ADT
// Created by A. Student
// Modified by:  <=============================== ADD YOUR NAME HERE
 
#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryTree.h"

template<class ItemType>
class BinarySearchTree : public BinaryTree<ItemType>
{
private:
	// internal insert node: insert newNode in nodePtr subtree
	BinaryNode<ItemType>* _insert(BinaryNode<ItemType>* nodePtr, BinaryNode<ItemType>* newNode);

	// internal remove node: locate and delete target node under nodePtr subtree
	BinaryNode<ItemType>* _remove(BinaryNode<ItemType>* nodePtr, const ItemType target, bool& success);

	// delete target node from tree, called by internal remove node
	BinaryNode<ItemType>* deleteNode(BinaryNode<ItemType>* targetNodePtr);

	// remove the leftmost node in the left subtree of nodePtr
	BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* nodePtr, ItemType& successor);

	// search for target node
	BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, const ItemType& target) const;

	BinaryNode<ItemType>* getSmallestNode(BinaryNode<ItemType>* treePtr)const;
	BinaryNode<ItemType>* getLargestNode(BinaryNode<ItemType>* treePtr)const;
public:
	// insert a node at the correct location
	bool insert(const ItemType& newEntry);
	// remove a node if found
	bool remove(const ItemType& anEntry);
	// find a target node
	bool getEntry(const ItemType& target, ItemType& returnedItem) const;
	// Find the smallest node
	bool getSmallest( ItemType& returnItem) const;
	bool getLargest(ItemType& returnItem) const;
};


///////////////////////// public function definitions ///////////////////////////
//Inserting items within a tree
template<class ItemType>
bool BinarySearchTree<ItemType>::insert(const ItemType & newEntry)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
	this->rootPtr = _insert(this->rootPtr, newNodePtr);
	return true;
}  

//Removing items within a tree
template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType & target)
{
	bool isSuccessful = false;
	this->rootPtr = _remove(this->rootPtr, target, isSuccessful);
	return isSuccessful; 
}  

//Finding entries within a tree
template<class ItemType>
bool BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry, ItemType & returnedItem) const
{
	BinaryNode<ItemType>* target = findNode(this->rootPtr, anEntry);
	if (target != NULL)
	{
		returnedItem = target->getItem();
		return true;
	}
    return false;
}  
template<class ItemType>
bool BinarySearchTree<ItemType>::getSmallest( ItemType& returnedItem)const
{
	BinaryNode<ItemType>* smallest = getSmallestNode(this->rootPtr);
	if (smallest != NULL)
	{
		returnedItem = smallest->getItem();
		return true;
	}
	return false; 
}
template<class ItemType>
bool BinarySearchTree<ItemType>::getLargest(ItemType& returnedItem)const
{
	BinaryNode<ItemType>* largest = getLargestNode(this->rootPtr);
	if (largest != NULL)
	{
		returnedItem = largest->getItem();
		return true;
	}
	return false;
}

//////////////////////////// private functions ////////////////////////////////////////////

//Implementation of the insert operation
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_insert(BinaryNode<ItemType>* nodePtr,
                                                          BinaryNode<ItemType>* newNodePtr)
{
	if (nodePtr == NULL) 
	{
		nodePtr = newNodePtr;
		this->count++;
		return nodePtr;
	}
	else
	{
		if (nodePtr->getItem() < newNodePtr->getItem())
			nodePtr->setRightPtr(_insert(nodePtr->getRightPtr(), newNodePtr));
		else
			nodePtr->setLeftPtr(_insert(nodePtr->getLeftPtr(), newNodePtr));
	}
}

//Implementation for the search operation
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* nodePtr,
                                                           const ItemType & target) const
{
	bool found =false ;
	BinaryNode<ItemType>* pWalk = nodePtr;
	//Check if the tree is empty
	if (pWalk == NULL)
	{
		cout << "The tree is empty. Please insert nodes\n"; 
	}
	while (pWalk != NULL && found == false)
	{
		if (pWalk->getItem() > target)
		{
			pWalk = pWalk->getLeftPtr();
		}
		else if (pWalk->getItem() < target)
		{
			pWalk = pWalk->getRightPtr();
		}
		else
		{
			found = true;
		}
	}
	return pWalk;
}
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::getSmallestNode(BinaryNode<ItemType>* nodePtr) const 
{
	if (nodePtr->getLeftPtr() != NULL)
	{
		getSmallestNode(nodePtr->getLeftPtr());
	}
	else
	{
		return nodePtr;
	}
}
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::getLargestNode(BinaryNode<ItemType>* nodePtr) const
{
	if (nodePtr->getRightPtr() != NULL)
	{
		getLargestNode(nodePtr->getRightPtr());
	}
	else
	{
		return nodePtr;
	}
}


////////////////////////////////////////////////////////////////////////
// The follwoing functions will be needed for the team project
//Implementation of the remove operation
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_remove(BinaryNode<ItemType>* nodePtr,
                                                          const ItemType target,
                                                          bool & success)

{
	if (nodePtr == 0)                   
	{
		success = false;
		return 0;
	}
	if (nodePtr->getItem() > target)		 
		nodePtr->setLeftPtr(_remove(nodePtr->getLeftPtr(), target, success));
	else if (nodePtr->getItem() < target)	 
		nodePtr->setRightPtr(_remove(nodePtr->getRightPtr(), target, success));
	else		
	{
		nodePtr = deleteNode(nodePtr);
		success = true;
	}      
	return nodePtr;   
}  
//Implementation of the delete operation
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::deleteNode(BinaryNode<ItemType>* nodePtr)
{
	if (nodePtr->isLeaf())				
	{
		delete nodePtr;
		nodePtr = 0;
		return nodePtr;
	}
	else if (nodePtr->getLeftPtr() == 0)  
	{
		BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getRightPtr();
		delete nodePtr;
		nodePtr = 0;
		return nodeToConnectPtr;
	}
	else if (nodePtr->getRightPtr() == 0) 
	{
		BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getLeftPtr();
		delete nodePtr;
		nodePtr = 0;
		return nodeToConnectPtr;      
	}
	else                                  
	{
		ItemType newNodeValue;
		nodePtr->setRightPtr(removeLeftmostNode(nodePtr->getRightPtr(), newNodeValue));
		nodePtr->setItem(newNodeValue);
		return nodePtr;
	}  
}  
//Implementation to remove the left leaf
template<class ItemType> 
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* nodePtr,
                                                                     ItemType & successor)
{
	if (nodePtr->getLeftPtr() == 0)
	{
		successor = nodePtr->getItem();
		return deleteNode(nodePtr);
	}
	else 
	{
		nodePtr->setLeftPtr(removeLeftmostNode(nodePtr->getLeftPtr(), successor));
		return nodePtr;
	}       
}



#endif
