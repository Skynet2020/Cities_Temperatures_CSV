#include "main.h"

void displaySearchMenu();
int getChoice();
int recieveValue();
int searchMaxTemp(CitiesIndex*, CitiesData*, int, int, int);
int searchMinTemp(CitiesIndex*, CitiesData*, int, int, int);
int searchAvgTemp(CitiesIndex*, CitiesData*, int, int, int);

/*
 * 1. Displays the menu
 * 2. Asks for choice
 * 3. Sorts the needed column
 * 4. Asks for value to search
 * 5. Returns the result
 * 6. If not found, returns -1, which is processed by main with output
 *      "The entry hasn't been found".
 */
int searchCities(CitiesIndex* index, CitiesData* data, int dbLength){
    int result;
    displaySearchMenu();
    int choice = getChoice();
    int value;
    if (choice == 1){        
        int sortCriteria = 3;
        sortCities(index, data, dbLength, sortCriteria);   
        value = recieveValue();
        result = searchMaxTemp(index, data, 0, dbLength, value);        
    }else if(choice == 2){
        int sortCriteria = 4;
        sortCities(index, data, dbLength, sortCriteria);    
        value = recieveValue();
        result = searchMinTemp(index, data, 0, dbLength, value);        
    }else if(choice == 3){
        int sortCriteria = 5;
        sortCities(index, data, dbLength, sortCriteria);    
        value = recieveValue();
        result = searchAvgTemp(index, data, 0, dbLength, value);
    }
    else if(choice == 0){
        result = -5;
    }
    return result;    
}

void displaySearchMenu(){
    system("clear");
        displayHeader();
    cout << "Choose the type of temperature:\n";
    cout << "\t1. Maximum\n";
    cout << "\t2. Minimum\n";
    cout << "\t3. Average\n";
    cout << "\t0. Exit\n";
}

int getChoice(){
    int choice = 0;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice>=0 && choice<4){
        return choice;
    }else{
        cout << "Choose a valid option" << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

int recieveValue(){
    int value;
    cout << "Enter a temperature to search: ";
    cin >> value;
    return value;
}

int searchMaxTemp(CitiesIndex* index, CitiesData* data, int start, int end, int value){    
    int middle;
    if (start > end)
        return -1;    
    middle = (start + end) / 2;
    if (data[middle].max == value)
        return middle;
    if (data[middle].max > value)
        return searchMaxTemp(index, data, start, middle - 1, value);
    else
        return searchMaxTemp(index, data, middle + 1, end, value);
}

int searchMinTemp(CitiesIndex* index, CitiesData* data, int start, int end, int value){    
    int middle;
    if (start > end)
        return -1;    
    middle = (start + end) / 2;
    if (data[middle].min == value)
        return middle;
    if (data[middle].min > value)
        return searchMinTemp(index, data, start, middle - 1, value);
    else
        return searchMinTemp(index, data, middle + 1, end, value);
}

int searchAvgTemp(CitiesIndex* index, CitiesData* data, int start, int end, int value){    
    int middle;
    if (start > end)
        return -1;    
    middle = (start + end) / 2;
    if (data[middle].average == value)
        return middle;
    if (data[middle].average > value)
        return searchAvgTemp(index, data, start, middle - 1, value);
    else
        return searchAvgTemp(index, data, middle + 1, end, value);
}

