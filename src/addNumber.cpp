#include "addNumber.h"
#include "datatree.h"
#include "The_counter.h"
#include "colors.h"
#include <iostream>
#include <fstream>
#include <string>

void addNumber() {
    std::string entry_name;
    std::string entry_num;
    std::fstream myData;
    system("clear");
    std::cout << Colors.bold_green << Colors.bold_white_bg << "\n🔗 Enter your new contact name:\n" <<Colors.reset;
    std::getline(std::cin, entry_name);
    if(entry_name.empty()|| entry_name.find_first_not_of(' ') == std::string::npos) {
        system("clear");
        std::cout << "Name cannot be empty. \nPlease try again.\n";
        return;
    }

    std::cout << Colors.bold_green << Colors.bold_white_bg << "\n🔗 Enter your new contact number \n(must be 18 digits or less):\n" << Colors.reset;
    std::cin >> entry_num;
    if (entry_num.size() > 18) {
        std::cout << "You entered more than 18 digits. \nPlease try again.\n";
        // No recursive call to avoid stack issues, let the user choose again from the menu.
        return;
    }

    CountResult.Count_changes++; // Increment changes count
    CountResult.Count_new_contact++; // Increment new contact count
    CountResult.curentCount = (CountResult.Count_Data - CountResult.Count_deleted) + CountResult.Count_new_contact; // Update current count
   
    // Insert into data tree
        std::string entry_check = entry_name + ": 📞 " + entry_num +"\n";
        if(Manage_Data_Tree.root->data ==""){
            Manage_Data_Tree.Delete_Contact("");
        }
        Manage_Data_Tree.To_insert(entry_check);
        system("clear");
        std::cout << "Contact (" << entry_name << " | " <<entry_num << ") added successfully.\n";

}
