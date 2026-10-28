#include <vector>

int sum(std::vector<int> numbers) {
  int result{};
  for (const auto number : numbers) {
    result += number;
  }
  return result;
}

#include <doctest/doctest.h>

TEST_CASE("sum()") {
  SUBCASE("collection nof 5 numbers") {
    std::vector numbers{1, 2, 3, 4, 5};
    int expected{15};

    CHECK(sum(numbers) == expected);
  }

  SUBCASE("collection of 3 numbers") {
    std::vector numbers{1, 2, 3};
    int expected{6};

    CHECK(sum(numbers) == expected);
  }
}
