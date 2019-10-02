/* 
 * File:   main.h
 * Author: Arman B.
 */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
using namespace std;

#ifndef MAIN_H
#define MAIN_H

// This struct keeps the city ID and name from the inputFile
struct CitiesIndex {
    string id, name;
};
// This struct keeps the temperatures from the inputFile
struct CitiesData{
    int max, min, average;
};

ostream& operator<<(ostream&, const CitiesIndex&);
ostream& operator<<(ostream&, const CitiesData&);
int countCities(ifstream&);
void readCities(ifstream&, CitiesIndex*, CitiesData*);
void displayCities(const CitiesIndex*, const CitiesData*, int);
void displayCitiesAsDB(const CitiesIndex*, const CitiesData*, int);
int searchCities(CitiesIndex*, CitiesData*, int);
void sortCities(CitiesIndex*, CitiesData*, int, int sortCriteria);
void displayHeader();
void displayMenu();
void displaySortMenu();

#endif /* MAIN_H */

