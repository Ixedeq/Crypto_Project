cmake_minimum_required(VERSION 3.14)
project(crypto_proj)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
 crypto_tests
 crypto_tests.cc
)

target_link_libraries(
 crypto_tests
 GTest::gtest_main
 )

 add_test(CryptoProblems crypto_tests)
 add_test(HexToBytesTests crypto_tests)
 add_test(BinaryToHexTests crypto_tests)
 add_test(FixedXorTests crypto_tests)
 add_test(B64DecoderTests crypto_tests)
 add_test(CharToByteTests crypto_tests)
 add_test(scoreEnglishTextTests crypto_tests)
 
 include(GoogleTest)
 gtest_discover_tests(crypto_tests)
