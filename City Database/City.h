/*
 * City.h
 *
 *  Created on: Jul 10, 2019
 *      Author: alex
 */

#ifndef CITY_H_
#define CITY_H_

#include <string>
using std::string;

class City {
public:
	City();
	City(string name, int* pos);
	virtual ~City();
	void print();

	int pos[2];
	string name;
};

#endif /* CITY_H_ */
