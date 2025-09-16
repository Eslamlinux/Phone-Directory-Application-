#include "header/readList.h"
#include "header/datatree.h"
#include "header/colors.h"
#include <header/The_counter.h>
#include <iostream>
#include <fstream>
#include <string>


void readList() {

    if(Manage_Data_Tree.root == nullptr || Manage_Data_Tree.root->data ==""){ 
        system("clear");
        std::cout << "The directory is empty.\n";
        return;
    }
    else if(Manage_Data_Tree.root != nullptr || Manage_Data_Tree.root->data != "") 
    { 
                system("clear");
        CountResult.curentCount = (CountResult.Count_Data + CountResult.Count_new_contact) - CountResult.Count_deleted; // Update current count 
        std::cout << Colors.light_white<< Colors.bold_blue_bg<<"-------- P.H.O.N.E  C.O.N.T.A.C.T.S --------\n";
        std::cout << "--------N-a-m-e----------N-u-m-b-e-r--------\n"<< Colors.reset;
        std::cout << Colors.light_white  << Colors.bold_blue_bg << "--------------------------------------------\n\n" << Colors.reset;        
        Manage_Data_Tree.print_preorder(Manage_Data_Tree.root);
        std::cout << std::endl;
        std::cout  << Colors.red << "----------------------------------------------\n";
        std::cout << Colors.bold_blue_bg << "Total contacts currently in the directory: " << CountResult.curentCount << " " << Colors.reset<< std::endl;
        std::cout << Colors.red << "----------------------------------------------\n" << Colors.reset;
    }
}