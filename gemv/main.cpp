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



extern void gemv4(const float *a, const float *b, const float *c, float *d); /* Prototype */

constexpr int SIZE = 1000;

float a[SIZE] ;
float b[SIZE * SIZE] ;
float c[SIZE] ;
float d[SIZE] ;

int main() {
    for (int i = 0; i < 32; ++i) {
        c[i] = i;
        a[i] = i + i;
        b[i] = i * i;
    }
    gemv4(a, b, c, d);
    for (int i = 0; i < 32; ++i) {
        std::cout << d[i] << " ";
    }
    return 0;
}