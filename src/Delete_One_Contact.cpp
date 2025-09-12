#include "Delete_One_Contact.h"
#include <limits>

void Delete_One_Contact(std::string User_entry) {
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
                    std::cout << "Are you sure you want to delete all (" << User_entry << ") data? Press 'Y' to continue or 'N' to ignore. \n";
                    std::cin >> chose;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if(chose == 'y' || chose == 'Y'){
                        // DeleteContact(ci);
                        Manage_Data_Tree.Delete_Contact(Manage_Data_Tree.root, User_entry);
                        system("clear");
                        std::cout << "If the contact existed, it has been deleted.\n";
                    }
                    else{
                        system("clear");
                        std::cout << "Operation cancelled. No contacts were deleted.\n";
                        return;
                    }
                }