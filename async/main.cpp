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

bool stop{false};

void loop() {
    while (!stop) {

    }
}


struct A {
    future<void> outcome;
    ~A() {
        stop = true;
    }
};


int main()
{
    A a;
    a.outcome = std::async(std::launch::async, loop);
    return 0;
}
