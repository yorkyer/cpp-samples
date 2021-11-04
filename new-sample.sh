#!/usr/bin/env bash

if [[ $# -ne 1 ]]; then
    echo "Usage: ./new-sample.sh <library>"
    echo "Example: ./new-sample.sh pprint"
    exit 2
fi

name=$1
mkdir $name

echo "add_subdirectory(${name})" >> CMakeLists.txt

cd $name

cat <<EOF > CMakeLists.txt
project(${name})

add_executable(\${PROJECT_NAME} main.cpp)
target_link_libraries(\${PROJECT_NAME} CONAN_PKG::${name})
EOF

cat <<EOF > main.cpp
#include <iostream>
#include <${name}.hpp>

using namespace std;

int main()
{

    return 0;
}
EOF

cd ..
