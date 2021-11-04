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
EOF

cat <<EOF > main.cpp
#include<bits/stdc++.h> 

using namespace std;

int main(int argc, char **argv)
{

    return 0;
}
EOF

cd ..
