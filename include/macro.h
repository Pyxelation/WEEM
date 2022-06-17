#ifndef WEEM_macro_h
#define WEEM_macro_h

// Includes
#include <iostream>
#include <string>

// defines
#define IMG_PATH "/Users/justinslingerland/Desktop/Projects/WEEM/img/"

#define INFO 1
#define WARNING 2
#define ERROR 3

void print(std::string input, int level=INFO);

#endif