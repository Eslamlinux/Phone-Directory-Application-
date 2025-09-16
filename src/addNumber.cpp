#include "header/addNumber.h"
#include "header/datatree.h"
#include "header/The_counter.h"
#include "header/colors.h"
#include <iostream>
#include <fstream>
#include <string>

void addNumber() {
    std::string entry_name;
    std::string entry_num;

    system("clear");
    std::cout << Colors.bold_white << Colors.bold_green_bg << "\n🔗 Enter your new contact name:\n" <<Colors.reset;
    std::getline(std::cin, entry_name);
    if(entry_name.empty()|| entry_name.find_first_not_of(' ') == std::string::npos) {
        system("clear");
        std::cout << Colors.bold_red << "Name cannot be empty. \nPlease try again.\n" << Colors.reset;
        return;
    }

    std::cout << Colors.bold_white << Colors.bold_green_bg << "\n🔗 Enter your new contact number \n(must be 18 digits or less):\n" << Colors.reset;
    std::cin >> entry_num;
    if (entry_num.size() > 18) {
        std::cout <<Colors.bold_red << "You entered more than 18 digits. \nPlease try again.\n" << Colors.reset;
        // No recursive call to avoid stack issues, let the user choose again from the menu.
        return;
    }

    CountResult.Count_changes++; // Increment changes count
    CountResult.Count_new_contact++; // Increment new contact count
    CountResult.Count_not_saved++;
    CountResult.curentCount = (CountResult.Count_Data - CountResult.Count_deleted) + CountResult.Count_new_contact; // Update current count
   
    // Insert into data tree
   
        std::string entry_check = entry_name + ": 📞 " + entry_num +"\n";
        if(Manage_Data_Tree.root->data ==""){
            Manage_Data_Tree.Delete_Contact("");
        }



        Manage_Data_Tree.To_insert(entry_check);
        system("clear");
        std::cout <<Colors.bold_white << Colors.bold_green_bg <<  "Contact "<< Colors.reset  << Colors.blue << "("  << entry_name << " | " << Colors.red <<entry_num <<  ")" << Colors.bold_white << Colors.bold_green_bg <<"  added successfully.\n"<< Colors.reset;

}
