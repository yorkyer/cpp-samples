#include <bits/stdc++.h> 
#include <pprint.hpp>
#include <backward.hpp>
#include <spdlog/spdlog.h>
#include <pystring.h>
#include <mio/mmap.hpp>
#include <spy/spy.hpp>
#include <args.hxx>
#include <tscns.h>


namespace backward
{
    backward::SignalHandling sh;
}


using namespace std;


#define P(...) \
do { \
    pprint::PrettyPrinter printer; \
    printer.quotes(false); \
    printer.compact(false); \
    printer.print(__VA_ARGS__); \
} while (0)

struct O {
    int a;
    int b;
};

int main(int argc, char **argv)
{
    std::unordered_map<int, int> m;
    m[1] = 1;

    auto it = m.find(1);
    std::cout << &(*it) << std::endl;
    std::cout << "current bucket_count: " << m.bucket_count() << std::endl;

    for (int i = -100; i < 100; ++i) {
        m[i] = i;
    }

    std::cout << &(*it) << " " << it->second << std::endl;
    std::cout << &(m[1]) << std::endl;
    std::cout << "current bucket_count: " << m.bucket_count() << std::endl;

    std::vector<int> v;
    v.push_back(1);
    auto iter = v.begin();
    std::cout << &(*iter) << std::endl;


    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
    }

    std::cout << &(*iter) << " " << *iter << std::endl;
    std::cout << &(*v.begin()) << std::endl;

    return 0;
}
