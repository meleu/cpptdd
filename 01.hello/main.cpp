#include "hello.h"

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc > 1) {
    std::cout << hello(argv[1]) << '\n';
  } else {
    std::cout << hello() << '\n';
  }
}
