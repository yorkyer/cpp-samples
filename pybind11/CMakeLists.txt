project(pybind11)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE 
        CONAN_PKG::backward-cpp 
        CONAN_PKG::spdlog 
        CONAN_PKG::fmt 
        CONAN_PKG::pystring
        CONAN_PKG::taywee-args
        CONAN_PKG::spy
        CONAN_PKG::mio)

set(pybind11_DIR /usr/local/lib/python3.6/dist-packages/pybind11/share/cmake/pybind11)
find_package(pybind11 CONFIG REQUIRED)
pybind11_add_module(example mult.cpp)

# g++ -O3 -Wall -Werror -shared -std=c++11 -fPIC -I/usr/include/python3.6m -I/usr/local/lib/python3.6/dist-packages/pybind11/include -I /usr/include/python3.6 -I. wrapper.cpp -o example.cpython-36m-x86_64-linux-gnu.so -L. -lmult -Wl,-rpath,.