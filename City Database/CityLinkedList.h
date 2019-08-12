/*
 * CityArrayList.h
 *
 *  Created on: Jul 10, 2019
 *      Author: alex
 */

#ifndef CITYLINKEDLIST_H_
#define CITYLINKEDLIST_H_

#include "LinkedList.h"
#include "City.h"

class CityLinkedList : LinkedList<City> {
public:
	CityLinkedList(int);
	virtual ~CityLinkedList();

	void insertCity(City); // Insert into database
	int searchByName(string key); // Search by name
	void deleteByName(string key); // Delete by name
	int searchByCoordinate(int key[2]); // Search by coordinate
	void deleteByCoordinate(int key[2]); // Delete by coordinate
	void printWithinDistance(int origin[2], double distance); // Print all cities within a distance of origin
};

#endif /* CITYLINKEDLIST_H_ */
