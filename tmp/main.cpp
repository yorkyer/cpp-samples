#include <bits/stdc++.h> 
#include <pprint.hpp>
#include <backward.hpp>
#include <spdlog/spdlog.h>
#include <pystring.h>
#include <mio/mmap.hpp>
#include <spy/spy.hpp>
#include <args.hxx>
#include <tscns.h>
#include <unistd.h>
#include <ctime>


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


using std::chrono::microseconds;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;

long long getTime() {
    return duration_cast<microseconds>(high_resolution_clock::now().time_since_epoch()).count();
}

void f(high_resolution_clock::duration du)
{
    long long before = getTime();
    std::this_thread::sleep_until(high_resolution_clock::now() + du);
    long long after = getTime();
    std::cout << before << std::endl;
    std::cout << after << std::endl;
    std::cout << after - before << std::endl;
}

long long TIME;

void accurate_sleep(long long du) {
    long long before = getTime();
    if (du <= 0) {
        long long after = getTime();
        std::cout << before << std::endl;
        std::cout << after << std::endl;
        std::cout << after - before << std::endl;
        return;
    }
    while (true) {
        long long time = getTime();
        if (time - before >= du) {
            break;
        }
    }
    long long after = getTime();
    std::cout << before << std::endl;
    std::cout << after << std::endl;
    std::cout << after - before << std::endl;
}
