#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

template <typename T1, typename T2>
class ArrayNode {

public:

	ArrayNode() {}
	ArrayNode(T1 initialName, T2 initialPoint) { nameData = initialName, pointData = initialPoint; }
	~ArrayNode() {}

	void setName(T1 newName) { nameData = newName; }
	void setPoint(T2 newPoint) { pointData = newPoint; }
	void addPoints(T2 extraPoints) { pointData += extraPoints; }

	T1 getName() { return nameData; }
	T2 getPoint() { return pointData; }

private:

	T1 nameData;
	T2 pointData;

};


template <typename T1, typename T2>
class Array {

public:

	Array() { currentPosition = 0; }
	~Array() {}

	ArrayNode<T1,T2>* accessArrayPosition(int position) { return &mainArray[position]; }
	void upPosition() { currentPosition++; }
	void downPosition() { currentPosition--; }
	int accessPosition() { return currentPosition; }
	void setPosition(int newPosition) { currentPosition = newPosition; }

private:

	ArrayNode<T1, T2> mainArray[100];
	int currentPosition;

};

void readAllPlayers(Array<std::string, int>* playerList);
void writeAllPlayers(Array<std::string, int> playerList);

void readAllPlayers(Array<std::string, int>* playerList) {

	std::ifstream readFile;
	readFile.open("CPTS223_assignments/cpts223PA1/profiles.csv");

	std::string line;

	while (getline(readFile, line)) {

		std::string newPlayer;
		int newPlayerPoints;

		std::stringstream ss(line);
		std::string tempString;

		getline(ss, tempString, ',');

		newPlayer = tempString;

		getline(ss, tempString, '\n');

		newPlayerPoints = stoi(tempString);

		(*playerList).accessArrayPosition(playerList->accessPosition())->setName(newPlayer);
		(*playerList).accessArrayPosition(playerList->accessPosition())->setPoint(newPlayerPoints);
		(*playerList).upPosition();

	}

	readFile.close();

}
void writeAllPlayers(Array<std::string, int> playerList) {

	std::ofstream writeFile;
	writeFile.open("CPTS223_assignments/cpts223PA1/profiles.csv");

	for (int i = 0; i < playerList.accessPosition(); i++) {

		writeFile << playerList.accessArrayPosition(i)->getName() << "," << playerList.accessArrayPosition(i)->getPoint();
		if (i != playerList.accessPosition() - 1) writeFile << "\n";

	}

	writeFile.close();

}
