cmake_minimum_required(VERSION 3.10)
project(PhoneDirectory VERSION 1.0.1)
# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
set(SOURCES
    main.cpp
    src/setup.cpp
    src/addNumber.cpp
    src/readList.cpp
    src/deleteAllContacts.cpp
    src/datatree.cpp
    src/The_counter.cpp
    src/utils.cpp
)

add_executable(phone_directory ${SOURCES})

# Include directories
target_include_directories(phone_directory PRIVATE src)

# Link filesystem library if needed
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS "9.0")
    target_link_libraries(phone_directory stdc++fs)
endif()

# Install targets
install(TARGETS phone_directory
    RUNTIME DESTINATION bin
)

# Install data file
install(FILES data/myPhoneData.txt
    DESTINATION share/phone_directory/data
    OPTIONAL
)

# Create desktop entry for Linux systems
if(UNIX AND NOT APPLE)
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/phone_directory.desktop.in"
        "${CMAKE_CURRENT_BINARY_DIR}/phone_directory.desktop"
        @ONLY
    )
    
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/phone_directory.desktop"
        DESTINATION share/applications
        OPTIONAL
    )
endif()

# CPack configuration for packaging
set(CPACK_PACKAGE_NAME "PhoneDirectory")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A simple phone directory application")
set(CPACK_PACKAGE_VENDOR "Eslamlinux")
set(CPACK_PACKAGE_CONTACT "github.com/Eslamlinux")

# Set package generators
if(WIN32)
    set(CPACK_GENERATOR "NSIS;ZIP")
elseif(APPLE)
    set(CPACK_GENERATOR "DragNDrop;TGZ")
else()
    set(CPACK_GENERATOR "DEB;RPM;TGZ")
endif()

# DEB package specific settings
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Eslamlinux")
set(CPACK_DEBIAN_PACKAGE_SECTION "utils")
set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")

# RPM package specific settings
set(CPACK_RPM_PACKAGE_GROUP "Applications/System")
set(CPACK_RPM_PACKAGE_LICENSE "MIT")

include(CPack)