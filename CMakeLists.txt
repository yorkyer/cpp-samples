cmake_minimum_required(VERSION 3.14)
project(cpp-samples)

set(CMAKE_CXX_STANDARD 17)

include_directories(external/include)

# [REQUIRE] cd build; conan install ..
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

# Global variables for conan libs.
################################
# include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
# conan_basic_setup()

# add_executable(cpp main.cpp)
# target_link_libraries(cpp ${CONAN_LIBS})
################################

add_subdirectory(cppitertools)
add_subdirectory(backward-cpp)
add_subdirectory(pprint)
add_subdirectory(sanitize)
add_subdirectory(pystring)
add_subdirectory(taywee-args)
add_subdirectory(functionalplus)
