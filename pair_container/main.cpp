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


template < template< typename K, typename V> typename Container >
class PairContainer {
    Container container;

    Container::iterator begin() { return container.begin(); }
    Container::iterator end() { return container.end(); }
};


int main(int argc, char **argv)
{

    return 0;
}
