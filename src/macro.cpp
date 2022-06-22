#include "macro.h"
#include <sstream>

// a simple print function with coloring for different types of messages:
// INFO: for white text
// WARNING: for yellow text
// ERROR: for red text
void print(std::string input, int level) {
   switch(level) {
      default:
      case INFO:
         std::cout << input << std::endl;
      break;

      case WARNING:
         std::cout << "\033[33m" << input << "\033[0m" << std::endl;
      break;

      case ERROR:
         std::cout << "\033[31m" << input << "\033[0m" << std::endl;
      break;
   }
}

// return a string containing the given pointer
// any pointer can be converted using (void*)ptr
std::string getPointer(void* ptr) {
   std::stringstream ss;
   ss << ptr;
   return ss.str();
}