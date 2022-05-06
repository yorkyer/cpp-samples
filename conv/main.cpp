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


const int out_w = 16;
const int in_w = 16;
const int kernel = 4;
const int in_c = 1;
const int out_c = 1;
const int stride = 1;
const int padding = 12;
const int dilation = 4;


void forward()
{
    float x_pack[out_w][kernel][in_c];

    for (int j = 0; j < out_w; j++) {
        int i0 = j * stride - padding;
        for (int l = 0; l < kernel; l++) {
            int i1 = i0 + l * dilation;
            if (i1 < 0 || i1 >= in_w) {
                for (int k = 0; k < in_c; k++) {
                    x_pack[j][l][k] = 0;
                    fmt::print("x_pack {} {} {} - 0\n", j, l , k);
                }
                    
            }
            else {
                for (int k = 0; k < in_c; k++)
                    // x_pack[j][l][k] = x.at(0, i1, k);
                    fmt::print("x_pack {} {} {} - x {} {}\n", j, l , k, i1, k);
            }
        }
    }
}


void forward_pre_fast()
{
    
}


void forward_pre()
{
    const int n = 0;
    const int start = out_w - 1;
    const int end = out_w;
    for (int j = start; j < end; j++) {
        int i0 = j * stride - padding;
        for (int i = 0; i < out_c; i++) {
            float s = 0;
            for (int l = 0; l < kernel; l++) {
                int i1 = i0 + l * dilation;
                if (i1 >= 0 && i1 < in_w - 1) { // skip the last input column
                    for (int k = 0; k < in_c; k++) {
                        fmt::print("inner for i k l {} {} {} - n i1 k {} {} {}\n", i, k, l, n, i1, k);
                        // s += w.at(i, k, l) * x.at(n, i1, k);
                        //if (j == out_w - 1)
                            //printf("[pre] %d %d %d - %f %f - %f\n", i, l, k, w.at(i, k, l), x.at(n, i1, k), s);
                    }
                }
            }
            // s += b.at(i);
            // y_pre.at(n, j - start, i) = s;
            fmt::print("y_pre {} {} {}\n", n, j-start, i);
        }
    }
}

template<int m, int n>
void gemv4_prepare_b(float *b, float *dst) {
    const int mc = 8 * 4;
    const int nc = 4;
    static_assert(n % nc == 0, "n % nc != 0");

    auto conv = [&](float *x, int len) {
        while (len--)
            *(dst++) = *(x++);
    };

    int i = 0;
    for (int c : {mc, 16, 8, 4}) {
        for (; i + c <= m; i += c) {
            for (int j = 0; j < n; j++) {
                fmt::print("b {} {}\n", j * m + i, c);
                conv(&b[j * m + i], c);
            }
                
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i0 = i; i0 < m; i0++) {
            fmt::print("bb {} {}\n", j * m + i0, 1);
            conv(&b[j * m + i0], 1);
        }
    }
}


int prepare(int argc, char **argv)
{
    const int SIZE = 10000;
    float a[SIZE];
    float b[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        a[i] = i;
        b[i] = 0;
    }

    gemv4_prepare_b<32, 8>(a, b);

    for (int i = 0; i < SIZE; i++) {
        fmt::print("{} ", b[i]);
        if (i % 50 == 0) {
            fmt::print("\n");
        }
    }

    return 0;
}


int main(int argc, char **argv)
{
    forward_pre();

    return 0;
}