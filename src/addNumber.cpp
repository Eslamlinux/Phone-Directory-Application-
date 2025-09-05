#include "addNumber.h"
#include <iostream>
#include <fstream>
#include <string>

void addNumber() {
    std::string entry_name;
    std::string entry_num;
    std::fstream myData;

    std::cout << "Enter your new contact name:\n";
    std::getline(std::cin, entry_name);

    std::cout << "Enter your new contact number (must be 18 digits or less):\n";
    std::cin >> entry_num;

    if (entry_num.size() > 18) {
        std::cout << "You entered more than 18 digits. Please try again.\n";
        // No recursive call to avoid stack issues, let the user choose again from the menu.
        return;
    }

    myData.open("data/myPhoneData.txt", std::ios::out | std::ios::app);

    if (myData.is_open()) {
        myData << entry_name << " | " << entry_num << std::endl;
        myData.close();
        std::cout << "Contact added successfully.\n";
    } else {
        std::cerr << "Error: Could not open the file.\n";
    }
}
