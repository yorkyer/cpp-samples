#include <bits/stdc++.h> 
#include <pprint.hpp>
#include <backward.hpp>
#include <spdlog/spdlog.h>
#include <pystring.h>
#include <mio/mmap.hpp>
#include <spy/spy.hpp>
#include <args.hxx>
#include <tscns.h>
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


// 2019-06-25T01:20:12.923541588Z -> microseconds
long long utc2timestamp(const std::string &utc) {
    std::tm tm = {};
    std::stringstream ss(utc);
    ss >> std::get_time(&tm, "%y-%m-%dT%H:%M:%S");
    tm.tm_hour += 8;
    auto timestamp = std::mktime(&tm);
    return timestamp * 1000'000 + std::stoi(utc.substr(utc.size() - 10, 6));
}

// 03:56:44.325000000 -> milliseconds
int time2timestamp(const std::string &time) {
    int hour = std::stoi(time.substr(0, 2));
    int minute = std::stoi(time.substr(3, 2));
    int second = std::stoi(time.substr(6, 2));
    int millisecond = std::stoi(time.substr(9, 3));

    return hour * 10000000 + minute * 100000 + second * 1000 + millisecond;
}

//1561425612923541 (2019-06-25T01:20:12.923541 -> 092012923
int getTimeFromTimestamp(long long ts) {
    long long microsecond = ts % 1000000;
    ts /= 1000000;
    ts %= (24 * 60 * 60);
    int hour = ts / (60 * 60) + 8;
    ts %= (60 * 60);
    int minute = ts / 60;
    ts %= 60;
    int second = ts;
    return hour * 10000000 + minute * 100000 + second * 1000 + microsecond / 1000;
}

int getDateFromTimestamp(long long ts, bool isNano = false) {
    if (isNano) {
        ts /= 1000;
    }
    std::time_t seconds = ts / 1000000;
    std::tm datetime;
    ::localtime_r(&seconds, &datetime);
    return (1900 + datetime.tm_year) * 10000 + (1 + datetime.tm_mon) * 100 + datetime.tm_mday;
}

int main(int argc, char **argv)
{
    // auto timestamp = utc2timestamp("2019-06-25T01:20:12.923541588Z");
    // std::cout << timestamp << std::endl;
    double t = (double) 1629775591721377;
    // std::cout << (long long)t;
    std::cout << getDateFromTimestamp(1629775591721377415, true) << std::endl;
    // std::cout << time2timestamp("03:56:44.325000000");
    return 0;
}
