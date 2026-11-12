# C++ Collatz sequence

Requires CMake 3.22+, Git, and a C++17 compiler. The first configure downloads GoogleTest and upstream [BigInt](https://github.com/faheel/BigInt) at a pinned commit; later builds can use the cached checkout. Open this directory as a CMake project in Visual Studio, or run:

```sh
cmake -S C++ -B build/collatz-cpp
cmake --build build/collatz-cpp
ctest --test-dir build/collatz-cpp --output-on-failure
```

Run `collatz_app` from the build directory. The BigInt dependency is MIT licensed; its license is included in the downloaded source.
