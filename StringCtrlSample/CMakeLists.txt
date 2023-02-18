cmake_minimum_required(VERSION 3.22)
project(StringCtrlSample)

set(CMAKE_CXX_STANDARD 11)

add_executable(StringCtrlSample main.cpp CMyString/CMyString.cpp CMyString/CMyString.h CMyStringEx/CMyStringEx.cpp CMyStringEx/CMyStringEx.h)
#add_executable(StringCtrlSample main.cpp CMyString/CMyString.cpp)
