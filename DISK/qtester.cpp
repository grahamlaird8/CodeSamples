#include <iostream>
#include "queue.h"
#include "itemtype.h"
#include <fstream>


using namespace std;

int main()
{
	Queue spike, rui;
	bool isNotFull = true;
	ifstream infile;
	ItemType newItem;
	infile.open("requests.dat");
	
	infile >> newItem;
	spike.lineUp(newItem, isNotFull);
	infile >> newItem;
	spike.lineUp(newItem, isNotFull);
	infile >> newItem;
	spike.lineUp(newItem, isNotFull);
	infile >> newItem;
	spike.lineUp(newItem, isNotFull);
	infile >> newItem;
	rui.lineUp(newItem, isNotFull);
	infile >> newItem;
	rui.lineUp(newItem, isNotFull);
	infile >> newItem;
	rui.lineUp(newItem, isNotFull);
	
	cout << "          Queue 'spike':" << endl << endl;
	cout << "The Queue: " << spike << endl;
	cout << "Queue size: " << spike.getSize() << endl << endl;
	cout << "Being Served: " << spike.getWhoIsServed() << endl << endl;
	spike.getServed(isNotFull);
	cout << "Updated Queue: " << spike << endl << endl;
	
	cout << "          Queue 'rui':" << endl << endl;
	Queue norvell(rui);
	cout << "The Queue: " << rui << endl;
	cout << "Queue size: " << rui.getSize() << endl << endl << endl;
	
	cout << "          Queue 'norvell' constructed from 'rui':" << endl << endl;
	cout << "The Queue: " << norvell << endl << endl;
	norvell = spike;
	cout << "The Queue after being assigned as 'spike': " << norvell << endl << endl << endl;
	
	infile.close();
	
	return 0;
}