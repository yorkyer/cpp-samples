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
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfenv>
#include <cfloat>
#include <cinttypes>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <strstream>
#include <tuple>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{

    return 0;
}
EOF

cd ..
