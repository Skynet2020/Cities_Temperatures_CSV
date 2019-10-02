#include "main.h"

void displayCities(const CitiesIndex* index, const CitiesData* data, int dbLength){
    for (int i=0; i<dbLength; i++){
        cout << index[i].id + ": "
                << index[i].name + ": "
                << to_string(data[i].max) + ','
                << to_string(data[i].min) + ','
                << to_string(data[i].average)
                << endl;
    }
}

