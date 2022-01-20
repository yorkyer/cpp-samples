include(CMakePrintHelpers)
cmake_print_variables(CMAKE_BUILD_TYPE)

project(benchmark)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} CONAN_PKG::benchmark)
