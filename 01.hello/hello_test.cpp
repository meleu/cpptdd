// hello.h
#include <string>

enum class Language {
  English,
  French,
  Spanish,
  Portuguese,
};

std::string hello(std::string name = "World",
                  Language language = Language::English);

// hello.cpp
#include <map>

std::string hello(std::string name, Language language) {
  static const std::map<Language, std::string> prefixes{
      {Language::English, "Hello, "},
      {Language::French, "Bonjour, "},
      {Language::Spanish, "Hola, "},
      {Language::Portuguese, "Olá, "},
  };

  return prefixes.at(language) + name;
}

// ----------------------------------------------------------------------
// tests
// ----------------------------------------------------------------------
// #include "hello.h"

#include <doctest/doctest.h>

TEST_CASE("hello()") {

  SUBCASE("say 'Olá' in Portuguese") {
    CHECK(hello("João", Language::Portuguese) == "Olá, João");
  }

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
