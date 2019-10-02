/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "main.h"

int countCities(ifstream& cities){
    /*************** GETTING THE LENGTH OF THE FILE *************/
    string temp;
    int fileLength = 0;
    while (getline(cities, temp) && temp != "") {
//        cout << temp1 << endl;
        fileLength++;
    }
//    cout << "The file contains " << fileLength << " lines." << endl;
    return fileLength;
}
