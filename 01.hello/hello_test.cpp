#include "hello.h"

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

TEST_CASE("languageFromLocale()") {
  SUBCASE("detect Portuguese") {
    CHECK(languageFromLocale("pt_BR.UTF-8") == Language::Portuguese);
    CHECK(languageFromLocale("pt_PT.UTF-8") == Language::Portuguese);
    CHECK(languageFromLocale("pt") == Language::Portuguese);
  }
  SUBCASE("detect Spanish") {
    CHECK(languageFromLocale("es_ES.UTF-8") == Language::Spanish);
    CHECK(languageFromLocale("es_MX.UTF-8") == Language::Spanish);
  }
  SUBCASE("detect French") {
    CHECK(languageFromLocale("fr_FR.UTF-8") == Language::French);
  }
  SUBCASE("fall back to English for unknown or missing locales") {
    CHECK(languageFromLocale("en_US.UTF-8") == Language::English);
    CHECK(languageFromLocale("C") == Language::English);
    CHECK(languageFromLocale("") == Language::English);
  }
}
