#include <doctest/doctest.h>

#include "dec2bin.h"

TEST_CASE("dec2bin()") {
  CHECK(dec2bin(8) == "1000");
  CHECK(dec2bin(9) == "1001");
  CHECK(dec2bin(1) == "1");
  CHECK(dec2bin(0) == "0");
}
