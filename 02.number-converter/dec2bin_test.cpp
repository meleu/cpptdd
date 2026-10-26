#include <string>

std::string dec2bin(unsigned int number) {
  if (number < 2) {
    return std::to_string(number);
  }
  return dec2bin(number / 2) + std::to_string(number % 2);
}

#include <doctest/doctest.h>

TEST_CASE("dec2bin()") {
  CHECK(dec2bin(8) == "1000");
  CHECK(dec2bin(9) == "1001");
  CHECK(dec2bin(1) == "1");
  CHECK(dec2bin(0) == "0");
}
