#include <bits/stdc++.h> 
#include <pprint.hpp>
#include <backward.hpp>
#include <spdlog/spdlog.h>
#include <pystring.h>
#include <mio/mmap.hpp>
#include <spy/spy.hpp>
#include <args.hxx>
#include <robin_hood.h>
#include <RollingMinMaxQueue.hpp>
#include <HistoricalQueue.hpp>


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

const std::vector<int> window_sizes{1, 2, 4};

int main() {

    sta::RollingMinMaxQueue q(6);
    sta::HistoricalQueue<int> hq(window_sizes);

    q.push_back(0, 0);
    q.push_back(1, 1);
    q.push_back(2, 2);
    // q.push_back(3, 3);
    // q.push_back(4, 4);
    // q.push_back(5, 5);
    // q.push_back(6, 6);
    // q.push_back(7, 7);
    // q.push_back(8, 8);
    q.push_back(9, 9);

    P(q.max());
    P(q.min());

    // hq.push_back(0, 0);
    // hq.push_back(1, 1);
    // hq.push_back(2, 2);
    // hq.push_back(3, 3);
    // hq.push_back(4, 4);
    // hq.push_back(5, 5);
    // hq.push_back(6, 6);
    // hq.push_back(7, 7);
    // // hq.push_back(8, 8);
    hq.push_back(9, 9);
    P(hq.get_lagging(9, 0));
    P(hq.get_lagging(9, 1));
    P(hq.get_lagging(9, 2));

    return 0;
}