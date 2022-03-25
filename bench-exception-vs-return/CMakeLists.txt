project(bench-exception-vs-return)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} CONAN_PKG::benchmark)
target_compile_options(${PROJECT_NAME} PRIVATE -m64 -mavx2 -mfma)
