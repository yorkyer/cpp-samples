#!/usr/bin/env bash

if [[ $# -ne 1 ]]; then
    echo "Usage: ./new-sample.sh <name>"
    echo "Example: ./new-sample.sh copy-elision"
    exit 2
fi

name=$1
mkdir $name

echo "add_subdirectory(${name})" >> CMakeLists.txt

cd $name

cat <<EOF > CMakeLists.txt
project(${name})

add_executable(\${PROJECT_NAME} main.cpp)
target_link_libraries(\${PROJECT_NAME} PRIVATE 
        CONAN_PKG::backward-cpp 
        CONAN_PKG::spdlog 
        CONAN_PKG::fmt 
        CONAN_PKG::pystring
        CONAN_PKG::taywee-args
        CONAN_PKG::spy
        CONAN_PKG::doctest
        CONAN_PKG::mio)
EOF

cat <<EOF > main.cpp
#include <bits/stdc++.h> 
#include <pprint.hpp>
#include <backward.hpp>
#include <spdlog/spdlog.h>
#include <pystring.h>
#include <mio/mmap.hpp>
#include <spy/spy.hpp>
#include <args.hxx>
#include <tscns.h>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

namespace backward
{
    backward::SignalHandling sh;
}

using namespace std;

#define P(...) \\
do { \\
    pprint::PrettyPrinter printer; \\
    printer.quotes(false); \\
    printer.compact(false); \\
    printer.print(__VA_ARGS__); \\
} while (0)


int main(int argc, char **argv)
{

    return 0;
}
EOF

cd ..
