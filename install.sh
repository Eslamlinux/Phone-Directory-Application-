#!/bin/bash

# Phone Directory Application - Installation Script
# Version 1.0.1

set -e

echo "📞 Phone Directory Application V1.0.1 - Installation Script"
echo "============================================================"

# Check if cmake is available
if command -v cmake >/dev/null 2>&1; then
    echo "✅ CMake found - Using CMake build system (recommended)"
    BUILD_METHOD="cmake"
else
    echo "⚠️  CMake not found - Using Make build system"
    BUILD_METHOD="make"
fi

# Create build directory and compile
echo "🔨 Building application..."

if [ "$BUILD_METHOD" = "cmake" ]; then
    mkdir -p build
    cd build
    cmake ..
    make -j$(nproc)
    echo "✅ Build completed successfully using CMake"
    
    # Ask for installation
    echo ""
    read -p "Do you want to install system-wide? (y/N): " install_choice
    if [[ $install_choice =~ ^[Yy]$ ]]; then
        echo "🚀 Installing system-wide..."
        sudo make install
        echo "✅ Installation completed! You can now run 'phone_directory' from anywhere."
    else
        echo "📁 Application built in build/phone_directory"
        echo "   You can run it with: ./build/phone_directory"
    fi
    
    # Ask for package creation
    echo ""
    read -p "Do you want to create distribution packages? (y/N): " package_choice
    if [[ $package_choice =~ ^[Yy]$ ]]; then
        echo "📦 Creating packages..."
        cpack -G TGZ
        if command -v dpkg-deb >/dev/null 2>&1; then
            cpack -G DEB
        fi
        echo "✅ Packages created in build/ directory"
        ls -la build/PhoneDirectory-*.* 2>/dev/null || true
    fi
    
else
    make clean
    make -j$(nproc)
    echo "✅ Build completed successfully using Make"
    echo "📁 Application built as 'phone_directory'"
    echo "   You can run it with: ./phone_directory"
fi

echo ""
echo "🎉 Installation script completed!"
echo "📖 Check README.md for usage instructions"