find_package(GTest REQUIRED)

add_executable(test_mastermind
test_mastermind.cxx
${PROJECT_SOURCE_DIR}/src/Peg.cxx
)

target_link_libraries(
    test_mastermind
    # gtest_main
    GTest::GTest
    GTest::Main
    )

include(GoogleTest)
gtest_discover_tests(test_mastermind)
