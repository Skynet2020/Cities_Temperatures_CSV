/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "main.h"

ostream& operator<<(ostream& stream, const CitiesIndex& city) {
// This line defines the length of a city name and puts it as the argument
// to the setw() method.
//    int cityNameLength = city.name.length();
    stream << setw(5) << right << city.id + ": " << setw(12) << left
            << city.name;
    return stream;
}
ostream& operator<<(ostream& stream, const CitiesData& temperatures) {
// This line defines the length of a city name and puts it as the argument
// to the setw() method.
//    int cityNameLength = city.name.length();  
    
    stream << setw(5) << right << to_string(temperatures.max) + " "
            << setw(5) << right << to_string(temperatures.min) + " "
            << setw(5) << to_string(temperatures.average);
    return stream;
}
