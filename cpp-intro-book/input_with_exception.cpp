#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>
#include <optional>
#include <sstream>

static std::optional<int> run_tests(int argc, char **argv);

double get_number(std::istream &input_stream) {
  double number{};

  input_stream >> number;
  if (input_stream) {
    return number;
  }

  throw std::exception{};
}

int main(int argc, char **argv) {
  if (auto exit_code = run_tests(argc, argv)) {
    return *exit_code;
  }

  // production code goes here
  // =========================
  try {

    std::cout << "Please enter a number.\n> ";
    double number = get_number(std::cin);
    std::cout << "Got " << number << " thanks!\n";
  } catch (const std::exception &ex) {
    std::cout << "Something went wrong.\n";
  }
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

TEST_CASE("get_number()") {
  SUBCASE("raise an exception when input isn't a number") {
    std::istringstream input_stream{"not-a-number"};
    CHECK_THROWS(get_number(input_stream));
  }
}
