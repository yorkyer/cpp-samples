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
    asm("nop \n  "
        "nop \n  "
        "nop");

    int foo = 1;
	asm("inc %[IncrementMe]" : [IncrementMe] "+r" (foo));
    P(foo);
    return 0;
}
