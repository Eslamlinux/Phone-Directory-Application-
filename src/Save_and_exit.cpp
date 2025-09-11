#include "datatree.h"
#include <iostream>
#include <fstream>

void save_and_exit() {
    // Save the current state of the binary tree to the file
    std::ofstream file("data/myPhoneData.txt", std::ios::trunc);
    if (file.is_open()) {
        file << Manage_Data_Tree.print_preorder(Manage_Data_Tree.root);
        file.close();
        std::cout << "Contacts saved successfully. Exiting...\n";
    } else {
        std::cerr << "Error: Could not open the file for saving.\n";
    }
}