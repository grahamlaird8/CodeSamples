//simulation.cpp
//This function simulates a queue of requests for a magnetic disk
//by Graham Laird and Ethan Gruis
//11/30/2018

#include "queue.h"
#include "itemtype.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

//This function opens a file and checks if the opening was successful
//Pre: infile has been declared
//Post: input file is open for reading
//Usage: openInputFile(infile);
void openInputFile(ifstream& infile);

//This function closes an input file 
//Pre: infile has been declared
//Post: input file is closed
//Usage: closeInputFile(infile);
void closeInputFile(ifstream& infile);

//This function reads a set number of lines of the input file
//Pre: disk and isNotFull have been declared, the input file has been opened and numberOfItems has been assigned a value;
//Post: disk contains multiple lines of data from the input file
//Usage: readInputFile(disk, isNotFull, infile, 3);
void readInputFile(Queue& disk, bool& isNotFull, ifstream& infile, int numberOfItems);

//This function takes a single line of data from the input file and adds it onto disk
//Pre: disk and isNotFull have been declared, the input file has been opened
//Post: disk contains added line of data 
//Usage: writeLineToDisk(disk, ifNotFull, infile);
void writeLineToDisk(Queue& disk, bool& isNotFull, ifstream& infile);

//This function serves the first item in disk numberOfServes times 
//Pre: disk and isNotFull have been declared and numberOfServes has been assigned a value
//Post: the first item(s) of disk have been removed and printed to the screen
//Usage: serveRequest(disk, isNotFull, 2);
void serveRequest(Queue& disk, bool& isNotFull, int numberOfServes);

//This function prints the contents of disk to the screen
//Pre: disk has been declared
//Post: the contents of disk have been printed to the screen
//Usage: printQueue(disk);
void printQueue(Queue& disk);

//This function simulates the reading and writing of the disk on a hard drive
//Pre: None
//Post: The requests in the input file come in and have been served and output to the screen
//Usage: runSimulation();
void runSimulation();

//This function handles the logic behind serving requests and adding new data to the disk depending on the remaining size of disk 
//Pre: size has been assigned a value, and infile, disk, and isNotFull have been declared
//Post: the serving and adding of the contents of disk has been displayed to the user 
//Usage: handleRequests(size, infile, disk, isNotFull); 
void handleRequests(int size, ifstream& infile, Queue& disk, bool& isNotFull);

//This function prints a specified number of newlines
//Pre: numberOfLines is assigned a value
//Post: numberOfLines newlines have been printed to the screen
//Usage: printNewLines(3);
void printNewLines(int numberOfLines);

//This function pauses the function until the user hits enter
//Pre: message is declared
//Post: the function runs after the user hits enter
//Usage: pauseFunction("Please hit enter to continue: ");
void pauseFunction(string message);

int main()
{
	srand(0);
	runSimulation();
	return 0;
}

//This function simulates the reading and writing of the disk on a hard drive
//Pre: None
//Post: The requests in the input file come in and have been served and output to the screen
//Usage: runSimulation();
void runSimulation()
{
	ifstream infile;
	Queue disk;
	bool isNotFull = true;
	
	openInputFile(infile);
	
	readInputFile(disk, isNotFull, infile, 4);
	printQueue(disk);
	pauseFunction("Press enter to begin serving requests: ");
	
	while(!disk.isEmpty())
	{
		int size = disk.getSize();
		handleRequests(size, infile, disk, isNotFull);
	}
	
	closeInputFile(infile);
}

//This function handles the logic behind serving requests and adding new data to the disk depending on the remaining size of disk 
//Pre: size has been assigned a value, and infile, disk, and isNotFull have been declared
//Post: the serving and adding of the contents of disk has been displayed to the user 
//Usage: handleRequests(size, infile, disk, isNotFull); 
void handleRequests(int size, ifstream& infile, Queue& disk, bool& isNotFull)
{
	if(size >= 3)
	{
		serveRequest(disk, isNotFull, (rand() % 3) + 1);
		if(infile.good())
		{
			readInputFile(disk, isNotFull, infile, (rand() % 4));		
		}
		printNewLines(1);
		printQueue(disk);		
		pauseFunction("Press enter to continue serving requests: ");
	}
	else if(size == 2)
	{
		serveRequest(disk, isNotFull, 1);
		if(infile.good())
		{
			readInputFile(disk, isNotFull, infile, 1);
		}
		printQueue(disk);
		pauseFunction("Press enter to continue serving requests: ");
	}
	else
	{
		serveRequest(disk, isNotFull, 1);
		pauseFunction("All requests have been served. Press enter to exit the simulation:");
	}
}

