#include "addNumber.h"
#include "datatree.h"
#include <iostream>
#include <fstream>
#include <string>

void addNumber() {
    std::string entry_name;
    std::string entry_num;
    std::fstream myData;
    system("clear");
    std::cout << "Enter your new contact name:\n";
    std::getline(std::cin, entry_name);
    if(entry_name.empty()|| entry_name.find_first_not_of(' ') == std::string::npos) {
        system("clear");
        std::cout << "Name cannot be empty. \nPlease try again.\n";
        return;
    }

    std::cout << "Enter your new contact number \n(must be 18 digits or less):\n";
    std::cin >> entry_num;
    if (entry_num.size() > 18) {
        std::cout << "You entered more than 18 digits. \nPlease try again.\n";
        // No recursive call to avoid stack issues, let the user choose again from the menu.
        return;
    }

    // Insert into data tree
        std::string entry_check = entry_name + " | " + entry_num;
        Manage_Data_Tree.To_insert(entry_check);
        system("clear");
        std::cout << "Contact (" << entry_name << " | " <<entry_num << ") added successfully.\n";
    // entry added to data tree, no need to write to file.   

    // myData.open("data/myPhoneData.txt", std::ios::out | std::ios::app);
    // if (myData.is_open()) {
    //     myData << entry_name << " | " << entry_num << std::endl;
    //     myData.close();
    //     system("clear");
    //     std::cout << "Contact (" << entry_name << " | " <<entry_num << ") added successfully.\n";
    // } else {
    //     std::cerr << "Error: Could not open the file.\n";
    // }
}
