#include "header/datatree.h"
#include "header/make_read_data.h"
#include "header/importdatafile.h"
#include "header/colors.h"
#include "header/Paths.h"

void Import_Replace_data(){
    system("clear");
    std::string New_Data_Path ;
    std::string New_Data_File_Name;
    std::cout << Colors.bold_green << "You chose to Replace the old data file path to new one\n";
    std::cout << "Remember that maybe Delete your old data file make Export to old data first\n";
    std::cout << "& and it wil clean also changes and all data that not saved too\n";
    std::cout << Colors.bold_blue << Colors.white_bg <<"\nNow Enter you'r new Data file Name without extension '.txt ' extra!\n" << Colors.reset;
    std::cout << Colors.bold_red << "\nExample:   MyDataFile \n" << Colors.reset;
    std::getline(std::cin,New_Data_File_Name);
    if(New_Data_File_Name.empty()||New_Data_File_Name.find_first_not_of(' ') == std::string::npos){
        system("clear");
        std::cout  << Colors.red << "Name can not be empty. \nPlease try again.\n" << Colors.reset;
        return;
    }
    system("clear");
    std::cout << Colors.bold_green <<  "\nEnter your new Data location Directory path that have inside the new data file\n";
    std::cout << Colors.bold_red <<  "\nExample:   /Eslam/FolderData/\n" << Colors.reset;
    std::getline(std::cin,New_Data_Path);
    if(New_Data_Path.empty()||New_Data_Path.find_first_not_of(' ') == std::string::npos){
        system("clear");
        std::cout  << Colors.red << Colors.bold_red << "Data Path cannot be empty or wrong. \nPlease try again.\n" << Colors.reset;
        return;
    }
    std::string delPath;
    delPath = Path();
    // system("delPath");
    Manage_Data_Tree.Delete_All_Contacts();
    Manage_Data_Tree.root = nullptr;
    New_Data_Path = New_Data_Path+New_Data_File_Name+".txt";
    Path(New_Data_Path);
    // Load_Creat_Data();
}

