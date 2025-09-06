#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void DeleteContact(std::string ci) {
    // Functionality to delete a specific contact can be implemented here.
    // This is a placeholder for future development.
    std::vector<std::string> temp;
    std::fstream reading("data/myPhoneData.txt");
    std::string wReturn;
    while (std::getline(reading, wReturn)) {
        if(ci.find_first_not_of() == getline(reading, wReturn)) {
            continue;
        }
        else{
            temp.push_back(wReturn);
        }
}
}