//This function closes an input file 
//Pre: infile has been declared
//Post: input file is closed
//Usage: closeInputFile(infile);
void closeInputFile(ifstream& infile)
{
	infile.close();
}

//This function opens a file and checks if the opening was successful
//Pre: infile has been declared
//Post: input file is open for reading
//Usage: openInputFile(infile);
void openInputFile(ifstream& infile)
{
	infile.open("requests.dat");
	if (infile.fail())
	{
		cout << "Error opening file named requests.dat";
		exit(1); // the only time this is allowed
	}
}

//This function takes a single line of data from the input file and adds it onto disk
//Pre: disk and isNotFull have been declared, the input file has been opened
//Post: disk contains added line of data 
//Usage: writeLineToDisk(disk, ifNotFull, infile);
void writeLineToDisk(Queue& disk, bool& isNotFull, ifstream& infile)
{
	ItemType newItem;
	
	infile >> newItem;
	disk.lineUp(newItem, isNotFull);
}

//This function reads a set number of lines of the input file
//Pre: disk and isNotFull have been declared, the input file has been opened and numberOfItems has been assigned a value;
//Post: disk contains multiple lines of data from the input file
//Usage: readInputFile(disk, isNotFull, infile, 3);
void readInputFile(Queue& disk, bool& isNotFull, ifstream& infile, int numberOfItems)
{
	string temp;
	if(infile.good())
	{
		cout << "+ Receiving new requests. Adding to the back of the Queue.";
		printNewLines(2);
	}
		for(int count = 1 ; count <= numberOfItems ; count++)
		{
			if(infile.good())
			{
				writeLineToDisk(disk, isNotFull, infile);
				getline(infile, temp);
			}
		}
}

//This function prints a specified number of newlines
//Pre: numberOfLines is assigned a value
//Post: numberOfLines newlines have been printed to the screen
//Usage: printNewLines(3);
void printNewLines(int numberOfLines)
{
	for(int count = 0 ; count < numberOfLines ; count++)
	{
		cout << endl;
	}
}

//This function prints the contents of disk to the screen
//Pre: disk has been declared
//Post: the contents of disk have been printed to the screen
//Usage: printQueue(disk);
void printQueue(Queue& disk)
{
	cout << "Current Queue of requests waiting to be served: ";
	printNewLines(2);
	cout << disk;
	printNewLines(2);
}

//This function serves the first item in disk numberOfServes times 
//Pre: disk and isNotFull have been declared and numberOfServes has been assigned a value
//Post: the first item(s) of disk have been removed and printed to the screen
//Usage: serveRequest(disk, isNotFull, 2);
void serveRequest(Queue& disk, bool& isNotFull, int numberOfServes)
{
	for(int count = 1 ; count <= numberOfServes ; count++)
	{
		if(disk.getSize() != 1)
		{
			cout << "- Now serving: " << endl << endl << disk.getWhoIsServed();
			printNewLines(3);
			disk.getServed(isNotFull);
			pauseFunction("Press enter to continue serving requests: ");
		}
		else
		{
			cout << "- Now serving: " << endl << endl << disk.getWhoIsServed();
			printNewLines(3);
			disk.getServed(isNotFull);
		}
	}
}

//This function pauses the function until the user hits enter
//Pre: message is declared
//Post: the function runs after the user hits enter
//Usage: pauseFunction("Please hit enter to continue: ");
void pauseFunction(string message)
{
	string temp;
	printNewLines(1);
	cout << message << endl << "__________________________________________________________________" << endl;
	getline(cin, temp);
	printNewLines(2);
}