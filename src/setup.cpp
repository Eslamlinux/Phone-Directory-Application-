#include "setup.h"
#include "addNumber.h"
#include "readList.h"
#include "deleteAllContacts.h"
#include "deletecontact.h"
#include <iostream>
#include <string>
#include <limits> 
using namespace std;
int safebreak = 1;
void setup() {
    char chose = ' ';
    system("clear");
    cout << "Welcome to your phone directory book";
    while (chose != 'q' && chose != 'Q') {
         chose = ' ';
         if(safebreak > 100) {
            system("clear");
            cout << "\nyou reached the maximum use \n ot there some problem because you enter wrong choice...\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
         }
         safebreak++;
         cout << "\n--------------------------------------------\n";
         cout << "1: To add new contact press    [1]\n";
         cout << "2: To see all contacts press   [2]\n";
         cout << "3: contact total numbers press [3]\n";
         cout << "4: Delete one contact press    [4]\n";
         cout << "5: To delete all contacts press[D]\n";
         cout << "6: To exit press               [Q]\n";
         cout << "--------------------------------------------\n";
         cout << "Your choice: ";
         cin >> chose;
        
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (chose) {
            case '1':
                addNumber();
                break;
            case '2':
                readList();
                break;
            case '3':
                    system("clear");
                cout << "Total contacts: " << countsize() - 1 << endl; //
                break;
            case '4':
                {
                    string ci;
                    system("clear");
                    cout << "Be careful with that. You must add the contact name in the same way as before,\n" ;
                    cout << "because if there are other names that start with the same name that you enter,\n";
                    cout << "you will delete them all.\n";
                    cout << "also if you add first character of the name and ther is another you will delete it too.\n";
                    cout << "Enter the exact name of the contact to delete:\n";
                    getline(cin, ci);
                    if(ci.empty()|| ci.find_first_not_of(' ') == std::string::npos) {
                        system("clear");
                        cout << "Name cannot be empty. \nPlease try again.\n";
                        break;
                    }
                    DeleteContact(ci);
                    system("clear");
                    cout << "If the contact existed, it has been deleted.\n";
                }
                break;
            case '5':
            case 'D':
            case 'd':
                system("clear");
                deleteAllContacts();
                break;
            case '6':
            case 'q':
            case 'Q':
                system("clear");
                cout << "Thank you for using our Phone Directory Console App.\nGoodbye!\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}