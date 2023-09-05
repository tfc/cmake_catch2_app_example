cmake_minimum_required(VERSION 3.12)
project(example CXX)

#### Library

add_library(lib src/lib.cpp)
add_library(lib::lib ALIAS lib)

target_include_directories(lib
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  )

#### App

add_executable(hello app/main.cpp)
target_link_libraries(hello PRIVATE lib::lib)

#### Tests

find_package(Catch2 REQUIRED)

include(CTest)
include(Catch)

add_executable(tests
  test/main.cpp
  test/lib.cpp
  )
target_link_libraries(tests
  PRIVATE
  Catch2::Catch2
  lib::lib
  )
catch_discover_tests(tests)
