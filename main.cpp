#include "main.h"

 
int main(int argc, char** argv) {
    
    ifstream inputFile("cities.csv");        
    const int dbLength = countCities(inputFile);
    int choice;    
    CitiesIndex citiesInfo[dbLength];
    CitiesData temperatures[dbLength];            
    inputFile.clear();
    inputFile.seekg(0, inputFile.beg);    
    readCities(inputFile, citiesInfo, temperatures);
    inputFile.close();
    
    /*** BEGINNING OF INTERACTION ***/    
    while(choice != 4){
        displayHeader();
        displayCities(citiesInfo, temperatures, dbLength);
        cout << endl;
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        if(choice == 1){
            char again = 'y';
            while(tolower(again) == 'y'){
                int sortCriteria;
                system("clear");            
//                  displayHeader();
                displayCitiesAsDB(citiesInfo, temperatures, dbLength);
                cout << " ------------------------------" << endl;
                displaySortMenu();            
                cout << "  Enter your choice: ";
                cin >> sortCriteria;
                while (sortCriteria <1 || sortCriteria >5){
                    cout << "Enter a valid choice: ";
                    cin >> sortCriteria;
                }
                system("clear");
                sortCities(citiesInfo, temperatures, dbLength, sortCriteria);
                cout << "     --- Sorted database ---" << endl;
                displayCitiesAsDB(citiesInfo, temperatures, dbLength);
                cout << "\nContinue? Y/N: ";
                cin >> again;
            }
            system("clear");            
        }else if(choice == 2){            
            char again = 'y';
            while (again == 'y'){
                int result = searchCities(citiesInfo, temperatures, dbLength);
                if(result == -1){
                    cout << "The entry hasn't been found" << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                    system("clear");
                }else if(result == -5){
                    break;
                }else{
                    system("clear");
                    cout << "    Your entry is in line " << result+1 << endl;
                    displayCitiesAsDB(citiesInfo, temperatures, dbLength);                    
                    cout << "\nContinue? Y/N: ";
                    cin >> again;
                }
            }
            system("clear");
        }
        else if(choice == 3){
            system("clear");
            sortCities(citiesInfo, temperatures, dbLength, 2);
            displayCitiesAsDB(citiesInfo, temperatures, dbLength);
            cout << "\nPress Enter to continue..." << endl;
            cin.get();
            cin.get();
            system("clear");
        }
        else if (choice <1 || choice >4) {
            cout << "Invalid choice input!" << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
            system("clear");
            displayCities(citiesInfo, temperatures, dbLength);
        }
        
    }
    cout << "    GOOD BYE!" << endl;
    return 0;
}

void displayHeader(){
    cout << setw(20) << "    --- Weather Monitor ---" << endl;
}

void displayMenu(){
    cout << "    --- MENU ---" << endl;
    cout << "1. Sort a column" << endl;
    cout << "2. Search an entry" << endl;
    cout << "3. Display the database" << endl;
    cout << "4. Exit" << endl;
}
