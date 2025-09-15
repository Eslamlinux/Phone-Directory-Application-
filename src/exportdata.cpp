#include "exportdata.h"
#include "datatree.h"
#include <fstream>
#include <limits>




void To_Export(){
    system("clear");
    std::string File_Location_ToSave;
    std::string File_Name = "your_phone_data_exported";
    char To_Export_Entry;
    system("clear");
    std::cout << "enter location to export your file in\n";
    std::cout << "also must end with '/' or you wil save in the same directory   \n";
    std::cout << "and the data file name will start with the name you entered\n";
    getline(std::cin,File_Location_ToSave);
        if(File_Location_ToSave.empty() || File_Location_ToSave.find_first_not_of(' ') == std::string::npos){
        system("clear");
        std::cout << "File Location can't be Empty try agin\n";
        return;
    }
    system("clear");
    std::cout << "now enter the file name'\n";
    getline(std::cin,File_Name);

    if(File_Name.empty() || File_Name.find_first_not_of(' ') == std::string::npos){
        system("clear");
        std::cout << "File Name can't be Empty try agin\n";
        return;
    }
    system("clear");
    std::cout << "are you sure you want to export all data even not saved one?\n";
    std::cout << "'Y' for 'Yes' & 'N' for 'No'\n";
    std::cin >> To_Export_Entry ;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(To_Export_Entry == 'y' || To_Export_Entry == 'Y'){
            Manage_Data_Tree.Export_Tree(Manage_Data_Tree.root,File_Location_ToSave + File_Name + ".txt");
            std::cout << "you data exported in this location: " <<  File_Location_ToSave << std::endl;
        }
        
            else if(To_Export_Entry != 'y' || To_Export_Entry != 'Y' || To_Export_Entry != 'n' || To_Export_Entry != 'N')
            {
                system("clear");
                std::cout << "you enter wrong choice \n";
                return ;
            }
        else{
            system("clear");
            std::cout << "Nothing Exported as you choose\n";
            return ;
        }
    
};
