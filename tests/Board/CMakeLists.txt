add_executable(test_Board
test_Board.cxx
${PROJECT_SOURCE_DIR}/src/PegPattern.cxx
${PROJECT_SOURCE_DIR}/src/Score.cxx
)

target_link_libraries(
    test_Board
    GTest::GTest
    GTest::Main
    )

include(GoogleTest)
gtest_discover_tests(test_Board)
