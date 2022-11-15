# compiler used
CXX = g++

# command to include libraries
LIB = `pkg-config --libs --cflags raylib`

# Directories used
SRC_DIR = src
INC_DIR = include
LIB_DIR = lib
BIN_DIR = bin
OUT_DIR = $(BIN_DIR)/out

# C++ version
CPP_VER = 20

# Warning flags
WARNINGS = -Wall -Wextra -g -Og

# Put all options together: 
# (warnings) (c++ version) (include directory)
CXXFLAGS = $(WARNINGS) $(addprefix -std=c++, $(CPP_VER)) $(addprefix -I, $(INC_DIR))

# find all folders and .cpp files to convert them to .o requirements
SOURCES = $(sort $(shell find $(SRC_DIR) -name '*.cpp')) # finds all .cpp files
OBJS = $(patsubst $(SRC_DIR)/%,%,$(SOURCES:.cpp=.o)) # removes the source folder name out of the .cpp and turns it into .o
DIRS = $(sort $(OUT_DIR) $(subst ., ,$(dir $(addprefix $(BIN_DIR)/, $(OBJS))))) # takes the folder names out of the object files and adds the output folder

TARGET = WEEM

.PHONY: all clean $(TARGET)

# create the executable
all: $(DIRS) $(TARGET) # firstly creates the folders and then the output

# clear the object files
clean: 
	rm -r $(OUT_DIR)
	rm -r $(BIN_DIR)

# create the required folders
$(DIRS):
	mkdir -p $@

# create the required object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# compile the executable
$(TARGET): $(addprefix $(BIN_DIR)/, $(OBJS))
	mkdir -p $(OUT_DIR)
	$(CXX) $(CXXFLAGS) $(LIB) -o $(OUT_DIR)/output.exe $^
