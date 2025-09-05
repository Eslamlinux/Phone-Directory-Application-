#include <main.h>
void setup(){
    char chose = ' ';
    cout << "Welcome to your phone directory book\n";
        while(chose != 'q' && chose != 'Q'){
        cout << "\n--------------------------------------------\n";
        cout << "To add new contact press 1\n";
        cout << "To see all contacts press 2\n";
        cout << "To delete all contacts press D\n";
        cout << "To exit press Q\n";
        cout << "--------------------------------------------\n";
        cout << "Your choice: ";
        cin >> chose;
        cin.ignore();
    switch(chose){
        case '1':
        addNumber();
        break;
        case '2':
        readList();
        break;
        case 'D':
        case 'd':{
        do{
        cout << "Are you sure you want to delete all your contacts? If so, press Y or I fo ignore.\n";
        cin >> chose;
        if(chose == 'y'||chose == 'Y'){
            ofstream myData("myPhoneData.txt");
            cout << "All contacts have been deleted.\n";
            break;
        }
        else if(chose == 'I'||chose == 'i'){
            break;
        }
        else{
            cout << "wrong choice\n";
        }
        }while(chose != 'q');
        }
        break;
        case 'q':
        case 'Q':
        cout << "Goodbye!\n";
        return;
        default:
        cout << "Invalid choice. Please try again.\n";
        break;
}
}
}