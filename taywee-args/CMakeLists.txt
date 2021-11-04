project(taywee-args)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} CONAN_PKG::taywee-args)
