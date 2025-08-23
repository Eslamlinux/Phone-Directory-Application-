#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void addNumber();
void setup();
void readList();

int main(){
 setup();   
    return 0;
}

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
         string tempchose;
         cout << "are you sure you want delete all data contact ? write 'del' to confirm \n";
         cin >> tempchose;
          if(tempchose == "del"){
        ofstream myData("myPhoneData.txt");
        cout << "All contacts have been deleted.\n";
          }
         break;
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

void addNumber(){
    string entry_name;
    string entry_num;
    fstream myData;
    cout << "enter your new content name\n";
    getline(cin,entry_name);
    cout << "enter your new content number must be less than 18 number only\n";
    cin >> entry_num;
    if(entry_num.size() > 18){
     cout << "you entered more than 18 number try agin\n";
     cin.clear();
     cin.ignore();
     addNumber();
     return;
    }
    myData.open("myPhoneData.txt" , ios::out|ios::app );

    if(myData.is_open()){
    myData << entry_name << " | " << entry_num << endl;
    myData.close();
    }
    else{
        cerr << "Error: Could not open the file.\n"; 
    }

}
void readList(){
    string wReturn;
    fstream reading("myPhoneData.txt");
    if(reading.is_open()){
    if(reading.peek() == fstream::traits_type::eof()){
        cout << "The directory is empty.\n";
    }
    else{
    cout << "---------------------\n";
    cout << "Phone Contacts:\n";
    cout << "Name  |  Number:\n";
    cout << "---------------------\n";
    while ( getline(reading,wReturn) )
    {
        cout << wReturn << endl;
    }
    reading.close();
    }
        }
else{
    cerr << "Error: Could not open the file for reading.\n";

}

}
