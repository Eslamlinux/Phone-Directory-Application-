#include "readList.h"
#include "datatree.h"
#include <The_counter.h>
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
        std::cout << "-------- P.H.O.N.E  C.O.N.T.A.C.T.S --------\n";
        std::cout << "--------N-a-m-e----------N-u-m-b-e-r--------\n";
        std::cout << "--------------------------------------------\n";        
        Manage_Data_Tree.print_preorder(Manage_Data_Tree.root);
        std::cout << "\n----------------------------------------------\n";
        std::cout << "Total contacts currently in the directory: " << CountResult.curentCount << std::endl;
        std::cout << "----------------------------------------------\n";
    }
}