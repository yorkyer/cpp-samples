project(factory)

include_directories(.)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE 
        CONAN_PKG::backward-cpp 
        CONAN_PKG::spdlog 
        CONAN_PKG::fmt 
        CONAN_PKG::pystring
        CONAN_PKG::taywee-args
        CONAN_PKG::spy
        CONAN_PKG::mio)
add_link_options("-dynamic-list=symbols")

add_library(liba SHARED liba.cpp)
add_library(libb SHARED libb.cpp)