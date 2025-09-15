#include <iostream>
#include <fstream>
#include <string>
#include <limits> 
#include <The_counter.h>
#include "colors.h"
#include "setup.h"
#include "addNumber.h"
#include "readList.h"
#include "deleteAllContacts.h"
#include "datatree.h"
#include "exportdata.h"


long int Count_Data = 0;
int safebreak = 1;
void setup() {
    char chose = ' ';
    system("clear");
    std::cout << "Welcome to your phone directory book";
    while (chose != 'q' && chose != 'Q') {

         if(safebreak > 100) {
            system("clear");
            std::cout << "\nyou reached the maximum use \n ot there some problem because you enter wrong choice...\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
         }
         safebreak++;

        if(Manage_Data_Tree.isEmpty(Manage_Data_Tree.root))  // Load existing contacts into the binary tree
        {
            std::ifstream file;
            file.open("data/myPhoneData.txt", std::ios::in);
            std::string line ="";
            while(std::getline(file, line)) {   
                if(!line.empty()) // Avoid inserting empty lines
                {
                    Manage_Data_Tree.To_insert(line + "\n"); // Insert each line into the binary tree
                    Count_Data++;
                }
                CountResult.Count_Data = Count_Data;
            }
        file.close();
        }
    // End of loading contacts into the binary tree

         chose = ' ';
         std::cout << "\n--------------------------------------------\n";
         std::cout << Colors.bold_yellow_bg <<Colors.bold_red << "\t📞 Phone Directory Menu 📞" <<Colors.reset;
         std::cout << "\n--------------------------------------------\n";
         std::cout << "1: "<< Colors.blue<< "🔗 add new contact         "<< Colors.bold_green<< "press[1]\n"<<Colors.reset;
         std::cout << "2: "<< Colors.blue<<"🧐 To see all contacts     "<< Colors.bold_green<< "press[2]\n"<<Colors.reset;
         std::cout << "3: "<< Colors.blue<<"📇 Total contact           "<< Colors.bold_green<< "press[3]\n"<<Colors.reset;
         std::cout << "4: "<< Colors.blue<<"🗑️  Delete contacts         "<< Colors.bold_green<< "press[D]\n"<<Colors.reset;
         std::cout << "5: "<< Colors.blue<<"📤  Export Data            "<< Colors.bold_green<< "press[E]\n"<<Colors.reset;
         std::cout << "6: "<< Colors.blue<<"🧹 ignore the changes      "<< Colors.bold_green<< "press[I]\n"<<Colors.reset;
         std::cout << "7: "<< Colors.blue<<"📊 To see Total changes    "<< Colors.bold_green<< "press[T]\n"<<Colors.reset;
         std::cout << "8: "<< Colors.blue<<"💾 Save last changes       "<< Colors.bold_green<< "press[S]\n"<<Colors.reset;
         std::cout << "9: "<< Colors.blue<<"🔍 To search contact       "<< Colors.bold_green<< "press[F]\n"<<Colors.reset;
         std::cout << "0: "<< Colors.blue<<"⏻  To exit                 "<< Colors.bold_green<< "press[Q]\n"<<Colors.reset;

         std::cout << "--------------------------------------------\n";
         std::cout << "Your choice: ";
         std::cin >> chose;
        
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                std::cout << "Total contacts: " << CountResult.curentCount << std::endl; //
                break;
            case '4':
            case 'D':
            case 'd':
            system("clear");
                std::cout << "Choose delete mode:\n";
                std::cout << "for delete one contact press [1]\n";
                std::cout << "for delete all contacts press [2]\n";
                std::cout << "Your choice: ";
                char deleteChoice;
                std::cin >> deleteChoice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if(deleteChoice != '1' && deleteChoice != '2') {
                    system("clear");
                    std::cout << "Invalid choice. Returning to main menu.\n";
                    break;
                }
            switch(deleteChoice) {
            case '1':
                {
                    std::string User_entry;
                    system("clear");
                    std::cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n";
                    std::cout << "|*| *** Be careful with that. ***                             |*|\n";
                    std::cout << "|*| You must add the contact name in the same way as before,  |*|\n" ;
                    std::cout << "|*| because if there are other names that start with the      |*|\n";
                    std::cout << "|*| same name that you enter, you will delete them all.       |*|\n";
                    std::cout << "|*| also if you add first character of the name and ther      |*|\n"; 
                    std::cout << "|*| is another you will delete it too                         |*|\n";
                    std::cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n";
                    std::cout << "\nEnter the exact name of the contact to delete:\n";
                    std::getline(std::cin, User_entry);
                    if(User_entry.empty()|| User_entry.find_first_not_of(' ') == std::string::npos) {
                        system("clear");
                        std::cout << "Name cannot be empty. \nPlease try again.\n";
                        return;
                    }
                    system("clear");
                    std::cout << "Are you sure you want to delete (" << User_entry << ") data? Press 'Y' to continue or 'N' to ignore. \n";
                    std::cin >> deleteChoice;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if(deleteChoice == 'y' || deleteChoice == 'Y'){

                        CountResult.Count_changes++; // Decrement changes count
                        CountResult.Count_deleted++; // Increment deleted count
                        CountResult.curentCount = (CountResult.Count_Data - CountResult.Count_deleted) + CountResult.Count_new_contact; // Update current count


                        Manage_Data_Tree.Delete_Contact(Manage_Data_Tree.root, User_entry);
                        Manage_Data_Tree.To_insert(""); // To handle the case when the tree becomes empty

                        system("clear");
                        std::cout <<  "Contact deleted successfully.\n";
                    }
                    else{
                        system("clear");
                        std::cout << "Operation cancelled. No contacts were deleted.\n";
                        return;
                    }
                }
                break;
            case '2':    
                {
                    system("clear");
                    std::cout << "Are you sure you want to delete all contacts? Press 'Y' to continue or 'N' to ignore. \n";
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
                        std::cout <<  "All contacts deleted successfully.\n";
                    }
                    else{
                        system("clear");
                        std::cout << "Operation cancelled. No contacts were deleted.\n";
                        return;
                    }
                }
                }
                
                break;

            case '6':
            case 'I':
            case 'i':
                system("clear");
                std::cout << "you've ignored all the changes you made in this session.\n";
                CountResult.Count_changes = 0; // count of changes made during the session
                CountResult.Count_new_contact = 0; // count of new contacts added during the session
                CountResult.Count_deleted = 0; // count of deletions made during the session
                CountResult.Count_not_saved = 0; // count of changes not yet saved to the file
                CountResult.Count_all_deleted = 0; // count of all deletions 
                Manage_Data_Tree.Delete_All_Contacts();
                Manage_Data_Tree.To_insert(""); // To handle the case when the tree becomes empty
                CountResult.curentCount = CountResult.Count_Data; // Update current count to the original count
                // Reload original data from file
                {
                    std::ifstream file;
                    file.open("data/myPhoneData.txt", std::ios::in);
                    std::string line ="";
                    while(std::getline(file, line)) {   
                        if(!line.empty()) // Avoid inserting empty lines
                        {
                            Manage_Data_Tree.To_insert(line + "\n"); // Insert each line into the binary tree
                        }
                    }
                    file.close();
                }
                std::cout << "All changes have been ignored.\n";

                break;

            case '7':
            case 't':
            case 'T':
                system("clear");
                CountResult.curentCount = (CountResult.Count_Data - CountResult.Count_deleted) + CountResult.Count_new_contact; // Update current count
                CountResult.Count_not_saved = CountResult.Count_deleted + CountResult.Count_new_contact;
                CountResult.Count_all_deleted =  CountResult.Count_all_deleted + CountResult.Count_deleted;
                std::cout << "Total contacts loaded from Data during start the program: " << CountResult.Count_Data << std::endl;
                std::cout << "Total contacts currently in the directory after changes: " << CountResult.curentCount << std::endl;
                std::cout << "Total changes not yet saved to the Data file: " << CountResult.Count_not_saved << std::endl;
                std::cout << std::endl;
                std::cout << "Total changes made during the session: " << CountResult.Count_changes << std::endl;
                std::cout << "Total new contacts added during the session: " << CountResult.Count_new_contact << std::endl;
                std::cout << "Total deletions (all) made during the session: " << CountResult.Count_all_deleted << std::endl;
                // std::cout << "Total changes saved to the file: " << CountResult.Count_saved << std::endl;
                break;

            case '8':
            case 's':
            case 'S':
            CountResult.Count_saved = CountResult.Count_changes; // count of changes saved to the file
            CountResult.Count_not_saved = 0; // count of changes not yet saved to the file
            CountResult.Count_all_deleted += CountResult.Count_deleted;; // count of all deletions
            CountResult.Count_deleted = 0; // count of deletions made during the session
            system("clear");
            Manage_Data_Tree.SaveToFile();
            std::cout << "All changes have been saved successfully.\n";
            break;

            case '9':
            case 'f':
            case 'F':
            system("clear");
            std::cout << "Choose search mode:\n";
            std::cout << "1: Search and matching all contacts (press [1])\n";
            std::cout << "2: Search for exact contact (press [2])\n";
            std::cout << "Your choice: ";
            char searchChoice;
            std::cin >> searchChoice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if(searchChoice != '1' && searchChoice != '2') {
                system("clear");
                std::cout << "Invalid choice. Returning to main menu.\n";
                break;
            }
            switch(searchChoice) {
                case '1':   
                    {
                        std::string To_search;
                        system("clear");
                        std::cout << "Enter the name or part of the name to search:\n";
                        getline(std::cin, To_search);
                        if(To_search.empty()|| To_search.find_first_not_of(' ') == std::string::npos) {
                            system("clear");
                            std::cout << "Name cannot be empty. \nPlease try again.\n";
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
                    std::cout << "Enter the exact name of the contact to search:\n";
                    getline(std::cin, To_search);
                    if(To_search.empty()|| To_search.find_first_not_of(' ') == std::string::npos) {
                        system("clear");
                        std::cout << "Name cannot be empty. \nPlease try again.\n";
                        break;
                    }
                    std::string result = Manage_Data_Tree.SearchInsideTree(To_search);
                    system("clear");
                    std::cout << "\n--------------------------------------------\n";
                    std::cout << "Search for: " << To_search << std::endl;   
                    std::cout << "Result found:" << std::endl;     
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
                
                std::cout << "Do you want save the changes ? 'Y' for save 'N' for Ignore it\n" ;
                std::cin >> chose;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if(chose == 'y' || chose == 'Y'){
                std::cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n" ;
                std::cout << "|*| Thank you for using our Phone Directory Console App.    |*|\n";   
                std::cout << "|*| All your changes are saved :)                           |*| \n";
                std::cout << "|*| Goodbye !                                               |*| \n";
                std::cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n" ;
                Manage_Data_Tree.SaveToFile();
                }
                else if(chose == 'n' || chose == 'N'){
                {
                std::cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n" ;
                std::cout << "|*| Thank you for using our Phone Directory Console App.    |*|\n";   
                std::cout << "|*| All your changes are ignored :(                         |*| \n";
                std::cout << "|*| Goodbye !                                               |*| \n";
                std::cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n" ;
                }
                }
                else{
                    std::cout << "Invalid choice. Returning to main menu.\n";
                    break;
                }
                return;
                case '5':
                case 'E':
                case 'e':
                To_Export();
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;

        }
    }
}