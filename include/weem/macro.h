#ifndef WEEM_macro_h
#define WEEM_macro_h

// Includes
#include <iostream>
#include <string>
#include <filesystem>

// defines
#define ROOT (std::string) std::filesystem::current_path()

enum level {
   INFO,
   WARNING,
   ERROR
};

const int noone = -1;

void print(std::string input, level level=level::INFO);

std::string getPointer(void* ptr);

#endif