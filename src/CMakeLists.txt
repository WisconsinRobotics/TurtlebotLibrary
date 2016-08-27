cmake_minimum_required(VERSION 3.1)
project(TurtlebotLibrary)

set (TurtlebotLibrary_VERSION_MAJOR 1)
set (TurtlebotLibrary_VERSION_MINOR 0)
set (CMAKE_CXX_STANDARD 11)

find_package(Threads REQUIRED)
include_directories(../include)
file(GLOB TURTLEBOT_LIBRARY_SRC *.cpp *.c msg/*.cpp)

if(MSVC)
    # Force to always compile with W4
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-missing-field-initializers -pedantic")
endif()

add_library(${PROJECT_NAME} STATIC ${TURTLEBOT_LIBRARY_SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREADS_LIBS_INIT})

# Expose public includes to other subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ../include
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)