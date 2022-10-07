#include <bits/stdc++.h> 
#include <pprint.hpp>
#include <backward.hpp>
#include <spdlog/spdlog.h>
#include <pystring.h>
#include <mio/mmap.hpp>
#include <spy/spy.hpp>
#include <args.hxx>
#include <tscns.h>
#include <immintrin.h>
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

inline int64_t rdtsc()
{
    uint64_t rax, rdx, aux;
    asm volatile ( "rdtscp\n" : "=a" (rax), "=d" (rdx), "=c" (aux) : : );
    return (rdx << 32) + rax;
}

constexpr static int L3_CACHE_SIZE = 40 * 1024 * 1024;
std::vector<float> big_array(L3_CACHE_SIZE / sizeof(float));
float sum;
void flush_cache() {
    for (size_t i = 0; i < big_array.size(); i++)
        sum += big_array[i];
}


constexpr int PASS = 1000;
std::vector<int64_t> diffs(PASS);


__m256i tmp;
__m256i tmp2;
alignas(128) int mem[64];

void bench()
{
    for (int i = 0; i < PASS; i++) {
        // flush_cache();
        auto start = rdtsc();
        
        _mm256_stream_si256((__m256i *)mem, tmp);

        auto end = rdtsc();
        diffs[i] = end - start;
    }
    std::sort(diffs.begin(), diffs.end());
    std::cout << "no_warmup," << diffs[(int) (PASS * 0.05)] << "," << diffs[(int) (PASS * 0.5)] << ","
              << diffs[(int) (PASS * 0.95)] << std::endl;
}

void bench2()
{
    for (int i = 0; i < PASS; i++) {
        // flush_cache();
        auto start = rdtsc();
        
        _mm256_store_si256((__m256i *)mem, tmp2);

        auto end = rdtsc();
        diffs[i] = end - start;
    }
    std::sort(diffs.begin(), diffs.end());
    std::cout << "no_warmup," << diffs[(int) (PASS * 0.05)] << "," << diffs[(int) (PASS * 0.5)] << ","
              << diffs[(int) (PASS * 0.95)] << std::endl;
}

int main(int argc, char **argv)
{
    bench();    
    bench2();    
    return 0;
}
