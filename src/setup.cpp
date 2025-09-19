#include "header/The_counter.h"
#include "header/colors.h"
#include "header/setup.h"
#include "header/addNumber.h"
#include "header/readList.h"
#include "header/deleteAllContacts.h"
#include "header/datatree.h"
#include "header/exportdata.h"
#include "header/importdatafile.h"
#include "header/menu.h"
#include "header/make_read_data.h"
#include "header/Paths.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits> 
#include <cstdlib>

int safebreak = 1;


void setup() {
    char chose = ' ';
    system("clear");
    std::cout <<Colors.bold_green_bg << Colors.bold_white<<"    Welcome to your phone directory book" << Colors.reset;
    while (chose != 'q' && chose != 'Q') {

         if(safebreak > 100) {
            system("clear");
            std::cout << Colors.bold_red << Colors.bold_green_bg << "\nyou reached the maximum use \n ot there some problem because you enter wrong choice...\n" << Colors.reset;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
         }
         safebreak++;

        Load_Creat_Data();
         
        chose = Start_Menu(chose);

        switch (chose) {
            case '1':
                addNumber();
                break;
            case '2':
                readList();
                break;
            case '3':
                    system("clear");
                CountResult.curentCount = (CountResult.Count_Data - CountResult.Count_deleted) + CountResult.Count_new_contact; // Update current count
                std::cout << Colors.bold_red << Colors.bold_green_bg << "Total contacts: " << CountResult.curentCount << Colors.reset << std::endl; //
                break;
            case '4':
            case 'D':
            case 'd':
            system("clear");
                std::cout << Colors.bold_red << Colors.bold_green_bg << "Choose delete mode:\n" << Colors.reset;
                std::cout << Colors.red << "for delete one contact press [1]\n";
                std::cout << "for delete all contacts press [2]\n" << Colors.reset;
                std::cout << "Your choice: ";
                char deleteChoice;
                std::cin >> deleteChoice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if(deleteChoice != '1' && deleteChoice != '2') {
                    system("clear");
                    std::cout << Colors.bold_red << "Invalid choice. Returning to main menu.\n";
                    break;
                }
            switch(deleteChoice) {
            case '1':
                {
                    std::string User_entry;
                    system("clear");
                    std::cout << Colors.bold_red << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n";
                    std::cout << "|*| "<< Colors.underline << "*** Be careful with that. ***"<< Colors.reset << Colors.bold_red <<"                             |*|\n";
                    std::cout << "|*| " << Colors.green << "You must add the contact name in the same way as before,  " << Colors.red << "|*|\n" ;
                    std::cout << "|*| " << Colors.green << "because if there are other names that start with the      " << Colors.red << "|*|\n";
                    std::cout << "|*| " << Colors.green << "same name that you enter, you will delete them all.       " << Colors.red << "|*|\n";
                    std::cout << "|*| " << Colors.green << "also if you add first character of the name and ther      " << Colors.red << "|*|\n"; 
                    std::cout << "|*| " << Colors.green << "is another you will delete it too                         " << Colors.red << "|*|\n";
                    std::cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n" << Colors.reset;
                    std::cout << "\n" << Colors.bold_blue << "Enter the exact name of the contact to delete:\n" << Colors.reset;
                    std::getline(std::cin, User_entry);
                    if(User_entry.empty()|| User_entry.find_first_not_of(' ') == std::string::npos) {
                        system("clear");
                        std::cout  << Colors.red << "Name cannot be empty. \nPlease try again.\n" << Colors.reset;
                        break;
                    }
                    system("clear");
                    std::cout << Colors.bold_red << Colors.bold_green_bg << "Are you sure you want to delete (" << User_entry << ") data? Press 'Y' to continue or 'N' to ignore. \n" << Colors.reset;
                    std::cin >> deleteChoice;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if(deleteChoice == 'y' || deleteChoice == 'Y'){

                        CountResult.Count_changes++; // Decrement changes count
                        CountResult.Count_deleted++; // Increment deleted count
                        CountResult.Count_not_saved++;
                        CountResult.curentCount = (CountResult.Count_Data - CountResult.Count_deleted) + CountResult.Count_new_contact; // Update current count


                        Manage_Data_Tree.Delete_Contact(Manage_Data_Tree.root, User_entry);
                        Manage_Data_Tree.To_insert(""); // To handle the case when the tree becomes empty

                        system("clear");
                        std::cout << Colors.bold_green <<  "Contact deleted successfully.\n" << Colors.reset;
                    }
                    else{
                        system("clear");
                        std::cout << Colors.red << "Operation cancelled. No contacts were deleted.\n" << Colors.reset;
                        break;
                    }
                }
                break;
            case '2':    
                {
                    system("clear");
                    std::cout << Colors.bold_red << Colors.bold_green_bg << "Are you sure you want to delete all contacts? Press 'Y' to continue or 'N' to ignore. \n" << Colors.reset;
                    std::cin >> deleteChoice;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if(deleteChoice == 'y' || deleteChoice == 'Y'){
                        CountResult.Count_changes += CountResult.Count_new_contact; // Decrement changes count
                        CountResult.Count_deleted += CountResult.Count_new_contact + CountResult.Count_Data; // Increment deleted count
                        CountResult.curentCount = 0; // Update current count
                        Manage_Data_Tree.Delete_All_Contacts();
                        Manage_Data_Tree.root = nullptr;
                        Manage_Data_Tree.To_insert(""); // To handle the case when the tree becomes empty
                        system("clear");
                        std::cout << Colors.bold_green <<  "All contacts deleted successfully.\n" << Colors.reset;
                    }
                    else{
                        system("clear");
                        std::cout << Colors.bold_green << "Operation cancelled. No contacts were deleted.\n" << Colors.reset;
                        break;
                    }
                }
                }
                
                break;

            case '6':
            case 'I':
            case 'i':
            {
                system("clear");
                CountResult.Count_changes = 0; // count of changes made during the session
                CountResult.Count_new_contact = 0; // count of new contacts added during the session
                CountResult.Count_deleted = 0; // count of deletions made during the session
                CountResult.Count_not_saved = 0; // count of changes not yet saved to the file
                CountResult.Count_all_deleted = 0; // count of all deletions 
                Manage_Data_Tree.Delete_All_Contacts();
                Manage_Data_Tree.root = nullptr;
                // Manage_Data_Tree.To_insert(""); // To handle the case when the tree becomes empty
                CountResult.curentCount = CountResult.Count_Data; // Update current count to the original count
                // Reload original data from file
                
                std::cout << Colors.bold_green << "you've ignored all the changes you made in this session.\n"<< Colors.reset;
                    std::ifstream file;
                    std::string dataplace;
                    dataplace = Path();
                    file.open(dataplace, std::ios::in);
                    std::string line ="";
                    while(std::getline(file, line)) {   
                        if(!line.empty()) // Avoid inserting empty lines
                        {
                            Manage_Data_Tree.To_insert(line + "\n"); // Insert each line into the binary tree
                        }
                    }
                    file.close();
                
                std::cout << Colors.bold_red << "All changes have been ignored.\n" <<Colors.reset;
                }
                break;

            case '7':
            case 't':
            case 'T':
                system("clear");
                CountResult.curentCount = (CountResult.Count_Data - CountResult.Count_deleted) + CountResult.Count_new_contact; // Update current count
                // CountResult.Count_not_saved = CountResult.Count_not_saved;
                CountResult.Count_all_deleted =  CountResult.Count_all_deleted + CountResult.Count_deleted;
                std::cout << Colors.bold_blue << "Total contacts loaded from Data during start the program or after save the changes: "<< Colors.bold_red  << CountResult.Count_Data << std::endl;
                std::cout << Colors.bold_blue << "Total contacts currently in the directory after changes: " << Colors.bold_red << CountResult.curentCount << std::endl;
                // std::cout << Colors.bold_blue << "Total changes not yet saved to the Data file: " << Colors.bold_red << CountResult.Count_not_saved << std::endl;
                std::cout << Colors.bold_blue << "Total changes not yet saved to the Data file: " << Colors.bold_red << CountResult.Count_not_saved << std::endl;
                std::cout << std::endl;
                std::cout << Colors.bold_blue << "Total changes made during the session: " << Colors.bold_red << CountResult.Count_changes << std::endl;
                std::cout << Colors.bold_blue << "Total new contacts added during the session: "<< Colors.bold_red << CountResult.Count_new_contact << std::endl;
                std::cout << Colors.bold_blue << "Total deletions (all) made during the session: " << Colors.bold_red << CountResult.Count_all_deleted << std::endl;
                // std::cout << "Total changes saved to the file: " << CountResult.Count_saved << std::endl;
                break;

            case '8':
            case 's':
            case 'S':
            CountResult.Count_saved = CountResult.Count_changes; // count of changes saved to the file
            CountResult.Count_all_deleted += CountResult.Count_deleted;; // count of all deletions
            CountResult.Count_deleted = 0; // count of deletions made during the session
            system("clear");
            Manage_Data_Tree.SaveToFile();
            CountResult.Count_not_saved = 0; // count of changes not yet saved to the file
            std::cout << Colors.bold_red << Colors.bold_green_bg <<  "All changes have been saved successfully.\n" << Colors.reset;
            break;

            case '9':
            case 'f':
            case 'F':
            system("clear");
            std::cout << Colors.bold_red << Colors.bold_green_bg <<  "Choose search mode:\n" << Colors.reset;
            std::cout << Colors.bold_blue << "1: Search and matching all contacts (press [1])\n"<< Colors.reset;
            std::cout << Colors.bold_blue << "2: Search for exact contact (press [2])\n";
            std::cout << "Your choice: ";
            char searchChoice;
            std::cin >> searchChoice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if(searchChoice != '1' && searchChoice != '2') {
                system("clear");
                std::cout << Colors.bold_red << "Invalid choice. Returning to main menu.\n"<< Colors.reset;
                break;
            }
            switch(searchChoice) {
                case '1':   
                    {
                        std::string To_search;
                        system("clear");
                        std::cout << Colors.bold_red << Colors.bold_green_bg << "Enter the name or part of the name to search:\n"<< Colors.reset;
                        getline(std::cin, To_search);
                        if(To_search.empty()|| To_search.find_first_not_of(' ') == std::string::npos) {
                            system("clear");
                            std::cout << Colors.bold_red << "Name cannot be empty. \nPlease try again.\n"<< Colors.reset;
                            break;
                        }
                        system("clear");
                        std::cout << "\n--------------------------------------------\n";
                        Manage_Data_Tree.SearchAndPrintAll(To_search);
                    }
                    break;
                case '2':
                {
                    std::string To_search;
                    system("clear");
                    std::cout << Colors.bold_red << Colors.bold_green_bg << "Enter the exact name of the contact to search:\n"<< Colors.reset;
                    getline(std::cin, To_search);
                    if(To_search.empty()|| To_search.find_first_not_of(' ') == std::string::npos) {
                        system("clear");
                        std::cout << Colors.bold_red << "Name cannot be empty. \nPlease try again.\n"<< Colors.reset;
                        break;
                    }
                    std::string result = Manage_Data_Tree.SearchInsideTree(To_search);
                    system("clear");
                    std::cout << "\n--------------------------------------------\n";
                    std::cout << Colors.bold_blue<< "Search for: " << To_search << std::endl;   
                    std::cout << "Result found:" << Colors.reset << std::endl;     
                    std::cout << "\n--------------------------------------------\n";
                    std::cout << result << std::endl;
                    std::cout << "\n--------------------------------------------\n";

                }
                break;
            }
            break;

            case '0':
            case 'q':
            case 'Q':
                system("clear");
                
                std::cout << Colors.bold_red << Colors.bold_green_bg <<  "Do you want save the changes ? "<< Colors.bold_white << Colors.bold_green_bg << "'Y' for save 'N' for Ignore it\n" << Colors.reset ;
                std::cin >> chose;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if(chose == 'y' || chose == 'Y'){
                std::cout << Colors.bold_red << Colors.bold_green_bg <<  "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n" ;
                std::cout << "|*| Thank you for using our Phone Directory Console App.    |*|\n";   
                std::cout << "|*| All your changes are saved :)                           |*| \n";
                std::cout << "|*| Goodbye !                                               |*| \n";
                std::cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n" << Colors.reset;
                Manage_Data_Tree.SaveToFile();
                }
                else if(chose == 'n' || chose == 'N'){
                {
                std::cout << Colors.bold_red << Colors.bold_red_bg <<  "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n" ;
                std::cout << "|*| Thank you for using our Phone Directory Console App.    |*|\n";   
                std::cout << "|*| All your changes are ignored :(                         |*| \n";
                std::cout << "|*| Goodbye !                                               |*| \n";
                std::cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n" <<Colors.reset ;
                }
                }
                else{
                    std::cout << Colors.bold_red <<  "Invalid choice. Returning to main menu.\n";
                    break;
                }
                return;
                case '5':
                case 'E':
                case 'e':
                system("clear");
                std::cout<< Colors.bold_blue << "If you want to Export Data prees [E] & to import Data prees [I] \n";
                std::cin >> chose;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if(chose == 'e' || chose == 'E'){
                    To_Export();
                }
                else if(chose == 'i' || chose == 'I'){
                    system("clear");
                    std::cout << "this choice will delete old data and replac it with one you enter,,, \nare you sure enter 'Y' for yes and 'N' fo no \n";
                    std::cin>>chose;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if(chose == 'y' || chose == 'Y'){
                    system("clear");
                        Import_Replace_data();
                        std::cout << "Every thing is changed\n";

                    }
                    else if(chose == 'n' || chose == 'N'){
                    system("clear");
                        std::cout << "great you chose to Ignore, no thing is change\n";
                        break;
                    }
                    else{
                    system("clear");
                        std::cout << "you enter wrong choice\n";
                        break;
                    }
                }
                else{
                    system("clear");
                    std::cout << "you enter wrong choice\n";
                    break;
                }
                break;
            default:
                std::cout << Colors.bold_red <<   "Invalid choice. Please try again.\n";
                break;

        }
    }
}