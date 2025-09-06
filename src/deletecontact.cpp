#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void DeleteContact(std::string ci) {
    std::vector<std::string> temp;
    std::ifstream reading("data/myPhoneData.txt");
    std::string line;

    if (!reading.is_open()) {
        std::cerr << "Error: Could not open the file for reading.\n";
        return;
    }

    // Read all lines from the file, but skip the one to be deleted.
    while (std::getline(reading, line)) {
        // Find 'ci' as a substring in 'line'. If not found, keep the line.
        if (line.find(ci) == std::string::npos) {
            temp.push_back(line);
        }
    }
    reading.close();

    // Open the file in truncation mode to overwrite it.
    std::ofstream myData("data/myPhoneData.txt", std::ios::out | std::ios::trunc);

    if (myData.is_open()) {
        for (const auto& entry : temp) {
            myData << entry << std::endl;
        }
        myData.close();
        system("clear");
    } else {
        std::cerr << "Error: Could not open the file for writing.\n";
    }
}