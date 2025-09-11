#include "readList.h"
#include "datatree.h"
#include <iostream>
#include <fstream>
#include <string>
int counter = 1;
void readList() {


    // ############################
    std::cout << "starting readList function frome tree \n"; // 
    Manage_Data_Tree.print_preorder(Manage_Data_Tree.root);
    std::cout << "end of readList function frome tree \n"; //
    // ############################


    std::string wReturn;
    std::fstream reading("data/myPhoneData.txt");
    if (reading.is_open()) {
        if (reading.peek() == std::fstream::traits_type::eof()) {
            system("clear");
            std::cout << "The directory is empty.\n";
        } else {
            system("clear");
            std::cout << "----------------------\n";
            std::cout << "-- Phone  Contacts: --\n";
            std::cout << "----------------------\n";
            std::cout << "   Name  |   Number  :\n";
            std::cout << "----------------------\n";
            counter = 1;
            while (std::getline(reading, wReturn)) {
                std::cout << counter << ": " << wReturn << std::endl;
                counter++;
            }
            reading.close();
        }
    } else {
        std::cerr << "Error: Could not open the file for reading.\n";
    }
}
int countsize() {
    std::fstream reading("data/myPhoneData.txt");
    std::string wReturn;
    counter = 1; // Reset counter to 1 each time countsize is called
    while (std::getline(reading, wReturn)) {
            
                counter++;
            }
    return counter;
}