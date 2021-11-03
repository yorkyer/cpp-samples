#include <vector>
#include <iostream>
#include <cppitertools/itertools.hpp>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v{1,2,3,4,5};
    for (auto&& vec : iter::permutations(v)) {
        for (auto&& i : vec) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}
