#include "readList.h"
#include <iostream>
#include <fstream>
#include <string>

void readList() {
    std::string wReturn;
    std::fstream reading("data/myPhoneData.txt");
    int counter = 1;
    if (reading.is_open()) {
        if (reading.peek() == std::fstream::traits_type::eof()) {
            std::cout << "The directory is empty.\n";
        } else {
            std::cout << "---------------------\n";
            std::cout << "-- Phone Contacts: --\n";
            std::cout << "---------------------\n";
            std::cout << "Name  |  Number:\n";
            std::cout << "---------------------\n";
            while (std::getline(reading, wReturn)) {
                std::cout << counter << ": "<< wReturn << std::endl;
                counter++;
            }
            reading.close();
        }
    } else {
        std::cerr << "Error: Could not open the file for reading.\n";
    }
}
