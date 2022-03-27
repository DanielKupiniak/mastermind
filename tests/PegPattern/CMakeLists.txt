add_executable(test_pegpattern
test_PegPattern.cxx
${PROJECT_SOURCE_DIR}/src/PegPattern.cxx
${PROJECT_SOURCE_DIR}/src/Score.cxx
)

target_link_libraries(
    test_pegpattern
    GTest::GTest
    GTest::Main
    )

include(GoogleTest)
gtest_discover_tests(test_pegpattern)
