#include "header/deleteAllContacts.h"
#include "header/datatree.h"
#include "header/colors.h"
#include <header/The_counter.h>
#include <iostream>
#include <fstream>
#include <string>

void deleteAllContacts() {
    char chose;
    system("clear");
    std::cout <<Colors.bold_green_bg << Colors.white << "Are you sure you want to delete all your contacts? \nIf so, press Y or N to ignore.\n" <<Colors.reset;
    std::cin >> chose;
    if (chose == 'y' || chose == 'Y') {
        CountResult.Count_all_deleted = CountResult.curentCount ; // all deleted count
        Manage_Data_Tree.Delete_All_Contacts();
        Manage_Data_Tree.To_insert(""); // To handle the case when the tree becomes empty
        CountResult.Count_changes++; // increment changes count
        CountResult.Count_deleted += CountResult.Count_all_deleted; // Increment deleted count
        CountResult.curentCount = 0; // Update current count to zero
        CountResult.Count_not_saved++;
        system("clear");
        std::cout << "All contacts have been deleted.\n";
    } else {
        system("clear");
        std::cout << "Operation cancelled.\n";
    }
}
