cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)

find_package(Threads REQUIRED)
add_definitions(${TurtlebotLibrary_DEFINITIONS})
include_directories(${TurtlebotLibrary_INCLUDE_DIRS})

file( GLOB TURTLEBOT_EXAMPLE_SRC *.cpp )
foreach( example_file ${TURTLEBOT_EXAMPLE_SRC} )
    get_filename_component(exec_name ${example_file} NAME_WE)
    add_executable( ${exec_name} ${example_file} )
    target_link_libraries(${exec_name} TurtlebotLibrary ${CMAKE_THREAD_LIBS_INIT})
endforeach( example_file ${TURTLEBOT_EXAMPLE_SRC} )
