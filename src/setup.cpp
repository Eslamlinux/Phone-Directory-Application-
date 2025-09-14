#include <iostream>
#include <fstream>
#include <string>
#include <limits> 
#include "setup.h"
#include "addNumber.h"
#include "readList.h"
#include "deleteAllContacts.h"
#include "datatree.h"
#include <The_counter.h>


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
         std::cout << "1: To add new contact      press[1]\n";
         std::cout << "2: To see all contacts     press[2]\n";
         std::cout << "3: Total contact           press[3]\n";
         std::cout << "4: Delete one contact      press[4]\n";
         std::cout << "5: To delete all contacts  press[D]\n";
         std::cout << "6: To see Total changes    press[T]\n";
         std::cout << "7: Save last changes       press[S]\n";
         std::cout << "8: To search contact       press[F]\n";
         std::cout << "9: To exit                 press[Q]\n";
        //  std::cout << "0: Maxmum                  press[m]\n";
        //  std::cout << "9: Main                    press[n]\n";
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
                    std::cout << "Are you sure you want to delete all (" << User_entry << ") data? Press 'Y' to continue or 'N' to ignore. \n";
                    std::cin >> chose;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if(chose == 'y' || chose == 'Y'){

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
            case '5':
            case 'D':
            case 'd':
                system("clear");
                deleteAllContacts();
                break;

            case '6':
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
                std::cout << "Total deletions Numbers made during the session: " << CountResult.Count_all_deleted << std::endl;
                std::cout << "Total new contacts added during the session: " << CountResult.Count_new_contact << std::endl;
                std::cout << "Total deletions (all) made during the session: " << CountResult.Count_all_deleted << std::endl;
                // std::cout << "Total changes saved to the file: " << CountResult.Count_saved << std::endl;
                break;

            case '7':
            case 's':
            case 'S':
            CountResult.Count_saved = CountResult.Count_changes; // count of changes saved to the file
            CountResult.Count_not_saved = 0; // count of changes not yet saved to the file
            CountResult.Count_all_deleted += CountResult.Count_deleted;; // count of all deletions
            CountResult.Count_deleted = 0; // count of deletions made during the session
            system("clear");
            std::cout << "All changes have been saved successfully.\n";
            break;

            case '8':
            case 'f':
            case 'F':
                {
                    std::string To_search;
                    system("clear");
                    std::cout << "أدخل اسم جهة الاتصال للبحث عنه (أو جزء من الاسم):\n";
                    std::cout << "Enter the contact name to search for (or part of the name):\n";
                    getline(std::cin, To_search);
                    if(To_search.empty()|| To_search.find_first_not_of(' ') == std::string::npos) {
                        system("clear");
                        std::cout << "الاسم لا يمكن أن يكون فارغاً. حاول مرة أخرى.\n";
                        std::cout << "Name cannot be empty. Please try again.\n";
                        break;
                    }
                    system("clear");
                    // استخدام الدالة الجديدة التي تطبع جميع النتائج المتشابهة
                    Manage_Data_Tree.SearchAndPrintAll(To_search);
                }
                break;
            // case '0':
            // case 'M':
            // case 'm':
            //     {
            //         system("clear");
            //         if(Manage_Data_Tree.isEmpty(Manage_Data_Tree.root))  // Check if the tree is empty{
            //         { 
            //         system("clear");
            //             std::cout << "The directory is empty.\n";
            //             break;
            //         }
            //         else{
            //         system("clear");
            //         Node* maxNode = Manage_Data_Tree.MaxmumData();
            //         if(maxNode) {
            //             std::cout << "Maximum contact (based on lexicographical order): " << maxNode->data << std::endl;
            //         } else {
            //             std::cout << "The directory is empty.\n";
            //         }
            //         }
            //     }
            //     break;
            // case '9':
            // case 'N':
            // case 'n':
            //     system("clear");
            //     {
            //         if(Manage_Data_Tree.isEmpty(Manage_Data_Tree.root))  // Check if the tree is empty{
            //         { 
            //         system("clear");
            //             std::cout << "The directory is empty.\n";
            //             break;
            //     }
            //     else{
            //         system("clear");
            //         Node* minNode = Manage_Data_Tree.MiniData();
            //         if(minNode) {
            //             std::cout << "Minimum contact (based on lexicographical order): " << minNode->data << std::endl;
            //         } else {
            //             std::cout << "The directory is empty.\n";
            //         }
            //     }
            //     }
            //     break;

            case '9':
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
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}