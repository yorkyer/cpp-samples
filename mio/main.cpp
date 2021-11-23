#include<bits/stdc++.h>
#include<mio/mmap.hpp>

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Usage: mio <file>" << std::endl;
        exit(1);
    }

    // mio::mmap_source mmap(argv[1], 0, mio::map_entire_file);
    mio::mmap_sink mmap(argv[1], 0, mio::map_entire_file);
    for (auto& c : mmap) {
        std::cout << c;
    }
    mmap[10] = 'b';
    fill(mmap.begin(), mmap.end(), 'c');
    for (auto& c : mmap) {
        std::cout << c;
    }
    return 0;
}
