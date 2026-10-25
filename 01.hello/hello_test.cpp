// hello.h
#include <string>

enum class Language {
  English,
  French,
};

std::string hello(std::string name = "World",
                  Language language = Language::English);

// hello.cpp
std::string hello(std::string name, Language language) {
  std::string prefix = "Hello, ";

  if (language == Language::French) {
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
    CHECK(hello("Jean", Language::French) == "Bonjour, Jean");
  }
}
