#include <string>

std::string dec2bin(int number, int length = 4) {
  std::string binary{};
  for (unsigned i = (1 << (length - 1)); i > 0; i = i / 2) {
    binary += (number & i) ? "1" : "0";
  }

  return binary;
}

#include <doctest/doctest.h>

TEST_CASE("dec2bin()") {
  CHECK(dec2bin(8) == "1000");
  CHECK(dec2bin(9) == "1001");
}
