// hello.h
// ----------------------------------------------------------------------
#include <string>

std::string hello(std::string name = "World");

// hello.cpp
// ----------------------------------------------------------------------
std::string hello(std::string name) { return "Hello, " + name; }

// hello_test.cpp
// ----------------------------------------------------------------------
// #include "hello.h"

#include <doctest/doctest.h>

TEST_CASE("hello()") {

  SUBCASE("say hello to people") { CHECK(hello("John") == "Hello, John"); }

  SUBCASE("say 'Hello, World' when no name is given") {
    CHECK(hello() == "Hello, World");
  }
}
