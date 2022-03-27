add_executable(mastermind
    main.cpp
    Peg.cxx
    Score.cxx)

# target_link_libraries(
#     mastermind
#     PRIVATE
# )

target_include_directories(mastermind PRIVATE "${CMAKE_BINARY_DIR}/include")