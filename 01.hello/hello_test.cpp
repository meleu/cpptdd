// hello.h
#include <string>

std::string hello(std::string name = "World", std::string language = "English");

// hello.cpp
std::string hello(std::string name, std::string language) {
  std::string prefix = "Hello, ";

  if (language == "French") {
    prefix = "Bonjour, ";
  }

  return prefix + name;
}

// ----------------------------------------------------------------------
// tests
// ----------------------------------------------------------------------
// #include "hello.h"

#include <doctest/doctest.h>

TEST_CASE("hello()") {

  SUBCASE("say hello to people") { CHECK(hello("John") == "Hello, John"); }

  SUBCASE("say 'Hello, World' when no name is given") {
    CHECK(hello() == "Hello, World");
  }

  SUBCASE("say 'Bonjour' in French") {
    CHECK(hello("Jean", "French") == "Bonjour, Jean");
  }
}
