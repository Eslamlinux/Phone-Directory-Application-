#include "setup.h"
#include "addNumber.h"
#include "readList.h"
#include "deleteAllContacts.h"
#include <iostream>
#include <string>

using namespace std;

void setup() {
    char chose = ' ';
    cout << "Welcome to your phone directory book\n";
    while (chose != 'q' && chose != 'Q') {
        cout << "\n--------------------------------------------\n";
        cout << "1: To add new contact press 1\n";
        cout << "2: To see all contacts press 2\n";
        cout << "3: To delete all contacts press D\n";
        cout << "4: To exit press Q\n";
        cout << "--------------------------------------------\n";
        cout << "Your choice: ";
        cin >> chose;
        cin.ignore(); // To consume the newline character

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
                cout << "Goodbye!\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}