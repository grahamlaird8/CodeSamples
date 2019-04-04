/** Implementation of the ADT ListP, implemented
  * with linked lists. Can be used to sort lists w/ mergesort.
  *@file ListP.cpp 
  *@author: Graham Laird
  *@date: 3/27/19 */
#include "ListP.h"
#include <iostream>
#include <cstddef>
using namespace std;

/** Constructs a ListP object the same as l
  *@post the ListP object has been constructed to be the same as l
  *@param l is a ListP object */ 
ListP::ListP(const ListP * l)
{
	if(l -> isEmpty())
	{
		head = NULL;
	}
	else
	{
		head = new ListNode(l -> head -> getItem(), NULL);
		ListNode *curr = l -> head;
		ListNode *temp = head;
		while(curr -> getNext() != NULL)
		{
			curr = curr -> getNext();
			temp -> setNext(new ListNode(curr -> getItem(), NULL));
			temp = temp -> getNext();
		}
	}
	size = l -> getSize();
}

/** Uses merge sort to sort the list
  *@post the list is sorted */ 
void ListP::sort_mergesort()
{
	head = mergesort(head, size);
}

/** Constructs a ListP object
  *@post the ListP object has been constructed  */ 
ListP::ListP()
{
	head = NULL;
	size = 0;
}

/** Sees whether this list is empty.
  *@return True if the list is empty; otherwise returns false. */ 
bool ListP::isEmpty() const
{
	return(size == 0);
}

/** Gets the current number of entries in this list.
  *@return The integer number of entries currently in the list. */ 
int ListP::getSize() const
{
	return size;
}

/** Inserts an entry into this list at a given position.
  *@pre 0 < pos <= size + 1.
  *@post x has been put in the list at position pos
  *@param pos is the position where the new item will be put
  *@param x is the new item
  *@return None. */ 
void ListP::insert(int pos, const ItemType & x) // insert the new item x into the position "pos", with 1 being the first position
{
	ListNode *before = new ListNode();
	ListNode *curr = new ListNode();
	ListNode *temp = new ListNode();
	bool canInsert = (pos >= 1) && (pos <= size + 1);
	
	temp -> setItem(x);
	if(canInsert)
	{
		if(size == 0)
		{
			head = new ListNode(x);
		}
		else if(pos == 1)
		{
			temp -> setNext(head);
			head = temp;
		}
		else if (pos == (size + 1))
		{
			ListNode *curr = new ListNode();
			curr = head;
			while (curr -> getNext() != NULL)
			{
				curr = curr -> getNext();
			}
			curr -> setNext(temp);
		}
		else
		{	
			curr = head;
			for(int i = 1; i < (pos); i++)
				{
					before = curr;
					curr = curr -> getNext();
				}
			before -> setNext(temp);
			temp -> setNext(curr);
		}
	}
	else
	{
		cout << "Position unavailable to insert" << endl;
	}
	size++;
}

/** Removes the entry at a given position from this list.
  *@pre 0 < pos <= size
  *@post the item at position pos has been removed from the list
  *@param pos is the list position of the entry to remove.
  *@return None */
void ListP::remove(int pos)// remove the item at the position "pos"
{
	ListNode *curr = new ListNode();
	ListNode *before = new ListNode();
	curr = head;
	size--;
	
    if(pos == 1)
	{
		head = head -> getNext();
	}
	else
	{
		for(int i = 1; i < pos; i++)
		{
			before = curr;
			curr = curr -> getNext();
		}
		
		before -> setNext(curr -> getNext());
	}
	
}

/** prints the list to the screen
  *@pre none
  *@post list has been printed to screen
  *@return None. */ 
void ListP::display()
{
	ListNode *temp = new ListNode();
	temp = head;
	while ((temp -> getNext()) != NULL)
	{
		cout << temp -> getItem() << ", ";
		temp = temp -> getNext();
	}
		cout << temp -> getItem() << endl;	
}

/** Sorts the list smallest to largest
  *@pre none
  *@post list has been sorted largest to smallest
  *@param lhead is the head ptr of the list you want to sort, and lsize is the size of the list you want to sort
  *@return new head ptr of the list. */ 
ListNode* ListP::mergesort(ListNode *lhead, int lsize)
{
	int size1, size2, count;
	ListNode* lhead1;
	ListNode* lhead2;
	ListNode* temp;
	if(lsize <= 1)
	{
		return lhead;
	}
	else
	{
		size1 = lsize / 2;
		size2 = lsize - size1;
		lhead2 = lhead;
		for(int i = 0; i < size1; i++)
		{
			lhead1 = lhead2;
			lhead2 = lhead2 -> getNext();
		}
		lhead1 -> setNext(NULL);
		lhead1 = lhead;
		return merge(mergesort(lhead1, size1), mergesort(lhead2, size2));
	}
}

/** merges two lists together with their components going in order of smallest to largest
  *@pre none
  *@post the two lists have been merged into one list
  *@param lhead1 is the head ptr of one list you want to merge together, and lhead2 is the head ptr of the other list
  *@return new head ptr of the list. */ 
ListNode* ListP::merge(ListNode *lhead1, ListNode *lhead2)
{
	if(lhead1 == NULL)
	{
		return lhead2;
	}
	else if (lhead2 == NULL)
	{
		return lhead1;
	}
	else if (lhead1 -> getItem() <= lhead2 -> getItem())
	{
		lhead1 -> setNext(merge(lhead1 -> getNext(), lhead2));
		return lhead1;
	}
	else if (lhead1 -> getItem() > lhead2 -> getItem())
	{
		lhead2 -> setNext(merge(lhead1, lhead2 -> getNext()));
		return lhead2;
	}
}