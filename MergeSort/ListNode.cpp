/** Implementation of the ListNode Class, used to create linked lists
  *@file ListNode.cpp 
  *@author: Graham Laird
  *@date: 3/27/19 */
#include "ListNode.h"
#include <cstddef>

using namespace std;

/** Default Constructor, Constructs an empty ListNode object
  *@post the empty ListNode object has been constructed */ 
ListNode::ListNode() : next(NULL)
{
}

/** Constructs a ListNode object holding item x
  *@post the ListNode object has been constructed with item = x
  *@param x is an item */ 
ListNode::ListNode(const ItemType & x) : item(x), next(NULL)
{
}

/** Constructs a ListNode object holding item x pointing to nNode
  *@post the ListNode object has been constructed with item = x and points to nNode
  *@param x is an item
  *@param nNode is a ListNode */ 
ListNode::ListNode(const ItemType & x, ListNode * nNode) : item(x), next(nNode)
{
}

/** Sets the item of the ListNode to x
 *@post ListNode's item has been set to x
 *@param x is an item */
void ListNode::setItem(const ItemType & x)
{
	item = x;
}

/** Sets what the ListNode points to
 *@post ListNode points to nNode
 *@param nNode is a ListNode */
void ListNode::setNext(ListNode * nNode)
{
	next = nNode;
}

/** Gets what item the ListNode holds
 *@return ListNode's item */
ItemType ListNode::getItem()
{
	return item;
}

/** Gets what the ListNode points to
 *@return what ListNode points to  */
ListNode *ListNode::getNext()
{
	return next;
}