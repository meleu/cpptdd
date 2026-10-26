#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>

#include <iostream>
#include <string>

std::string dec2bin(unsigned int number);

int main(int argc, char **argv) {
  // -------------------------------------------
  // doctest boilerplate
  // -------------------------------------------
  doctest::Context ctx;
  ctx.applyCommandLine(argc, argv);
  int result = ctx.run();
  if (result != 0 || ctx.shouldExit()) {
    return result;
  }
  // -------------------------------------------

  std::cout << "Enter a number\n> ";
  unsigned int number{};
  std::cin >> number;
  std::cout << "decimal: " << number << "\nbinary: " << dec2bin(number);
}

std::string dec2bin(unsigned int number) {
  if (number < 2) {
    return std::to_string(number);
  }
  return dec2bin(number / 2) + std::to_string(number % 2);
}

// -------------------------------------------
// test code
// -------------------------------------------
TEST_CASE("dec2bin()") {
  CHECK(dec2bin(8) == "1000");
  CHECK(dec2bin(9) == "1001");
  CHECK(dec2bin(1) == "1");
  CHECK(dec2bin(0) == "0");
}
