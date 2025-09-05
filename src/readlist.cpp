#include <main.h>

void readList(){
    string wReturn;
    fstream reading("myPhoneData.txt");
    if(reading.is_open()){
    if(reading.peek() == fstream::traits_type::eof()){
        cout << "The directory is empty.\n";
    }
    else{
    cout << "---------------------\n";
    cout << "-- Phone Contacts: --\n";
    cout << "---------------------\n";
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