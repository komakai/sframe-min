# sframe, following Chromium's third_party/sframe/BUILD.gn: the BoringSSL
# backend only. Needs a `boringssl` target (boringssl-min).
cmake_minimum_required(VERSION 3.22)
project(sframe CXX)

add_library(sframe STATIC
  src/crypto.cpp
  src/crypto_boringssl.cpp
  src/header.cpp
  src/result.cpp
  src/sframe.cpp
)
# include/namespace.h replaces the one upstream's CMake generates.
target_include_directories(sframe PUBLIC include)
target_compile_definitions(sframe PRIVATE BORINGSSL)
target_link_libraries(sframe PRIVATE boringssl)
