#include "main.h"


void displayCitiesAsDB(const CitiesIndex* index, const CitiesData* data, int dbLength){
  cout << setw(5) << right << "ID  " << setw(12) << left << "City" << setw(5)
            << right << "Max" << setw(5) << right << "Min" << setw(5) << "Avg"
            << endl;
  cout << "------------------------------------" << endl;
    for (int i=0; i<dbLength; i++){
        cout << index[i] << data[i] << endl;
    }  
}

