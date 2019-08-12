/*
 * CityDatabaseTest.cpp
 *
 * Driver to test & compare the array- and list-based implementations of a city database.
 *
 *  Created on: Aug 9, 2019
 *      Author: alex
 */

#include "CityLinkedList.h"
#include "CityArrayList.h"
#include <ctime>
#include <random>
#include <iostream>
using std::cout; using std::to_string;

// Raise int to int power
int myPow(int x, int p)
{
	if (p == 0) return 1;
	if (p == 1) return x;

	int tmp = myPow(x, p/2);
	if (p%2 == 0) return tmp * tmp;
	else return x * tmp * tmp;
}

int main() {

	// Init variables and random distributions
	CityLinkedList LLdatabase(100);
	CityArrayList ALdatabase(100);

	const int NUM_INSERTIONS = 10000;
	const int NUM_SEARCHES = 100;
	const int NUM_DELETIONS = NUM_SEARCHES;
	const int MAP_SIZE = 10;
	clock_t start;

	std::random_device rd;
	std::mt19937 eng(rd());

	std::uniform_int_distribution<> posDistr(-MAP_SIZE,MAP_SIZE);
	std::uniform_int_distribution<> nameDistr(0,NUM_INSERTIONS-1);

	City cities[NUM_INSERTIONS];

	// Set up cities to insert
	int pos[2];
	string name;
	string baseName = "City";
	for (int i = 0; i < NUM_INSERTIONS; ++i) {
		pos[0] = posDistr(eng);
		pos[1] = posDistr(eng);
		name = baseName + std::to_string(i);
		cities[i] = City(name, pos);
	}

	cities[5].print();

	////////////
	// Insert //
	////////////

	// Init linked list
	start = clock();
	for (int i = 0; i < NUM_INSERTIONS; ++i) {
		LLdatabase.insertCity(cities[i]);
	}
	double LL_insert_time = (clock() - start)/ (double) CLOCKS_PER_SEC;
	cout << "Successfully inserted into linked list.\n";

	// Init array
	start = clock();
	for (int i = 0; i < NUM_INSERTIONS; ++i) {
		ALdatabase.insertCity(cities[i]);
	}
	double AL_insert_time = (clock() - start)/ (double) CLOCKS_PER_SEC;
	cout << "Successfully inserted into array.\n";

	////////////
	// Search //
	////////////

	// Set up names and positions to search for
	string names[NUM_SEARCHES];
	int poses[NUM_SEARCHES][2];
	for (int i = 0; i < NUM_SEARCHES; ++i) {
		names[i] = baseName + to_string(nameDistr(eng));
		poses[i][0] = posDistr(eng);
		poses[i][1] = posDistr(eng);
	}

	start = clock();
	// Search linked list by name
	for (int i = 0; i < NUM_SEARCHES; ++i) {
		LLdatabase.searchByName(names[i]);
	}
	double LL_name_search_time = (clock() - start)/ (double) CLOCKS_PER_SEC;
	cout << "Successfully searched linked list by name.\n";

	start = clock();
	// Search array by name
	for (int i = 0; i < NUM_SEARCHES; ++i) {
		ALdatabase.searchByName(names[i]);
	}
	double AL_name_search_time = (clock() - start)/ (double) CLOCKS_PER_SEC;
	cout << "Successfully searched array by name.\n";

	start = clock();
	// Search linked list by coordinate
	for (int i = 0; i < NUM_SEARCHES; ++i) {
		LLdatabase.searchByCoordinate(poses[i]);
	}
	double LL_pos_search_time = (clock() - start)/ (double) CLOCKS_PER_SEC;
	cout << "Successfully searched linked list by pos.\n";

	start = clock();
	// Search array by coordinate
	for (int i = 0; i < NUM_SEARCHES; ++i) {
		ALdatabase.searchByCoordinate(poses[i]);
	}
	double AL_pos_search_time = (clock() - start)/ (double) CLOCKS_PER_SEC;
	cout << "Successfully searched array by pos.\n";

	//////////////////////////////
	// Printing within distance //
	//////////////////////////////

	// Set origin and search distance
	int origin[2];
	origin[0] = 0;
	origin[1] = 0;
	double searchDist = 2.5;

	// Print array within searchDist of origin
	start = clock();
	ALdatabase.printWithinDistance(origin, searchDist);
	double AL_print_time = (clock() - start)/ (double) CLOCKS_PER_SEC;
	cout << "Should have found at least one city in the range... (array)\n";

	// Print array within searchDist of origin
	start = clock();
	LLdatabase.printWithinDistance(origin, searchDist);
	double LL_print_time = (clock() - start)/ (double) CLOCKS_PER_SEC;
	cout << "Should have found at least one city in the range... (linked list)\n";

	//////////////
	// Deleting //
	//////////////

	start = clock();
	// Search linked list by name
	for (int i = 0; i < NUM_DELETIONS; ++i) {
		LLdatabase.deleteByName(names[i]);
	}
	double LL_name_delete_time = (clock() - start)/ (double) CLOCKS_PER_SEC;
	cout << "Successfully deleted from linked list by name.\n";

	start = clock();
	// Search array by name
	for (int i = 0; i < NUM_DELETIONS; ++i) {
		ALdatabase.deleteByName(names[i]);
	}
	double AL_name_delete_time = (clock() - start)/ (double) CLOCKS_PER_SEC;
	cout << "Successfully deleted from array by name.\n";

	start = clock();
	// Search linked list by coordinate
	for (int i = 0; i < NUM_DELETIONS; ++i) {
		LLdatabase.deleteByCoordinate(poses[i]);
	}
	double LL_pos_delete_time = (clock() - start)/ (double) CLOCKS_PER_SEC;
	cout << "Successfully deleted from linked list by pos.\n";

	start = clock();
	// Search array by coordinate
	for (int i = 0; i < NUM_DELETIONS; ++i) {
		ALdatabase.deleteByCoordinate(poses[i]);
	}
	double AL_pos_delete_time = (clock() - start)/ (double) CLOCKS_PER_SEC;
	cout << "Successfully deleted from array by pos.\n";

	// Print timing results
	cout << "Time to insert into array database: " << AL_insert_time << "\n";
	cout << "Time to insert into linked database: " << LL_insert_time << "\n";
	cout << "Time to print within distance from array database: " << AL_print_time << "\n";
	cout << "Time to print within distance from linked database: " << LL_print_time << "\n";
	cout << "Time to search array database by name: " << AL_name_search_time << "\n";
	cout << "Time to search linked database by name: " << LL_name_search_time << "\n";
	cout << "Time to search array database by coordinate: " << AL_pos_search_time << "\n";
	cout << "Time to search linked database by coordinate: " << LL_pos_search_time << "\n";
	cout << "Time to delete from array database by name: " << AL_name_delete_time << "\n";
	cout << "Time to delete from linked database by name: " << LL_name_delete_time << "\n";
	cout << "Time to delete from array database by coordinate: " << AL_pos_delete_time << "\n";
	cout << "Time to delete from linked database by coordinate: " << LL_pos_delete_time << "\n";
}
