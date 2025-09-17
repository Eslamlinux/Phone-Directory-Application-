#include "header/make_read_data.h"
#include "header/datatree.h"
#include "header/The_counter.h"

#include <fstream>

long int Count_Data = 0;

void Load_Creat_Data(std::string Data_Path){
        if(Manage_Data_Tree.isEmpty(Manage_Data_Tree.root))  // Load existing contacts into the binary tree
        {
            std::ifstream file;
            file.open(Data_Path, std::ios::app);
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
    // End of loading contacts into the binary tree

}
