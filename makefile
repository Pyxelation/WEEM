# compiler used
CXX = g++

# Directories used
SRC_DIR = src
INC_DIR = include
LIB_DIR = lib
OUT_DIR = output

# C++ version
CPP_VER = 20

# Warning flags
WARNINGS = -Wall -Wextra

# Put all options together: 
# (warnings) (c++ version) (include directory)
CXXFLAGS = $(WARNINGS) $(addprefix -std=c++, $(CPP_VER)) $(addprefix -I, $(INC_DIR))

# find all .cpp files and convert them to obj requirments
SOURCES = $(sort $(shell find $(SRC_DIR) -name '*.cpp'))
OBJS = $(SOURCES:.cpp=.o)

TARGET = WEEM

.PHONY: all clean
all: $(TARGET)

clean: 
	rm -f $(OBJS)

$(TARGET): $(OBJS)
	mkdir -p $(OUT_DIR)
	$(CXX) $(CXXFLAGS) `pkg-config --libs --cflags raylib` -o $(OUT_DIR)/output.exe $^
	rm -f $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<