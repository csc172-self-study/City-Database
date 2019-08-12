/*
 * CityArrayList.cpp
 *
 *  Created on: Jul 10, 2019
 *      Author: alex
 */

#include "CityArrayList.h"
#include "City.h"
#include <cmath>
#include <iostream>
using std::sqrt; using std::cout;

CityArrayList::CityArrayList(int size) : InfiniteList<City>(size) {

}

CityArrayList::~CityArrayList() {

}

void CityArrayList::insertCity(City inCity) {
	insert(inCity);
}

int CityArrayList::searchByName(string key) {

	for (int i = 0; i < length(); ++i) {
		moveToPos(i);
		if (getVal().name == key) {
			return i;
		}
	}

	return -1;
}

void CityArrayList::deleteByName(string key) {
	int removePos = searchByName(key);
	moveToPos(removePos);
	remove();
}

int CityArrayList::searchByCoordinate(int key[]) {

	for (int i = 0; i < length(); ++i) {
		moveToPos(i);
		if (getVal().pos[0] == key[0] && getVal().pos[1] == key[1]) {
			return i;
		}
	}

	return -1;
}

void CityArrayList::deleteByCoordinate(int key[]) {
	int removePos = searchByCoordinate(key);
	moveToPos(removePos);
	remove();
}

void CityArrayList::printWithinDistance(int orig[], double dist) {
	bool firstPrint = true;

	for (int i = 0; i < length(); ++i) {
		moveToPos(i);
		City city = getVal();

		int xdist = city.pos[0]-orig[0];
		int ydist = city.pos[1]-orig[1];

		if (xdist*xdist + ydist*ydist <= dist*dist) {
			if (firstPrint) {
				cout << "Name \t x \t y \n";
				firstPrint = false;
			}
			city.print();
		}
	}
}
