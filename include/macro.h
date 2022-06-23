#ifndef WEEM_macro_h
#define WEEM_macro_h

// Includes
#include <iostream>
#include <string>

// defines
#define ROOT (std::string)"/Users/justinslingerland/Desktop/Projects/WEEM/"

enum level {
   INFO,
   WARNING,
   ERROR
};

void print(std::string input, level level=level::INFO);

std::string getPointer(void* ptr);

#endif