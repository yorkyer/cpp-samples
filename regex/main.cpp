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
    std::string time = "03:56:44.325000000";
    std::regex reg("(\\d+):(\\d+):(\\d+)\\.(\\d+)");
    std::smatch match_result;
    if (std::regex_match(time, match_result, reg)) {
        for (size_t i = 0; i < match_result.size(); ++i) {
            std::cout << i << ": " << match_result[i].str() << std::endl;
        }
    }
    return 0;
}
