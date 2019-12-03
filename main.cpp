#include "BinarySearchTree.h"  // BST ADT 
#include <iostream>
#include <fstream>
#include <string>
#include "Mail.hpp"
#include "Hash.h"
using namespace std;
/**
This is the best I can think of and I think we need to add setter for the tracking number and the address.
**/
void printWelcome();
void printMenu();
void printEnd();
void buildBST(string fileName, BinarySearchTree<Mail>* mailTree);
//void searchPrimaryKey(Hash<int>* table);
//void searchSecondaryKey(BinarySearchTree<Mail>* addressTree);
void printMail(Mail& a);
int main()
{
	string fileName = "Mail.txt";
	BinarySearchTree<Mail>* mailTree = new BinarySearchTree<Mail>;
	buildBST(fileName, mailTree);
	mailTree->inOrder(printMail);
}
void printWelcome()
{
	cout << "========================================\n";
	cout << "WELCOME TO OUR TEAM PROJECT\n";
	cout << "By Keshav Gurushanka, Devryan Singh, Can Huynh, Joseph Monge, and Thinh Huynh\n";
	cout << "========================================\n";
}
void printMenu()
{
	cout << "INPUT GUIDE:\n";
	cout << "D - Display first Binary Search Tree ( sorted by City )\n";
	cout << "I - Display second Binary Search Tree (sorted by tracking number)\n";
	cout << "B - Search by the primary key (Tracking number is the primary key and it is unique key)\n";
	cout << "S - Search by the secondary key (by city)\n";
	cout << "H -  Display Hash Table (using tracking number as hash key and LinkedList as collision resolution)\n";
	cout << "X - Search hash: \n";

	cout << "E -  Exit \n";
}
void printEnd()
{
	cout << "==============================\n";
	cout << "THANK YOU FOR USING THE PROGRAM\n";
	cout << "==============================\n";

}
void buildBST(string fileName, BinarySearchTree<Mail>* addressTree)
{
	ifstream inFile;
	string street, city, state, track;
	int zip;
	Mail a;
	
	inFile.open(fileName);

	if (!inFile) {
		cout << "Error opening the input file: \"" << fileName << "\"" << endl;
		exit(EXIT_FAILURE);
	}

	while (inFile >> track >> city >> state >> zip )
	{
		a.setTracking(track);
		getline(inFile, street);
		a.setStreet(street);
		a.setCity(city);
		a.setState(state);
		a.setZip(zip);
		addressTree->insert(a);
	}

	inFile.close();

}
void printMail(Mail& a)
{
	cout << a;
}
/*void searchPrimaryKey(Hash<Mail>* table)
{
	int trackingTemp;
	cout << "Please enter your tracking number for mailing : ";
	cin >> trackingTemp;


	Mail obj;
	Mail returnItem;
	obj.setTracking(trackingTemp);

	if (table->search(obj, returnItem))
	{
		cout << returnItem;
	}
}

void searchSecondaryKey(BinarySearchTree<Mail>* addressTree)
{
	string addressTemp;
	cout << "Please enter the address for mailing : ";
	getline(cin, addressTemp);
	cin.ignore();

	Mail obj;
	Mail returnItem;
	obj.setAddrees(addressTemp);

	if (addressTree->search(obj, returnItem))
	{
		cout << returnItem;
	}

}

void searchByState(Hash<Mail>* table)
{
	Mail obj;
	Mail returnItem;
	string stateTemp;

	cout << "Please enter the state : ";
	getline(cin, stateTemp);
	cin.ignore();

	obj.setState(stateTemp);
	if (table->search(obj, returnItem))
	{
		cout << returnItem;
	}
}*/



