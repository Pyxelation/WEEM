#include "macro.h"

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