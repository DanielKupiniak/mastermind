add_executable(test_peg
test_Peg.cxx
${PROJECT_SOURCE_DIR}/src/Peg.cxx
${PROJECT_SOURCE_DIR}/src/Score.cxx
)

target_link_libraries(
    test_peg
    GTest::GTest
    GTest::Main
    )

include(GoogleTest)
gtest_discover_tests(test_peg)
