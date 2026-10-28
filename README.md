# Learn C++ with TDD

I'm doing some exercises, highly inspired by [Learn Go with Tests](http://quii.gitbook.io/learn-go-with-tests/)
but to learn C++.

I'm using [doctest](https://github.com/doctest/doctest) as the testing
framework. Installed using the distro package manager
(Arch: `pacman -S doctest`; Debian: `apt-get install doctest-dev`).
See [doctest.mk](https://github.com/meleu/doctest.mk) to get an easy way
to start testing simple C++ projects.

The main source of C++ knowledge I'm using is [learncpp.com](https://learncpp.com).

Below I'm taking notes of what I've been learning.

## 01. Hello World

### Print to stdout

```cpp
#include <iostream> // required to use std::cout

int main() {
  // put a string into the std::cout stream, which
  // writes to standard output
  std::cout << "Hello, World";
}
```

**NOTES**:

- the `::` operator is a way to reference the a scope.
- `std::cout` means the `cout` object from the `std` namespace

### Basic test with doctest

```cpp
#include <doctest/doctest.h> // doctest installed via package manager

TEST_CASE("hello()") {
  CHECK(hello() == "Hello, World");
}
```

### Ceremony required to separate main / domain code / tests

In order to "connect" the domain code (`hello.cpp`) with the main function
and also allow it to be tested, we need the `hello.h`.

```
├── hello.cpp
├── hello.h
├── hello_test.cpp
└── main.cpp
```

The `hello.h` file must be included in all three files. Yeah, that's a lot
of ceremony, compared with other languages, but that's the C++ way.

There are some important concepts to be aware about including header files,
and they can be learned [here](https://www.learncpp.com/cpp-tutorial/header-files/)
and [here](https://www.learncpp.com/cpp-tutorial/header-guards/).

The main things to remember:

- `#include "file.h"` with double quotes when the header file is part of the project.
- `#include <file.h>` when it's a lib we didn't write (the preprocessor searches for it in the "include directories").
  - sometimes the `.h` is omitted (like in `#include <iostream>`)

### Headers files need a header guard

In order to prevent header files being included more than once, it's important
to add "header guards" to them.

Classic way:

```cpp
#ifndef MY_HEADER_H
#define MY_HEADER_H

// declarations here...

#endif
```

Non-standard-but-commonly-used way:

```cpp
#pragma once

// declarations here...
```

### Functions accept default values (but they must be declared in the header)

In C++ we can have default values for function arguments, so the callers can
omit that argument. But there's a detail to keep in mind: The definition of
the default value MUST be in the header file, not in the "implementation file".
Reason: the call site (the file including the header) must be aware that
calling the function omitting that argument is a valid thing.

A good way to remember:

**A default argument is part of the function's interface**, it's not part
of the implementation. So it belongs in the header next to the rest of the
interface.

In fact, the default value is used at compile time. The compiler replaces
`hello()` with `hello("World")` at compile time and the implementation code
doesn't even know that a "default value" was used. It just get the value it
needs to do its job.

### Scoped enumerations (enum class)

We can use a scoped enumeration to add a semantic value to the languages:

```cpp
enum class Language {
  English,
  French,
  Spanish,
  Portuguese
};

// Now we can use, for example, `Language::French`.
```

See more in scoped enumerations in <https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/>.

### Using maps (aka Lookup Tables)

Example of use of a lookup table (aka map, dictionary or associative array):

```cpp
#include <map>

std::string hello(std::string name, Language language) {
  static const std::map<Language, std::string> prefixes{
      {Language::English, "Hello, "},
      {Language::French, "Bonjour, "},
      {Language::Spanish, "Hola, "},
      {Language::Portuguese, "Olá, "},
  };

  return prefixes.at(language) + name;
}
```

## 02. Decimal to Binary Converter

### Test code and production code in the same file

doctest allows `TEST_CASE`s to live in the same file as the code they test
(see [02.number-converter/](./02.number-converter/)).

Since the file has its own `main()`, we tell doctest not to provide one, and
run the tests from our `main()`:

```cpp
#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>

int main(int argc, char **argv) {
  // doctest boilerplate
  // -------------------------------
  doctest::Context ctx;
  ctx.applyCommandLine(argc, argv);
  int result = ctx.run();
  if (result != 0 || ctx.shouldExit()) {
    return result;
  }

  // production code...
  // -------------------------------
}

  // test code...
  // -------------------------------
TEST_CASE("hello()") {
  CHECK(hello() == "Hello, World");
}
```

The same binary runs tests and/or the program, depending on the flags:

- `./hello`: run the tests, then the program
- `./hello --exit`: run only the tests
- `./hello --no-run`: run only the program

For the release build, compile with `-DDOCTEST_CONFIG_DISABLE`: all the test
code is stripped out at compile time (`context.run()` becomes a no-op).

```bash
# with tests
clang++ -std=c++23 hello.cpp -o hello_test

# release
clang++ -std=c++23 -O2 -DDOCTEST_CONFIG_DISABLE hello.cpp -o hello
```

In the example, the `Makefile` wraps this as `make test` and `make build`.

## 03. Iteration (text banner)

### Get the length of a string

```cpp
// std::string my_string{"meleu"};
my_string.length();
// => 5
```

### Find a char in a string

```cpp
// Returns the index of the first occurrence of the given character
// in my_string, starting from the given position. If not found,
// returns npos.
my_string.find(character, position);
```

### What is `std::string::npos`?

It means "no position". It's a way to C++ use to say "the position you
want was not found".

## 04. Arrays

### Vector

The most generic way to deal with arrays in C++ is by using `std::vector`.

We can define the type as `std::vector<int>` but also can use Class
Template Argument Deduction (aka CTAD, a fancy name for "type inference").

```cpp
// explicitly declare the type between <angle-brackets>
int sum(std::vector<int> numbers) { /* ... */ }

// using CTAD (Class Template Argument Deduction)
std::vector numbers{1, 2, 3, 4, 5}
```

### Range-based for loops

```cpp
for (const auto number : numbers) {
  // do something with `number`
}
```
