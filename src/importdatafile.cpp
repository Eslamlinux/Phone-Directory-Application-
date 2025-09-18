#include "header/datatree.h"
#include "header/make_read_data.h"
#include "header/importdatafile.h"
#include "header/colors.h"
#include "header/Paths.h"

void Import_Replace_data(){
    system("clear");
    std::string New_Data_Path ;
    std::string New_Data_File_Name;
    std::cout << "You chose to Replace the old data file path to new one\n";
    std::cout << "Remember that maybe Delete your old data file make Export to old data first\n";
    std::cout << "& and it wil clean also changes and all data that not saved too\n";
    std::cout << "\nEnter you'r new Data file Name\n";
    std::cout << "\nExample:   MyDataFile \n";
    std::getline(std::cin,New_Data_File_Name);
    if(New_Data_File_Name.empty()||New_Data_File_Name.find_first_not_of(' ') == std::string::npos){
        system("clear");
        std::cout  << Colors.red << "Name can not be empty. \nPlease try again.\n" << Colors.reset;
        return;
    }
    system("clear");
    std::cout << "\nEnter your new Data location Directory path that have inside the new data file\n";
    std::cout << "\nExample:   Eslam/FolderData\n";
    std::getline(std::cin,New_Data_Path);
    if(New_Data_Path.empty()||New_Data_Path.find_first_not_of(' ') == std::string::npos){
        system("clear");
        std::cout  << Colors.red << "Data Path cannot be empty or wrong. \nPlease try again.\n" << Colors.reset;
        return;
    }
    
    Manage_Data_Tree.Delete_All_Contacts();
    Manage_Data_Tree.root = nullptr;
    New_Data_Path = New_Data_Path+New_Data_File_Name+".txt";
    Path(New_Data_Path);
    // Load_Creat_Data();
}

