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
- `#include <file.h>` when it's a 3rd party lib.
  - sometimes the `.h` is omitted (like in `#include <iostream>`)
