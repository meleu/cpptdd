#include <expected>
#include <string>
#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>
#include <optional>

static std::optional<int> run_tests(int argc, char **argv);

std::expected<double, std::string> get_number(std::istream &input_stream) {
  double number{};
  input_stream >> number;
  if (input_stream) {
    return number;
  }
  return std::unexpected{"That's not a number"};
}

int main(int argc, char **argv) {
  if (auto exit_code = run_tests(argc, argv)) {
    return *exit_code;
  }

  // production code goes here
  // =========================
  std::cout << "Enter a number\n> ";
  auto number = get_number(std::cin);
  if (number.has_value()) {
    std::cout << "Got " << number.value() << " thanks!\n";
  } else {
    std::cout << number.error() << '\n';
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

TEST_CASE("replace me with a real test") { CHECK(1 + 1 == 3); }
