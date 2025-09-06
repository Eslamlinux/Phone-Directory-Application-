#include "deleteAllContacts.h"
#include <iostream>
#include <fstream>
#include <string>

void deleteAllContacts() {
    char chose;
    system("clear");
    std::cout << "Are you sure you want to delete all your contacts? \nIf so, press Y or N to ignore.\n";
    std::cin >> chose;
    if (chose == 'y' || chose == 'Y') {
        std::ofstream myData("data/myPhoneData.txt"); // Opens in truncation mode
        std::cout << "All contacts have been deleted.\n";
    } else {
        system("clear");
        std::cout << "Operation cancelled.\n";
    }
}
