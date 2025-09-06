#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "readList.h"

void DeleteContact(std::string ci) {
    // Functionality to delete a specific contact can be implemented here.
    // This is a placeholder for future development.
    std::vector<std::string> temp;
    std::fstream reading("data/myPhoneData.txt");
    std::string wReturn;
    while (temp.size() == countsize()){
        if(ci.find_first_not_of(ci) == wReturn.find_first_not_of(wReturn)){
            continue;
        }
        else{
            temp.push_back(wReturn);
        }
    }
    std::fstream myData;
    myData.open("data/myPhoneData.txt", std::ios::out | std::ios::app);

    if (myData.is_open()) {
        for(auto const& entry : temp) {
            myData << entry << std::endl;
        }
        myData.close();
        system("clear");
    } else {
        std::cerr << "Error: Could not open the file.\n";
    }

}