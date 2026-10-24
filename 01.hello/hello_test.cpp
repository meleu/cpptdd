#include "hello.h"

#include <doctest/doctest.h>

TEST_CASE("hello()") {

  SUBCASE("say hello to people") { CHECK(hello("John") == "Hello, John"); }

  SUBCASE("say 'Hello, World' when no name is given") {
    CHECK(hello() == "Hello, World");
  }
}
