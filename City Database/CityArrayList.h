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

	void insertCity(City);
	int searchByName(string key);
	void deleteByName(string key);
	int searchByCoordinate(int key[]);
	void deleteByCoordinate(int key[]);
	void printWithinDistance(int orig[], double dist);
};

#endif /* CITYARRAYLIST_H_ */
