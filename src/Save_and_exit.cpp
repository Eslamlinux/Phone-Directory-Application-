void save_and_exit() {
    // Save the current state of the binary tree to the file
    std::ofstream file("data/myPhoneData.txt", std::ios::trunc);
    if (file.is_open()) {
        Manage_Data_Tree.saveToFile(Manage_Data_Tree.root, file);
        file.close();
        std::cout << "Contacts saved successfully. Exiting...\n";
    } else {
        std::cerr << "Error: Could not open the file for saving.\n";
    }
}