add_executable(test_PegMatcher
test_PegMatcher.cxx
${PROJECT_SOURCE_DIR}/src/PegPattern.cxx
${PROJECT_SOURCE_DIR}/src/PegMatcher.cxx
)

target_link_libraries(
    test_PegMatcher
    GTest::GTest
    GTest::Main
    )

include(GoogleTest)
gtest_discover_tests(test_PegMatcher)
