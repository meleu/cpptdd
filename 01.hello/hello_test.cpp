#include <string>

std::string hello() { return "Hello, World"; }

// test code

#include <doctest/doctest.h>

TEST_CASE("hello()") { CHECK(hello() == "Hello, World"); }
