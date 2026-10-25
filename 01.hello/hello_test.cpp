// hello.h
#include <string>

enum class Language {
  English,
  French,
  Spanish,
};

std::string hello(std::string name = "World",
                  Language language = Language::English);

// hello.cpp
std::string hello(std::string name, Language language) {
  std::string prefix = "Hello, ";

  if (language == Language::French) {
    prefix = "Bonjour, ";
  } else if (language == Language::Spanish) {
    prefix = "Hola, ";
  }

  return prefix + name;
}

// ----------------------------------------------------------------------
// tests
// ----------------------------------------------------------------------
// #include "hello.h"

#include <doctest/doctest.h>

TEST_CASE("hello()") {

  SUBCASE("say 'Hola' in Spanish") {
    CHECK(hello("Juan", Language::Spanish) == "Hola, Juan");
  }

  SUBCASE("say 'Bonjour' in French") {
    CHECK(hello("Jean", Language::French) == "Bonjour, Jean");
  }

  SUBCASE("say hello to people") { CHECK(hello("John") == "Hello, John"); }

  SUBCASE("say 'Hello, World' when no name is given") {
    CHECK(hello() == "Hello, World");
  }
}
