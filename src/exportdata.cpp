#include "exportdata.h"
#include "datatree.h"
#include "colors.h"
#include <fstream>
#include <limits>

void To_Export(){
    system("clear");
    std::string File_Location_ToSave;
    std::string File_Name = "your_phone_data_exported";
    char To_Export_Entry;
    system("clear");
                    std::cout << Colors.bold_red << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n";
                    std::cout << "|*| "<< Colors.underline << "*** Note ***"<< Colors.reset << Colors.bold_red <<"                                                |*|\n";
                    std::cout << "|*| " << Colors.green << "Enter location to export your file in,     " << Colors.red <<   "                 |*|\n" ;
                    std::cout << "|*| " << Colors.green << "Also must end with '/' or you wil save in the same directory" << Colors.red << "|*|\n";
                    std::cout << "|*| " << Colors.green << "And the data file name will start with the name you entered " << Colors.red << "|*|\n";
                    std::cout << "|*| " << Colors.green << "Example : Folder/Folder/                                    " << Colors.red << "|*|\n";
                    std::cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n" << Colors.reset;

    getline(std::cin,File_Location_ToSave);
        if(File_Location_ToSave.empty() || File_Location_ToSave.find_first_not_of(' ') == std::string::npos){
        system("clear");
        std::cout <<Colors.red << "File Location can't be Empty try agin\n"<<Colors.reset;
        return;
    }
    system("clear");
    std::cout <<Colors.bold_blue << "Now enter the file name'\n"<<Colors.reset;
    getline(std::cin,File_Name);

    if(File_Name.empty() || File_Name.find_first_not_of(' ') == std::string::npos){
        system("clear");
        std::cout <<Colors.red << "File Name can't be Empty try agin\n"<<Colors.reset;
        return;
    }
    system("clear");
    std::cout <<Colors.bold_green_bg <<Colors.red  << "Are you sure you want to export all data even not saved one?\n"<<Colors.reset;
    std::cout <<Colors.bold_red << "Enter 'Y' for 'Yes' & 'N' for 'No'\n"<<Colors.reset;
    std::cin >> To_Export_Entry ;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(To_Export_Entry == 'y' || To_Export_Entry == 'Y'){
            Manage_Data_Tree.Export_Tree(Manage_Data_Tree.root,File_Location_ToSave + File_Name + ".txt");
            std::cout <<Colors.green <<"you data exported in this location: "<<Colors.reset <<  File_Location_ToSave << std::endl;
        }
        else{
            system("clear");
            std::cout << Colors.red <<"Nothing Exported as you choose\n"<<Colors.reset;
            return ;
        }
        
        if((To_Export_Entry != 'y' || To_Export_Entry != 'Y' )|| (To_Export_Entry != 'n' || To_Export_Entry != 'N'))
        {
            system("clear");
            std::cout <<Colors.red <<"You enter wrong choice \n"<<Colors.reset;
            return ;
        }

    
};
