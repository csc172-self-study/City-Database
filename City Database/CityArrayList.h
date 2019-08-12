/*
 * CityArrayList.h
 *
 *  Created on: Jul 10, 2019
 *      Author: alex
 */

#ifndef CITYARRAYLIST_H_
#define CITYARRAYLIST_H_

#include "InfiniteList.h"
#include "City.h"

class CityArrayList : InfiniteList<City> {
public:
	CityArrayList(int size);
	virtual ~CityArrayList();

	void insertCity(City); // Insert into database
	int searchByName(string key); // Search by name
	void deleteByName(string key); // Delete by name
	int searchByCoordinate(int key[2]); // Search by coordinate
	void deleteByCoordinate(int key[2]); // Delete by coordinate
	void printWithinDistance(int origin[2], double distance); // Print all cities within a distance of origin
};

#endif /* CITYARRAYLIST_H_ */
