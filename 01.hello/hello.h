#pragma once

#include <string>

enum class Language {
  English,
  French,
  Spanish,
  Portuguese,
};

std::string hello(std::string name = "World",
                  Language language = Language::English);
