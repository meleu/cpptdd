#include "hello.h"

#include <cstdlib>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::string name{};
  if (argc > 1) {
    name = argv[1];
  }

  const char *envLang = std::getenv("LANG");
  Language lang = languageFromLocale(envLang ? envLang : "");

  std::cout << hello(name, lang) << '\n';
}
