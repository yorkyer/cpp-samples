cmake_minimum_required(VERSION 3.10)
project(cpp-samples)

set(CMAKE_CXX_STANDARD 17)

include_directories(external/include)

# [REQUIRE] cd build; conan install ..
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_subdirectory(cppitertools)

# include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
# conan_basic_setup()

# add_executable(cpp main.cpp)
# target_link_libraries(cpp ${CONAN_LIBS})
