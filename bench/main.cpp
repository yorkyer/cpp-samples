#include <bits/stdc++.h> 
#include <pprint.hpp>
#include <backward.hpp>
#include <spdlog/spdlog.h>
#include <pystring.h>
#include <mio/mmap.hpp>
#include <spy/spy.hpp>
#include <args.hxx>
#include <tscns.h>
#include "LatencyStat.hpp"


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


constexpr int COUNT = 1000;
constexpr int PASS = 3;
TSCNS tscns;


constexpr static int L3_CACHE_SIZE = 40 * 1024 * 1024;
std::vector<float> big_array(L3_CACHE_SIZE / sizeof(float));
float sum;
void flush_cache() {
    for (size_t i = 0; i < big_array.size(); i++)
        sum += big_array[i];
}

struct A {
    int a;
    int b;
};
A a;

void bench(int size)
{
    {   
        std::vector<A> v;
        LatencyStat stat("f1", COUNT);
        for (int i = 0; i < PASS * COUNT; i++) {
            flush_cache();
            auto t0 = tscns.rdns();
            A a;
            a.a = 1;
            a.b = 2;
            v.push_back(a);
            auto t1 = tscns.rdns();
            stat.stat(t1 - t0, true);
        }
        sum += v.size();
    }

    {
        std::vector<A> v;
        LatencyStat stat("f2", COUNT);
        for (int i = 0; i < PASS * COUNT; i++) {
            flush_cache();
            auto t0 = tscns.rdns();
            v.emplace_back(1, 2);
            auto t1 = tscns.rdns();
            stat.stat(t1 - t0, true);
        }
        sum += v.size();
    }
}



int main(int argc, char **argv)
{
    tscns.init();
    bench(100);    

    std::cout << sum << std::endl;
    
    return 0;
}
