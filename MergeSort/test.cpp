/** client program to test ADT ListP and Class ListNode
  *@file test.cpp
  *@author: Graham Laird
  *@date: 3/27/19 */

#include "ListP.h"
#include "ListNode.h"
#include <iostream>
using namespace std;

int main(){
	ListP *testPtr = new ListP();
	cout << "Show insert function works: " << endl;
	
	testPtr -> insert(1, 5);
	testPtr -> insert(2, 19);
	testPtr -> insert(3, 8);
	testPtr -> insert(2, 1);
	testPtr -> insert(4, 28);
	testPtr -> insert(6, 3);
	testPtr -> insert(1, 62);
	testPtr -> display();
	
	cout << endl << "Show remove function works: " << endl;
	testPtr -> remove(1);
	testPtr -> display();
	testPtr -> remove(6);
	testPtr -> display();
	testPtr -> remove(3);
	testPtr -> display();
	
	cout << endl << "Show sort_mergesort function and copy constructor works: " << endl;
	ListP *copyPtr = new ListP(testPtr);
	cout << "Original List:" << endl;
	copyPtr -> display();
	cout << "Sorted List:" << endl;
	testPtr -> sort_mergesort();
	testPtr -> display();
	
	cout << endl << "Show insert function still works: " << endl;
	testPtr -> insert(4, 103);
	testPtr -> insert(6, -49);
	testPtr -> insert(1, 0);
	testPtr -> display();
	
	cout << endl << "Show sort_mergesort function still works: " << endl;
	testPtr -> sort_mergesort();
	testPtr -> display();
	
	cout << endl << "That is all of the functions working, either directly displayed or used in other functions. Thank you!" << endl;
	
	return 0;
}