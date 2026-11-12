cmake_minimum_required(VERSION 3.22)
project(CollatzSequence LANGUAGES CXX)
include(FetchContent)
FetchContent_Declare(bigint
  GIT_REPOSITORY https://github.com/faheel/BigInt.git
  GIT_TAG 18a5cac389bbdc889d24264c00e44c5e0f4dce48
  SOURCE_SUBDIR no-cmake-project)
FetchContent_MakeAvailable(bigint)
add_library(collatz CollatzSequence/Collatz.cpp)
target_include_directories(collatz PUBLIC CollatzSequence "${bigint_SOURCE_DIR}/include")
target_compile_features(collatz PUBLIC cxx_std_17)
add_executable(collatz_app CollatzSequenceApplication/Main.cpp)
target_link_libraries(collatz_app PRIVATE collatz)
enable_testing()
add_executable(collatz_smoke CollatzSequenceTests/smoke.cpp)
target_link_libraries(collatz_smoke PRIVATE collatz)
add_test(NAME collatz_smoke COMMAND collatz_smoke)

FetchContent_Declare(googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG 52eb8108c5bdec04579160ae17225d66034bd723)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
add_executable(collatz_tests CollatzSequenceTests/CollatzTests.cpp)
target_link_libraries(collatz_tests PRIVATE collatz GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(collatz_tests)
