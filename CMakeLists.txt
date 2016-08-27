cmake_minimum_required(VERSION 3.1)

if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif ()

# Remove 'lib' prefix for shared libraries on Windows
if (WIN32)
  set(CMAKE_SHARED_LIBRARY_PREFIX "")
endif ()

add_subdirectory(src)
add_subdirectory(example)