#include <main.h>

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
    myData.open("/data/myPhoneData.txt" , ios::out|ios::app );

    if(myData.is_open()){
    myData << entry_name << " | " << entry_num << endl;
    myData.close();
    }
    else{
        cerr << "Error: Could not open the file.\n"; 
    }

}