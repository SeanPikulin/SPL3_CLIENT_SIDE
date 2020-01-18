cmake_minimum_required(VERSION 3.15)
project(SPL3)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
include_directories(include)
include_directories(src)
link_libraries("-lboost_system")
link_libraries("-pthread")

add_executable(SPL3 src/echoClient.cpp src/connectionHandler.cpp include/connectionHandler.h src/IOThread.cpp include/IOThread.h src/BookClub.cpp include/BookClub.h src/ServerThread.cpp include/ServerThread.h src/Frame.cpp include/Frame.h)
