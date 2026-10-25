#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>
#include <optional>

#include <iostream>
#include <map>
#include <string>

enum class Language {
  English,
  French,
  Spanish,
  Portuguese,
};

std::string hello(std::string name = "World",
                  Language language = Language::English);

static std::optional<int> run_tests(int argc, char **argv);

int main(int argc, char **argv) {
  if (auto exit_code = run_tests(argc, argv)) {
    return *exit_code;
  }

  std::cout << hello() << '\n';
}

std::string hello(std::string name, Language language) {
  static const std::map<Language, std::string> prefixes{
      {Language::English, "Hello, "},
      {Language::French, "Bonjour, "},
      {Language::Spanish, "Hola, "},
      {Language::Portuguese, "Olá, "},
  };

  return prefixes.at(language) + name;
}

// Runs the tests. Returns an exit code if the program should stop
// (tests failed, or a flag like --exit/--help was given).
static std::optional<int> run_tests(int argc, char **argv) {
  doctest::Context context;
  context.applyCommandLine(argc, argv);

  int result = context.run();
  if (result != 0 || context.shouldExit()) {
    return result;
  }
  return std::nullopt;
}

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
