#include "hello.h"
#include <map>

std::string hello(std::string name, Language language) {
  static const std::map<Language, std::string> prefixes{
      {Language::English, "Hello, "},
      {Language::French, "Bonjour, "},
      {Language::Spanish, "Hola, "},
      {Language::Portuguese, "Olá, "},
  };
  if (name.empty()) {
    name = "World";
  }

  return prefixes.at(language) + name;
}

Language languageFromLocale(std::string locale) {
  static const std::map<std::string, Language> languages{
      {"pt", Language::Portuguese},
      {"es", Language::Spanish},
      {"fr", Language::French},
  };

  const std::string languageCode = locale.substr(0, locale.find('_'));
  if (languages.contains(languageCode)) {
    return languages.at(languageCode);
  }

  return Language::English;
}
