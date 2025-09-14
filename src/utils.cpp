#include "utils.h"
#include <fstream>
#include <cstdlib>

std::string getDataFilePath() {
    // Try current working directory first
    std::ifstream testFile("data/myPhoneData.txt");
    if (testFile.good()) {
        testFile.close();
        return "data/myPhoneData.txt";
    }
    testFile.close();
    
    // Try current directory
    testFile.open("myPhoneData.txt");
    if (testFile.good()) {
        testFile.close();
        return "myPhoneData.txt";
    }
    testFile.close();
    
    // Try user's home directory
    const char* home = getenv("HOME");
    if (home) {
        std::string homePath = std::string(home) + "/myPhoneData.txt";
        return homePath;
    }
    
    // Fallback to current directory
    return "data/myPhoneData.txt";
}