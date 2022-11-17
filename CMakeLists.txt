cmake_minimum_required(VERSION 3.19)
project(SimpleAsyncThread)

set(CMAKE_CXX_STANDARD 17)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

add_executable(SimpleAsyncThread main.cpp)