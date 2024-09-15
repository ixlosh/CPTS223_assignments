#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// Template class: the node in the linked list
template <typename T1, typename T2>
class Node {
	
public:

	Node(T1 newData1, T2 newData2) { data1 = newData1, data2 = newData2, pNext = nullptr; }
	~Node() {}

	Node* getNextPtr() { return pNext; }

	void setData1(T1 newData) { data1 = newData; }
	void setData2(T2 newData) { data2 = newData; }
	void setNextPtr(Node* newNext) { pNext = newNext; }

	T1* getData1() { return &data1; };
	T2* getData2() { return &data2; };

private:

	T1 data1;
	T2 data2;
	Node* pNext;

};

// Define the linked list class
template <typename T1, typename T2>
class LinkedList {

public:

	LinkedList(Node<T1, T2>* newHead = nullptr) { pHead = newHead; }
	~LinkedList() {}

	void insertNode(Node <T1, T2>* newNode) {

		if (pHead == nullptr) {

			pHead = newNode;

		}
		else {

			Node<T1, T2>* tempPtr = pHead;

			while (tempPtr->getNextPtr() != nullptr) {

				tempPtr = tempPtr->getNextPtr();

			}

			tempPtr->setNextPtr(newNode);

		}

	}

	void setHeadPtr(Node<T1,T2>* newHead) { pHead = newHead; }
	Node<T1,T2>* getHeadPtr() { return pHead; }

	int getListSize() {

		int size = 0;

		if (pHead != nullptr) {

			Node<T1, T2>* tempPtr = pHead;

			while (tempPtr != nullptr) {

				size++;

				tempPtr = tempPtr->getNextPtr();

			}

		}

		return size;

	}

private:

	Node<T1, T2>* pHead;

};

void clearScreen();
void readAllCommands(LinkedList<std::string, std::string>* commandList);

void clearScreen() {

	system("cls");
	std::cout << "================================= The Game ===================================" << std::endl;

}
void readAllCommands(LinkedList<std::string, std::string>* commandList) {

	std::ifstream readFile;
	readFile.open("commands.csv");

	std::string line;
	
	if (!readFile.is_open()) {
		std::cout << "Error: Could not open the file." << std::endl;
		return;
	}

	getline(readFile, line);
	std::cout << line << std::endl;
	/*while () {
		
		std::string newCommand;
		std::string newCommandDescription;

		std::stringstream ss(line);
		std::string tempString;

		getline(ss, tempString, ',');

		newCommand = tempString;

		getline(ss, tempString, '"');
		getline(ss, tempString, '"');

		newCommandDescription = tempString;

		Node<std::string, std::string>* newNode = new Node<std::string, std::string>(newCommand, newCommandDescription);

		(*commandList).insertNode(newNode);

	}*/

}