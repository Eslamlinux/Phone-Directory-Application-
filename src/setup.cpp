#include "setup.h"
#include "addNumber.h"
#include "readList.h"
#include "deleteAllContacts.h"
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
         cout << "1: To add new contact press 1\n";
         cout << "2: To see all contacts press 2\n";
         cout << "3: To delete all contacts press D\n";
         cout << "4: To exit press Q\n";
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
            case 'D':
            case 'd':
            case '3':
                deleteAllContacts();
                break;
            case 'q':
            case 'Q':
            case '4':
                system("clear");
                cout << "Thank you for using our Phone Directory Console App.\nGoodbye!\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}