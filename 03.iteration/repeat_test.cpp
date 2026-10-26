#include <cstddef>
#include <string>

std::string repeat(std::string text) {
  std::string result{};
  for (int i{0}; i < 5; i++) {
    result += text;
  }
  return result;
}

std::size_t longestLineLength(const std::string &text) {
  std::string longest;
  std::size_t start = 0;

  while (true) {
    std::size_t end = text.find('\n', start);
    std::size_t count =
        (end == std::string::npos ? text.length() : end) - start;

    if (count > longest.length()) {
      longest = text.substr(start, count);
    }
    if (end == std::string::npos) {
      break;
    }

    start = end + 1;
  }

  return longest.length();
}

std::string banner(std::string text) {
  int length = longestLineLength(text);
  std::string border{'\n'};

  for (int i{0}; i < length; i++) {
    border += "=";
  }

  return border + '\n' + text + border;
}

#include <doctest/doctest.h>

TEST_CASE("banner()") {
  SUBCASE("single line banner") {
    CHECK(banner("text") == R"(
====
text
====)");
  }

  SUBCASE("multiline banner") {
    CHECK(banner("text\nwith multiple\nlines") == R"(
=============
text
with multiple
lines
=============)");
  }
}

TEST_CASE("repeat()") { CHECK(repeat("a") == "aaaaa"); }
