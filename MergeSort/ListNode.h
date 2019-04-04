/** Header of the ListNode Class, used to create linked lists
  *@file ListNode.h 
  *@author: Graham Laird
  *@date: 3/27/19 */
#ifndef _LISTNODE
#define _LISTNODE

typedef int ItemType;

class ListNode
{
    public:
		/** Gets what the ListNode points to
		 *@return what ListNode points to  */
		ItemType getItem();
		
		/** Gets what item the ListNode holds
		 *@return ListNode's item */
        ListNode * getNext();
		
		/** Default Constructor, Constructs an empty ListNode object
		 *@post the empty ListNode object has been constructed */ 
        ListNode();
		
		/** Constructs a ListNode object holding item x
		 *@post the ListNode object has been constructed with item = x
		 *@param x is an item */ 
        ListNode(const ItemType & x);
		
		/** Constructs a ListNode object holding item x pointing to nNode
		 *@post the ListNode object has been constructed with item = x and points to nNode
		 *@param x is an item
		 *@param nNode is a ListNode */ 
        ListNode(const ItemType & x, ListNode * nNode);
		
		/** Sets what the ListNode points to
		 *@post ListNode points to nNode
		 *@param nNode is a ListNode */
        void setNext(ListNode * nNode);
		
		/** Sets the item of the ListNode to x
		 *@post ListNode's item has been set to x
		 *@param x is an item */
		void setItem(const ItemType & x);
        ~ListNode();

    private :
        ItemType item; // A data item
        ListNode * next; // Pointer to next node
}; // end Node

#endif