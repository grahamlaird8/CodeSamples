/** Header of the ADT ListP, implemented
  * with linked lists. Can be used to sort lists w/ mergesort.
  *@file ListP.h 
  *@author: Graham Laird
  *@date: 3/27/19 */

#include <iostream> 
#include <algorithm>
#include "ListNode.h"


#ifndef _LISTP
#define _LISTP
using namespace std;

class ListP
{
	public:

		/** Constructs a ListP object
		 *@post the ListP object has been constructed  */ 
		ListP();
		
		/** Constructs a ListP object the same as l
		 *@post the ListP object has been constructed to be the same as l
		 *@param l is a ListP object */ 
		ListP(const ListP  *l); // copy constructor
		
		~ListP();	//destructor

		/** Sees whether this list is empty.
		 *@return True if the list is empty; otherwise returns false. */ 
		bool isEmpty() const;
		
		/** Gets the current number of entries in this list.
		 *@return The integer number of entries currently in the list. */ 
		int getSize() const;  

		/** Inserts an entry into this list at a given position.
		  *@pre 0 < pos <= size + 1.
		  *@post x has been put in the list at position pos
		  *@param pos is the position where the new item will be put
		  *@param x is the new item
		  *@return None. */
		void insert(int pos, const ItemType & x); // insert the new item x into the position "pos"
		
		/** Removes the entry at a given position from this list.
		  *@pre 0 < pos <= size
		  *@post the item at position pos has been removed from the list
		  *@param pos is the list position of the entry to remove.
		  *@return None */
		void remove(int pos);// remove the item at the position "pos"
		
		/** prints the list to the screen
		  *@pre none
		  *@post list has been printed to screen
		  *@return None. */ 
		void display(); // for debugging purpose, print out the list
		
		/** Uses merge sort to sort the list
		 *@post the list is sorted */ 
		void sort_mergesort();
		 
		 
	private:
		int size; // how many items in the list
		ListNode * head; //pointer that points to the list
		
		/** Sorts the list smallest to largest
		  *@pre none
		  *@post list has been sorted largest to smallest
		  *@param lhead is the head ptr of the list you want to sort, and lsize is the size of the list you want to sort
		  *@return new head ptr of the list. */ 
		ListNode * mergesort(ListNode *lhead, int lsize);
		
		/** merges two lists together with their components going in order of smallest to largest
		  *@pre none
		  *@post the two lists have been merged into one list
		  *@param lhead1 is the head ptr of one list you want to merge together, and lhead2 is the head ptr of the other list
		  *@return new head ptr of the list. */ 
		ListNode * merge(ListNode *lhead1, ListNode *lhead2);

};

#endif