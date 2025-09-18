#include "header/make_read_data.h"
#include "header/datatree.h"
#include "header/The_counter.h"
#include "header/Paths.h"

#include <fstream>


void Load_Creat_Data(){
    long int Count_Data = 0;
        if(Manage_Data_Tree.isEmpty(Manage_Data_Tree.root))  // Load existing contacts into the binary tree
        {
            std::string Pathurl ;
            Pathurl = Path();
            std::ifstream file;
            file.open(Pathurl, std::ios::in);
            if (file.is_open()) {
            std::string line ="";
            while(std::getline(file, line)) {   
                if(!line.empty()) // Avoid inserting empty lines
                {
                    Manage_Data_Tree.To_insert(line + "\n"); // Insert each line into the binary tree
                    Count_Data++;
                }
                CountResult.Count_Data = Count_Data;
            }
        file.close();
        }
        else{
            std::cerr << "Error: Could not open data file at " << Pathurl << std::endl;
        }
    }
    // End of loading contacts into the binary tree

}
