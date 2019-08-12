/*
 * CityLinkedList.cpp
 *
 *  Created on: Jul 10, 2019
 *      Author: alex
 */

#include "CityLinkedList.h"
#include "City.h"
#include <cmath>
#include <iostream>
using std::sqrt; using std::cout;

CityLinkedList::CityLinkedList(int size) : LinkedList<City>(size) {

}

CityLinkedList::~CityLinkedList() {

}

void CityLinkedList::insertCity(City inCity) {
	insert(inCity);
}

int CityLinkedList::searchByName(string key) {

	City city;
	for (int i = 0; i < length(); ++i) {
		moveToPos(i);
		city = getVal();
		if (city.getName() == key) {
			return i;
		}
	}

	return -1;

}

void CityLinkedList::deleteByName(string key) {
	int removePos = searchByName(key);
	moveToPos(removePos);
	remove();
}

int CityLinkedList::searchByCoordinate(int* key) {

	City city;
	for (int i = 0; i < length(); ++i) {
		moveToPos(i);
		city = getVal();
		if (city.getX() == key[0] && city.getY() == key[1]) {
			return i;
		}
	}

	return -1;
}

void CityLinkedList::deleteByCoordinate(int* key) {
	int removePos = searchByCoordinate(key);
	moveToPos(removePos);
	remove();
}

void CityLinkedList::printWithinDistance(int* orig, double dist) {
	bool firstPrint = true;

	for (int i = 0; i < length(); ++i) {
		moveToPos(i);
		City city = getVal();

		int xdist = city.getX()-orig[0];
		int ydist = city.getY()-orig[1];

		if (sqrt(xdist*xdist + ydist*ydist) <= dist) {
			if (firstPrint) {
				cout << "Name \t x \t y \n";
				firstPrint = false;
			}
			city.print();
		}
	}
}
