#include <bits/stdc++.h> 
#include <pprint.hpp>
#include <backward.hpp>
#include <spdlog/spdlog.h>
#include <pystring.h>
#include <mio/mmap.hpp>
#include <spy/spy.hpp>
#include <args.hxx>
#include <tscns.h>
#include <csv.h>
#include <cctype>


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
    std::vector<double> row;
    fstream fin("coef.csv");
    
    std::string line, word, temp;
    getline(fin, line);
    // P(line);
    while (getline(fin, line)) {
        stringstream s(line);
        while (getline(s, word, ',')) {
            if (word.empty() || std::all_of(word.begin(), word.end(), [](auto c){ return std::isspace(c); }))
                P(0);
            else
                P(std::stod(word));
        }
    }
    return 0;
}
