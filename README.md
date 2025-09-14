# Phone Directory Application V1.0.1 📞

This is a simple yet effective C++ console application designed to help users manage their phone contacts. The project serves as a great learning tool for fundamental file handling operations and command-line interfaces in C++.

-----

### Features ✨

  * **Simple Command-Line Interface (CLI)**: The application provides a straightforward text-based menu for easy user interaction.
  * **Add Contacts**: Users can add new contacts, which are saved to an external text file.
  * **View All Contacts**: The application can display a list of all saved contacts.
  * **Delete All Contacts**: A quick option is available to wipe all data from the file, effectively resetting the directory.
  * **Persistent Storage**: All contact information is saved in a text file (`myPhoneData.txt`), ensuring that data remains intact even after the program is closed.

-----

### How to Run 🚀

To get this project up and running, follow these simple steps:

1.  **Clone the Repository**:

    ```bash
    git clone [https://github.com/Eslamlinux/Phone-Directory-Application-.git](https://github.com/Eslamlinux/Phone-Directory-Application-.git)
    cd Phone-Directory-Application-
    ```

2.  **Compile the Code**:
    
    **Option A: Quick Install (recommended)**:
    ```bash
    ./install.sh
    ```
    This script will automatically detect the best build method and offer installation options.

    **Option B: Using Make (traditional)**:
    ```bash
    make
    ```

    **Option C: Using CMake (recommended for packaging)**:
    ```bash
    mkdir build && cd build
    cmake ..
    make
    ```

    **Option D: Manual compilation**:
    ```bash
    g++ -std=c++17 -Isrc main.cpp src/*.cpp -o phone_directory
    ```

3.  **Run the Application**:

    ```bash
    ./phone_directory
    ```

    Once running, a menu of options will be displayed in the terminal.

### Packaging 📦

To create distributable packages:

1.  **Using CMake and CPack**:
    ```bash
    mkdir build && cd build
    cmake ..
    make
    cpack
    ```

    This will create DEB, RPM, and TGZ packages on Linux systems.

2.  **Install system-wide**:
    ```bash
    sudo make install
    ```

-----

### Changelog 📝

**Version 1.0.1** (Current)
- ✅ Fixed crash when accessing "see all contacts" after deleting data
- ✅ Fixed inaccurate counting in "Total changes" section  
- ✅ Replaced hardcoded file paths with dynamic path resolution for better packaging
- ✅ Improved tree deletion logic and root pointer handling
- ✅ Enhanced empty tree state management
- ✅ Added CMake build system for professional packaging
- ✅ Created DEB, RPM, and TGZ package generation support
- ✅ Added system-wide installation support
- ✅ Improved data file location detection (works with installed packages)

**Version 1.0.0 Beta**
- Initial release with basic phone directory functionality

-----

### Technologies Used 💻

  * **C++**: The core language of the project.
  * **`fstream`**: For reading from and writing to files.
  * **`iostream`**: For standard input and output via the command line.
  * **`string`**: For handling text data and user input.

-----

### Contribution 🤝

Contributions are welcome\! If you have ideas for improvements or new features, feel free to:

1.  **Fork** this repository.
2.  Create a new branch (`git checkout -b feature/your-feature`).
3.  Submit a **pull request** with a clear description of your changes.

-----

### License 📜

This project is licensed under the MIT License.

-----

### Contact 📧

If you have any questions, feel free to reach out to me on GitHub.

  * [**My GitHub Profile**](https://github.com/Eslamlinux)

