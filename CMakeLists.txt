cmake_minimum_required(VERSION 3.16)
project(mastermind VERSION 0.1.0)
enable_testing()

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(tests)
# add_subdirectory(doc)
