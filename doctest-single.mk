# Shared build rules for single-file C++ projects tested with doctest,
# where the tests live inside the .cpp file itself.
#
# Include it from a project's Makefile, e.g.:
# ```
# include ../../doctest-single.mk
# ```
#
#   make test   -> build with tests and run only the tests
#   make build  -> build the executable without the test code
#   make run    -> build (no tests) and run the program
#
# Choose the file with SRC, e.g.: make test SRC=foo.cpp
# If SRC isn't given and there's only one .cpp here, that one is used.

CXX       := clang++
CXXFLAGS  ?= -std=c++23 -Wall -Wextra -Wpedantic

# Directory for all generated files
BUILD_DIR := build

SRC       ?= $(wildcard *.cpp)

# Binary name comes from the source file: foo.cpp -> foo
NAME      := $(basename $(notdir $(firstword $(SRC))))

# Exactly one source file is needed (except for `make clean`)
ifneq ($(MAKECMDGOALS),clean)
  ifneq ($(words $(SRC)),1)
    $(error Pick one source file with SRC=<file>.cpp (found: $(or $(SRC),none)))
  endif
endif

.DEFAULT_GOAL := test

# Pass extra doctest flags with ARGS, e.g.: make test ARGS='-s'
test: $(BUILD_DIR)/$(NAME)_test
	./$< --exit $(ARGS)

build: $(BUILD_DIR)/$(NAME)

run: $(BUILD_DIR)/$(NAME)
	./$<

# Test build: doctest is enabled, so the TEST_CASEs are compiled in
# (each recipe creates $(BUILD_DIR) itself: a `$(BUILD_DIR)` target would
# clash with the `build` target)
$(BUILD_DIR)/$(NAME)_test: $(SRC)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $< -o $@

# Release build: DOCTEST_CONFIG_DISABLE strips out all the test code
$(BUILD_DIR)/$(NAME): $(SRC)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -O2 -DDOCTEST_CONFIG_DISABLE $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: test build run clean
