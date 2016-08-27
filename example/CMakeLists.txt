cmake_minimum_required(VERSION 3.1)
project(TurtlebotTester C CXX)
set (CMAKE_CXX_STANDARD 11)

file(GLOB TESTER_SRC *.c *.cpp)

add_definitions(${TurtlebotLibrary_DEFINITIONS})
include_directories(${TurtlebotLibrary_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${TESTER_SRC})
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} TurtlebotLibrary)