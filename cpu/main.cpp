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



int main(int argc, char **argv)
{
    if (!__builtin_cpu_supports("mmx"))
        std::cout << "No MMX support" << std::endl;
    if (!__builtin_cpu_supports("avx512f"))
        std::cout << "No avx512f support" << std::endl;
    return 0;
}
