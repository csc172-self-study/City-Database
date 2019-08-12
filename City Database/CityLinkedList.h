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

	void insertCity(City);
	int searchByName(string);
	void deleteByName(string);
	int searchByCoordinate(int*);
	void deleteByCoordinate(int*);
	void printWithinDistance(int*, double);
};

#endif /* CITYLINKEDLIST_H_ */
