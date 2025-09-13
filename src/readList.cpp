#include "readList.h"
#include "datatree.h"
#include <The_counter.h>
#include <iostream>
#include <fstream>
#include <string>
// int counter = 1;


void readList() {

    // ############################
                if(Manage_Data_Tree.isEmpty(Manage_Data_Tree.root) || Manage_Data_Tree.root->data =="")  // Check if the tree is empty
                { 
                    system("clear");
                    std::cout << "The directory is empty.\n";
                    return;
                }
    else if(Manage_Data_Tree.root != nullptr)    {
        system("clear");
        CountResult.curentCount = (CountResult.Count_Data + CountResult.Count_new_contact) - CountResult.Count_deleted; // Update current count 
        std::cout << "----------------------\n";
        std::cout << "-- Phone  Contacts: --\n";
        std::cout << "----------------------\n";
        std::cout << "   Name  |   Number  :\n";
        std::cout << "----------------------\n";
        std::cout << "Contact Total: " << CountResult.curentCount << "\n";
    
        Manage_Data_Tree.print_preorder(Manage_Data_Tree.root);
    }
    
    // ############################


//     std::string wReturn;
//     std::fstream reading("data/myPhoneData.txt");
//     if (reading.is_open()) {
//         if (reading.peek() == std::fstream::traits_type::eof()) {
//             system("clear");
//             std::cout << "The directory is empty.\n";
//         } else {
//             system("clear");
//             std::cout << "----------------------\n";
//             std::cout << "-- Phone  Contacts: --\n";
//             std::cout << "----------------------\n";
//             std::cout << "   Name  |   Number  :\n";
//             std::cout << "----------------------\n";
//             counter = 1;
//             while (std::getline(reading, wReturn)) {
//                 std::cout << counter << ": " << wReturn << std::endl;
//                 counter++;
//             }
//             reading.close();
//         }
//     } else {
//         std::cerr << "Error: Could not open the file for reading.\n";
//     }
}
// int countsize() {
//     std::fstream reading("data/myPhoneData.txt");
//     std::string wReturn;
//     counter = 1; // Reset counter to 1 each time countsize is called
//     while (std::getline(reading, wReturn)) {
            
//                 counter++;
//             }
//     return counter;
// }
