#include "hello.h"

#include <doctest/doctest.h>

TEST_CASE("hello()") { CHECK(hello() == "Hello, World"); }
