#include "header/Paths.h"
#include <fstream>
#include <iostream>

std::string DPath = "data/Path.txt";

void Path(std::string ChangePath){
    std::ofstream File_Path;
    File_Path.open(DPath,std::ios::out);
    if(File_Path.is_open()){
        File_Path<< ChangePath;
        File_Path.close();
    }
    else {
        std::cerr << "Error: Could not open the file for writing." << std::endl;
    }
}
std::string Path(){
    std::string PathF;
    std::ifstream File_Path_Reading;

    File_Path_Reading.open(DPath); 

    if (File_Path_Reading.is_open()) {
        std::getline(File_Path_Reading, PathF); 
        File_Path_Reading.close();
    } 
    else {
        std::cerr << "Error: Could not open the file for reading." << std::endl;
    }
    return PathF;
}
