project(sanitize)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=leak")

add_executable(${PROJECT_NAME} main.cpp)