/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "main.h"

void readCities(ifstream& inputFile, CitiesIndex* index, CitiesData* data){
    int entryIndex = 0;
    string entry;
    while (getline(inputFile, entry)) {
        if (entry == "\0" && !inputFile.eof()) {
            cout << "Entry's value is '\0'" << endl;
            continue;
        } else {
//            cout << "Element " << entryIndex << ": " << entry << endl;
            stringstream linestream(entry);
            string currentValue;
            int counter = 0;
            
            while (getline(linestream, currentValue, ',')) {
//                cout << "Entry value is: " << currentValue << endl;
                if (counter == 0) {
                    index[entryIndex].id = currentValue;                    
                } else if (counter == 1) {
                    index[entryIndex].name = currentValue;
                } else if (counter == 2) {
                    data[entryIndex].max = stoi(currentValue);
                } else if (counter == 3) {
                    data[entryIndex].min = stoi(currentValue);
                } else if (counter == 4) {
                    data[entryIndex].average = stoi(currentValue);
                }
                counter++;
            };
            entryIndex++;
//            cout << "Line finished." << endl;
        }
    };
}
