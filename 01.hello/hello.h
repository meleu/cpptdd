#pragma once

#include <string>

enum class Language {
  English,
  French,
  Spanish,
  Portuguese,
};

std::string hello(std::string name = "", Language language = Language::English);

Language languageFromLocale(std::string locale);
