// author Dr Y, Graham Laird, Ethan Gruis, and CPSC 122 Fall 2018
// date: November 14, 2018
// file queue.cpp

//   Implementation for ADT Queue
//   data object: a queue which is a First In First Out List
//   data structure: a circularly linked list
//   operations: create, destroy, check if empty, copy, add to back, 
//               remove from front, check front


#include "queue.h"
#include "itemtype.h"
#include <iostream>
using namespace std;


struct Node
{
	ItemType item;
	Node* next;
};

   //outputs a queue to a file or the screen
   //pre  : rhsq exists. output is open.
   //post : contents of rhsq have been output
   //usage: cout << rhsq << endl;   
   ostream& operator<< (ostream& output, const Queue& rhsq)
   {
	   Node* currentptr;
	   currentptr = new Node;
	   
	   if (not rhsq.isEmpty())
	   {
		   
	      currentptr = rhsq.backptr -> next;
	      while(currentptr != rhsq.backptr)
	      {
		      output << currentptr -> item << " , "; 
		      currentptr = currentptr -> next;
	      }
	      output << currentptr -> item << " <- back" << endl;
	   } else {
		   output << "the queue is empty" << endl;
	   }
	   return output;
   }


   //creates an empty queue
   //post : an empty queue
   //usage: Queue q;
   Queue::Queue()
   {
	   backptr = nullptr;
   }
   
   //copies an existing queue
   //pre  : rhsq exists
   //post : queue object is a copy of rhsq
   //usage: Queue q(anotherq); or passing a Que object by value
   Queue::Queue(const Queue& rhsq)
   {
		backptr = nullptr;
		bool isNotEmpty = true;
		if(isNotEmpty)
		{
			getServed(isNotEmpty);
		}
		operator=(rhsq);
   }
   
   //destroys a queue
   //pre  : queue object exists
   //post : queue object does not exist
   //usage: automatically done at the end of scope
	Queue::~Queue()
	{
		bool isNotEmpty;
		while(!isEmpty())
			getServed(isNotEmpty);	
	}
 
   
   
	//finds the size of a queue object
	//pre  : queue object exists
	//post : returns the size of the queue object
	//usage: cout << q.getSize();
	int Queue::getSize() const
	{
		Node* currentptr = backptr -> next;
		int size = 0;
		
		while (currentptr != backptr)
		{
			size++;
			currentptr = currentptr -> next;
		}
		
		size++;
		
		return size;
	}
   
   //checks to see if a queue object is empty
   //pre  : queue object exists
   //post : if queue is empty returns true else returns false
   //usage: if (q.isEmpty())
   bool Queue::isEmpty() const
   {
	   return (backptr == nullptr);
   }
   
   //inserts a new item at the rear of the queue
   //pre  : newItem has an assigned value; queue exists
   //post : if queue object is not full, newItem is added
   //       at the rear of the queue and isNotFull is true else isNotFull is false
   // usage: myq.lineUp(hunter, isNotFull);
   void Queue::lineUp(ItemType newItem, bool& isNotFull)
   {
		Node* newptr;
		newptr = new Node;
	   
		if (isEmpty())
		{
			backptr = new Node;
			if (backptr != nullptr)
			{
				backptr -> item = newItem;
				backptr -> next = backptr;
				isNotFull = true;
			} else {
				isNotFull = false;
			}
		} else {
			if (newptr != nullptr)
			{
				newptr -> item = newItem;
				newptr -> next = backptr -> next;
				backptr -> next = newptr;
				backptr = newptr;
				isNotFull = true;
			} else {
				isNotFull = false;
			}	   
		}
	}
   
	//deletes item from the front of the queue after copying it
	//pre  : queue exists
	//post : if queue is nonempty, front of queue has been removed
	//         and isNotEmpty is true else isNotEmpty is false
	// usage: rui.getServed(isNotEmpty);
	void Queue::getServed(bool& isNotEmpty)
	{
		Node* newptr;
		newptr = new Node;
		
		if(isEmpty())
		{
			isNotEmpty = false;
		}
		else if(backptr == backptr -> next)
		{
			delete backptr -> next;
			backptr = nullptr;
			isNotEmpty = false;
		}
		else
		{
			newptr = backptr -> next -> next;
			delete backptr -> next;
			backptr -> next = newptr;
			isNotEmpty = true;
		}
	}
   
   //copies the front item
   //pre  : queue exists and is not empty
   //post : returns the front item in the queue
   //usage: rui.getWhoIsServed();
   ItemType Queue::getWhoIsServed() const
   {
	   return backptr -> next -> item;
   }
   
   //copies the queue
   //pre  : rhsq exists. queue object exists but may be empty
   //post : queue object is a copy of rhsq
   //usage: copyq.operator=(rhsq);
   //      or        copyq = rhsq;
   Queue& Queue::operator=(const Queue& rhsq)
   {
	   Node* currentptr;
	   bool isNotFull;
	   
	   if(this != &rhsq)
	   {
			while(!isEmpty())
			{
				getServed(isNotFull);
			}				
			if (not rhsq.isEmpty())
			{  
				currentptr = rhsq.backptr -> next;
				while(currentptr != rhsq.backptr)
				{
					lineUp(currentptr -> item, isNotFull);
					currentptr = currentptr -> next;
				}
				lineUp(currentptr -> item, isNotFull);
			}
	   }
	return *this;
}
