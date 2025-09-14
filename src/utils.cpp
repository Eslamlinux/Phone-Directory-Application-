#include "utils.h"
#include <filesystem>
#include <cstdlib>
#include <unistd.h>

std::string getDataFilePath() {
    // First, try to find the data file relative to the executable
    std::string exePath;
    
    // Get the path of the executable
    char buffer[1024];
    ssize_t len = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
    if (len != -1) {
        buffer[len] = '\0';
        exePath = std::string(buffer);
        
        // Get the directory containing the executable
        size_t lastSlash = exePath.find_last_of('/');
        if (lastSlash != std::string::npos) {
            std::string exeDir = exePath.substr(0, lastSlash);
            
            // Try data/myPhoneData.txt relative to executable directory
            std::string dataPath = exeDir + "/data/myPhoneData.txt";
            if (std::filesystem::exists(dataPath)) {
                return dataPath;
            }
            
            // Try myPhoneData.txt in the same directory as executable
            dataPath = exeDir + "/myPhoneData.txt";
            if (std::filesystem::exists(dataPath)) {
                return dataPath;
            }
        }
    }
    
    // Try current working directory
    if (std::filesystem::exists("data/myPhoneData.txt")) {
        return "data/myPhoneData.txt";
    }
    
    if (std::filesystem::exists("myPhoneData.txt")) {
        return "myPhoneData.txt";
    }
    
    // Try system installation path
    if (std::filesystem::exists("/usr/share/phone_directory/data/myPhoneData.txt")) {
        return "/usr/share/phone_directory/data/myPhoneData.txt";
    }
    
    if (std::filesystem::exists("/usr/local/share/phone_directory/data/myPhoneData.txt")) {
        return "/usr/local/share/phone_directory/data/myPhoneData.txt";
    }
    
    // Try user's home directory
    const char* home = getenv("HOME");
    if (home) {
        std::string homePath = std::string(home) + "/.phone_directory/myPhoneData.txt";
        
        // Create the directory if it doesn't exist
        std::string homeDir = std::string(home) + "/.phone_directory";
        if (!std::filesystem::exists(homeDir)) {
            std::filesystem::create_directories(homeDir);
        }
        
        return homePath;
    }
    
    // Fallback to current directory
    return "myPhoneData.txt";
}