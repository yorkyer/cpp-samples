project(cppitertools)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} CONAN_PKG::cppitertools)