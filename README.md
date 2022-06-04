# Pimpl Idiom Example
Basic Pointer-To-Implementation (Pimpl) Example with using unique pointer.

When using the Pimpl idiom, define special member functions in the implementation file.

Tested both on Ubuntu 20.04 and Windows 10

# Requirements
    * CMake
    * Gcc or Clang compiler

## Compilation and Run on Linux
```bash
mkdir build
cd build
cmake ..
make -j 4
./bin/RunSample
```