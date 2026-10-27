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

/**
 * Wraps `text` in a banner: a line of '=' characters above and below it.
 *
 * The border is as wide as the longest line of `text`, so multi-line input
 * is framed by a border matching its widest line. The result begins with a
 * newline (before the top border) and ends with the bottom border, with a
 * trailing newline.
 *
 * @param text The text to frame; may contain embedded '\n' characters.
 * @return The text surrounded by top and bottom borders.
 */
std::string banner(std::string text) {
  int length = longestLineLength(text);
  std::string border{'\n'};

  for (int i{0}; i < length; i++) {
    border += "=";
  }
  border += '\n';

  return border + text + border;
}

#include <doctest/doctest.h>

TEST_CASE("banner()") {
  SUBCASE("single line banner") {
    CHECK(banner("text") == R"(
====
text
====
)");
  }

  SUBCASE("multiline banner") {
    CHECK(banner("text\nwith multiple\nlines") == R"(
=============
text
with multiple
lines
=============
)");
  }
}

TEST_CASE("repeat()") { CHECK(repeat("a") == "aaaaa"); }
