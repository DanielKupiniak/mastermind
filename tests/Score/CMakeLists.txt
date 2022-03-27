add_executable(test_Score
test_Score.cxx
${PROJECT_SOURCE_DIR}/src/Peg.cxx
${PROJECT_SOURCE_DIR}/src/Score.cxx
)

target_link_libraries(
    test_Score
    GTest::GTest
    GTest::Main
    )

include(GoogleTest)
gtest_discover_tests(test_Score)
