# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Isrc

# Directories
SRC_DIR = src
OBJ_DIR = obj
DATA_DIR = data

# Source files and object files
SRCS = main.cpp $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(notdir $(SRCS)))

# Executable name
TARGET = phone_directory

# Default rule: build the executable
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile a .cpp file into a .o file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: main.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to create the data directory
setup_dirs:
	@mkdir -p $(DATA_DIR)

# Rule to clean up the build files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Phony targets are not real files
.PHONY: all clean setup_dirs
