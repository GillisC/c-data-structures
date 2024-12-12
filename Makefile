# Define directories
BUILD_DIR := build

MAIN_PROGRAM := $(BUILD_DIR)/main_program
TEST_PROGRAM := $(BUILD_DIR)/tests/test_program

# Tools
CMAKE := $(shell which cmake)

# Targets
.PHONY: all config build test clean

all: config build

config:
	@echo "Configuring the project..."
	@$(CMAKE) -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=Debug

build:
	@echo "Building the project..."
	@$(CMAKE) --build $(BUILD_DIR)

install:
	@echo "Installing dependencies..."
	@./vcpkg/vcpkg install cunit

run: build
	@echo "Running main program...\n"
	@$(MAIN_PROGRAM)

test: build
	@echo "Running tests...\n"
	@$(TEST_PROGRAM)

clean:
	@echo "Cleaning up...\n"
	@rm -rf $(BUILD_DIR)
	