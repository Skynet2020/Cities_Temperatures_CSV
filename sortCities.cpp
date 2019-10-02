#include "main.h"


/*** LOCAL FUNCTIONS PROTOTYPES ***/
void sortByID(CitiesIndex* index, CitiesData* data, int dbLength);
void sortByCity(CitiesIndex* index, CitiesData* data, int dbLength);
void sortByMax(CitiesIndex* index, CitiesData* data, int dbLength);
void sortByMin(CitiesIndex* index, CitiesData* data, int dbLength);
void sortByAvg(CitiesIndex* index, CitiesData* data, int dbLength);


/* Function #2 in main
 * 1. Asks for the sorting criteria in main
 * 2. Passes the value to this function
 * 3. This function sorts according to the criteria
 */
void sortCities(CitiesIndex* index, CitiesData* data, int dbLength, int sortCriteria){
    
    if (sortCriteria == 1){
        sortByID(index, data, dbLength);
    }
    else if(sortCriteria == 2){
        sortByCity(index,data,dbLength);
    }
    else if(sortCriteria == 3){
        sortByMax(index,data,dbLength);
    }
    else if(sortCriteria == 4){
        sortByMin(index,data,dbLength);
    }
    else if(sortCriteria == 5){
        sortByAvg(index,data,dbLength);
    }
    else{
        cout << "Invalid input" << endl; 
    }
}

void displaySortMenu(){    
    cout << "  Choose a column to sort" << endl;
    cout << "1. Sort by ID" << endl;
    cout << "2. Sort by city name" << endl;
    cout << "3. Sort by max temperature" << endl;
    cout << "4. Sort by min temperature" << endl;
    cout << "5. Sort by average temperature" << endl;
}


void sortByID(CitiesIndex* index, CitiesData* data, int dbLength){
    int startScan, minIndex;
    int minValue;
    CitiesIndex temp_1;
    CitiesData temp_2;
    
    for (startScan = 0; startScan < dbLength-1; startScan++) {
        minIndex = startScan;
        minValue = stoi(index[startScan].id);
        temp_1 = index[startScan];
        temp_2 = data[startScan];
        for (int i = startScan+1; i < dbLength; i++) {
            if (stoi(index[i].id) < minValue) {
                minValue = stoi(index[i].id);
                temp_1 = index[i];
                temp_2 = data[i];
                minIndex = i;
            }
        }
        index[minIndex] = index[startScan];
        index[startScan] = temp_1;
        data[minIndex] = data[startScan];
        data[startScan] = temp_2;
    }
}

void sortByCity(CitiesIndex* index, CitiesData* data, int dbLength){
    int startScan, minIndex;
    string minValue;
    CitiesIndex temp_1;
    CitiesData temp_2;
    
    for (startScan = 0; startScan < dbLength-1; startScan++) {
        minIndex = startScan;
        minValue = index[startScan].name;
        temp_1 = index[startScan];
        temp_2 = data[startScan];
        for (int i = startScan+1; i < dbLength; i++)  {
            if (index[i].name < minValue) {
                minValue = index[i].name;
                temp_1 = index[i];
                temp_2 = data[i];
                minIndex = i;
            }
        }
        index[minIndex] = index[startScan];
        index[startScan] = temp_1;
        data[minIndex] = data[startScan];
        data[startScan] = temp_2;
    }
}

void sortByMax(CitiesIndex* index, CitiesData* data, int dbLength){
    int startScan, minIndex;
    int minValue;
    CitiesIndex temp_1;
    CitiesData temp_2;
    
    for (startScan = 0; startScan < dbLength-1; startScan++) {
        minIndex = startScan;
        minValue = data[startScan].max;
        temp_1 = index[startScan];
        temp_2 = data[startScan];
        for (int i = startScan+1; i < dbLength; i++) {
            if (data[i].max < minValue) {
                minValue = data[i].max;
                temp_1 = index[i];
                temp_2 = data[i];
                minIndex = i;
            }
        }
        index[minIndex] = index[startScan];
        index[startScan] = temp_1;
        data[minIndex] = data[startScan];
        data[startScan] = temp_2;
    }
}

void sortByMin(CitiesIndex* index, CitiesData* data, int dbLength){
    int startScan, minIndex;
    int minValue;
    CitiesIndex temp_1;
    CitiesData temp_2;
    
    for (startScan = 0; startScan < dbLength-1; startScan++){
        minIndex = startScan;
        minValue = data[startScan].min;
        temp_1 = index[startScan];
        temp_2 = data[startScan];
        for (int i = startScan+1; i < dbLength; i++) {
            if (data[i].min < minValue) {
                minValue = data[i].min;
                temp_1 = index[i];
                temp_2 = data[i];
                minIndex = i;
            }
        }
        index[minIndex] = index[startScan];
        index[startScan] = temp_1;
        data[minIndex] = data[startScan];
        data[startScan] = temp_2;
    }
}

void sortByAvg(CitiesIndex* index, CitiesData* data, int dbLength){
    int startScan, minIndex;
    int minValue;
    CitiesIndex temp_1;
    CitiesData temp_2;
    
    for (startScan = 0; startScan < dbLength-1; startScan++) {
        minIndex = startScan;
        minValue = data[startScan].average;
        temp_1 = index[startScan];
        temp_2 = data[startScan];
        for (int i = startScan+1; i < dbLength; i++) {
            if (data[i].average < minValue) {
                minValue = data[i].average;
                temp_1 = index[i];
                temp_2 = data[i];
                minIndex = i;
            }
        }
        index[minIndex] = index[startScan];
        index[startScan] = temp_1;
        data[minIndex] = data[startScan];
        data[startScan] = temp_2;
    }
}

