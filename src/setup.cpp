#include <iostream>
#include <fstream>
#include <string>
#include <limits> 
#include "setup.h"
#include "addNumber.h"
#include "readList.h"
#include "deleteAllContacts.h"
#include "deletecontact.h"
#include "datatree.h"


int safebreak = 1;
void setup() {
    char chose = ' ';
    system("clear");
    std::cout << "Welcome to your phone directory book";
    while (chose != 'q' && chose != 'Q') {

        if(Manage_Data_Tree.isEmpty(Manage_Data_Tree.root))  // Load existing contacts into the binary tree
        {
            std::ifstream file;
            file.open("data/myPhoneData.txt", std::ios::app);
            std::string line ="";
            while(std::getline(file, line)) {    
            Manage_Data_Tree.To_insert(line + "\n"); // Insert each line into the binary tree
            }
        file.close();
        }
    // End of loading contacts into the binary tree


         chose = ' ';
         if(safebreak > 100) {
            system("clear");
            std::cout << "\nyou reached the maximum use \n ot there some problem because you enter wrong choice...\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
         }
         safebreak++;
         std::cout << "\n--------------------------------------------\n";
         std::cout << "1: To add new contact      press[1]\n";
         std::cout << "2: To see all contacts     press[2]\n";
         std::cout << "3: Total contact           press[3]\n";
         std::cout << "4: Delete one contact      press[4]\n";
         std::cout << "5: To delete all contacts  press[D]\n";
         std::cout << "6: Save last changes       press[S]\n";
         std::cout << "7: To search contact       press[F]\n";
         std::cout << "8: To exit                 press[Q]\n";
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
                std::cout << "Total contacts: " << countsize() - 1 << std::endl; //
                break;
            case '4':
                {
                    std::string ci;
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
                    getline(std::cin, ci);
                    if(ci.empty()|| ci.find_first_not_of(' ') == std::string::npos) {
                        system("clear");
                        std::cout << "Name cannot be empty. \nPlease try again.\n";
                        break;
                    }
                    system("clear");
                    std::cout << "Are you sure you want to delete all (" << ci << ") data? Press 'Y' to continue or 'N' to ignore. \n";
                    std::cin >> chose;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if(chose == 'y' || chose == 'Y'){
                        DeleteContact(ci);
                        system("clear");
                        std::cout << "If the contact existed, it has been deleted.\n";
                    }
                    else{
                        system("clear");
                        std::cout << "Operation cancelled. No contacts were deleted.\n";
                        break;
                    }
                }
                break;
            case '5':
            case 'D':
            case 'd':
                system("clear");
                deleteAllContacts();
                break;

            case '6':
            case 's':
            case 'S':
            Manage_Data_Tree.SaveToFile();
            system("clear");
            std::cout << "All changes have been saved successfully.\n";
            break;

            case '7':
            case 'f':
            case 'F':
                {
                    std::string ci;
                    system("clear");
                    std::cout << "Enter the exact name of the contact to search:\n";
                    getline(std::cin, ci);
                    if(ci.empty()|| ci.find_first_not_of(' ') == std::string::npos) {
                        system("clear");
                        std::cout << "Name cannot be empty. \nPlease try again.\n";
                        break;
                    }
                    std::string result = Manage_Data_Tree.SearchInTree(ci);
                    system("clear");
                    std::cout << result << std::endl;
                }
                break;
            case '8':
            case 'q':
            case 'Q':
                system("clear");
                std::cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n" ;
                std::cout << "|*| Thank you for using our Phone Directory Console App.    |*|\n";   
                std::cout << "|*| Goodbye !                                               |*| \n";
                std::cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n" ;
                Manage_Data_Tree.SaveToFile();
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}