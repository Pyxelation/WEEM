#ifndef WEEM_macro_h
#define WEEM_macro_h

// debug options
static bool DEBUG = true;
static bool BBOX = true;
static bool LOCATOR = true;

// Includes
#include <iostream>
#include <string>
#include <filesystem>
#include <sstream>

// defines
#define ROOT (std::string) std::filesystem::current_path()

enum level {
   INFO,
   WARNING,
   ERROR
};

const int noone = -1;

void print(std::string input, level level=level::INFO);

float roundf(float value, int dec = 0);

std::string getPointer(void* ptr);

template <typename T>
std::string to_pstring(const T a_value, const int n = 6) {
   std::ostringstream out;
   out.precision(n);
   out << std::fixed << a_value;
   return std::move(out).str();
}

#endif