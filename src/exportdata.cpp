#include "exportdata.h"
#include <fstream>

void To_Export(){
    system("clear");
    std::cout << "enter location to export your file in\n";
    getline(cin,File_Location_ToSave);
    if(File_Location_ToSave.empty || File_Location_ToSave.find_first_not_of(' ') == std::string::npos){
        system("clear");
        std::cout << "File Location can't be Empty try agin\n";
        return;
    }


}