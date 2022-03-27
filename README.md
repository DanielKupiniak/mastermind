# mastermind
Project build using CMake version 3.16. Choosen gtest as a testframework.
Compilation works under WSL2, and should on Linux systems
## Compilation
```
mkdir build && cd build
cmake ..
cmake --build . -j $(nproc)
```
## Run program
compiled application found at build/src/mastermind
## Test
To run tests
```
cd build
ctests
```
