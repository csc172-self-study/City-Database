/*
 * City.cpp
 *
 *  Created on: Jul 10, 2019
 *      Author: alex
 */

#include "City.h"
#include <iostream>
using std::cout;

City::City() {
	name = "";
	pos[0] = 0;
	pos[1] = 1;
}

City::City(string cityName, int* coord) {
	name = cityName;
	pos[0] = coord[0];
	pos[1] = coord[1];
}

City::~City() {

}

void City::print() {
	cout << name << "\t" << pos[0] << "\t" << pos[1] << "\n";
}

