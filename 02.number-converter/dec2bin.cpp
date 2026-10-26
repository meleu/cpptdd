#include "dec2bin.h"
#include <string>

std::string dec2bin(unsigned int number) {
  if (number < 2) {
    return std::to_string(number);
  }
  return dec2bin(number / 2) + std::to_string(number % 2);
}
