#include "dec2bin.h"
#include <iostream>

int main() {
  std::cout << "Enter a number\n> ";
  unsigned int number{};
  std::cin >> number;
  std::cout << "decimal: " << number << "\nbinary: " << dec2bin(number);
}
