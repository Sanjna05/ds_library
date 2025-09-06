cmake_minimum_required(VERSION 3.24)
project(ds_library C)

set(CMAKE_C_STANDARD 11)

# Include header files
include_directories(include)

# Source files
file(GLOB SRC_FILES "src/*.c")
file(GLOB HEADER_FILES "include/*.h")

# Test files
file(GLOB TEST_FILES "tests/*.c" "tests/placement_problems/*.c")

# Main executable
add_executable(ds_library main.c ${SRC_FILES} ${HEADER_FILES})

# Test executable
add_executable(run_tests ${TEST_FILES} ${SRC_FILES})
