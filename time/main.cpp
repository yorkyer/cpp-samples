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
// 2019-06-25T01:20:12.923541588Z -> microseconds
long long utc2nanoTimestamp(const std::string &utc) {
    std::tm tm = {};
    std::stringstream ss(utc);
    ss >> std::get_time(&tm, "%y-%m-%dT%H:%M:%S");
    tm.tm_hour += 8;
    auto timestamp = std::mktime(&tm);
    return timestamp * 1000'000'000 + std::stoi(utc.substr(utc.size() - 10, 9));
}

// 03:56:44.325000000 -> milliseconds
int time2timestamp(const std::string &time) {
    int hour = std::stoi(time.substr(0, 2));
    int minute = std::stoi(time.substr(3, 2));
    int second = std::stoi(time.substr(6, 2));
    int millisecond = std::stoi(time.substr(9, 3));

    return hour * 10000000 + minute * 100000 + second * 1000 + millisecond;
}


// @param timestamp int64_t supported timestamp resolution: seconds, milliseconds, microseconds, nanoseconds
// @return int hhmmssMMM (hh: hour, mm: minute, ss: second, MMM: millisecond)
// @warning Supported date range: 1970-12-14 ~ 2920-08-30
int getTimeFromTimestamp(int64_t timestamp) {
    int milliseconds = 0;
    if (timestamp > (int64_t)3e16) { // nanoseconds timestmap
        milliseconds = (timestamp % (int64_t)1e9) / (int64_t)1e6;
        timestamp /= (int64_t)1e9;
    }
    else if (timestamp > (int64_t)3e13) { // microseconds timestmap
        milliseconds = (timestamp % (int64_t)1e6) / (int64_t)1e3;
        timestamp /= (int64_t)1e6;
    }
    else if (timestamp > (int64_t)3e10) { // milliseconds timestmap
        milliseconds = (timestamp % (int64_t)1e3);
        timestamp /= (int64_t)1e3;
    }
    else if (timestamp > (int64_t)3e7) { // seconds timestmap
        // pass
    }
    else { // Don't support this.
        return 0;
    }

    timestamp %= (24 * 60 * 60);
    int hour = timestamp / (60 * 60) + 8;
    timestamp %= (60 * 60);
    int minute = timestamp / 60;
    timestamp %= 60;
    int second = timestamp;
    return hour * 10000000 + minute * 100000 + second * 1000 + milliseconds;
}


// @param timestamp int64_t supported timestamp resolution: seconds, milliseconds, microseconds, nanoseconds
// @return int yyyymmdd (yyyy: yera, mm: month, dd: day)
// @warning Supported date range: 1970-12-14 ~ 2920-08-30
int getDateFromTimestamp(int64_t timestamp) {
    if (timestamp > (int64_t)3e16) { // nanoseconds timestmap
        timestamp /= (int64_t)1e9;
    }
    else if (timestamp > (int64_t)3e13) { // microseconds timestmap
        timestamp /= (int64_t)1e6;
    }
    else if (timestamp > (int64_t)3e10) { // milliseconds timestmap
        timestamp /= (int64_t)1e3;
    }
    else if (timestamp > (int64_t)3e7) { // seconds timestmap
        // pass
    }
    else { // Don't support this.
        return 0;
    }

    std::time_t seconds = timestamp;
    std::tm datetime;
    ::localtime_r(&seconds, &datetime);
    return (1900 + datetime.tm_year) * 10000 + (1 + datetime.tm_mon) * 100 + datetime.tm_mday;
}


//1561425612923541 (2019-06-25T01:20:12.923541 -> 092012923
int getTimeFromTimestamp(long long ts, bool isNano) {
    if (isNano) {
        ts /= 1000;
    }
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

int getDateFromTimestamp(long long ts, bool isNano) {
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
    std::locale::global(std::locale("en_US.UTF8"));
    fmt::print("{:L}\n", utc2timestamp("9000-01-1T00:00:00.000000000Z"));
    fmt::print("{:L}\n", utc2nanoTimestamp("1980-01-1T00:00:00.000000000Z"));
    std::cout << getDateFromTimestamp(1577928600020000000) << std::endl;
    std::cout << getTimeFromTimestamp(1577928600020000000) << std::endl;
    std::cout << getDateFromTimestamp(1577928600020000) << std::endl;
    std::cout << getTimeFromTimestamp(1577928600020000) << std::endl;
    std::cout << getDateFromTimestamp(1577928600020) << std::endl;
    std::cout << getTimeFromTimestamp(1577928600020) << std::endl;
    std::cout << getDateFromTimestamp(1577928600) << std::endl;
    std::cout << getTimeFromTimestamp(1577928600) << std::endl;

    std::cout << getDateFromTimestamp(1639359048163936000) << std::endl;
    std::cout << getTimeFromTimestamp(1639359048163936000) << std::endl;
    std::cout << getDateFromTimestamp(1639359048163936) << std::endl;
    std::cout << getTimeFromTimestamp(1639359048163936) << std::endl;
    std::cout << getDateFromTimestamp(1639359048163) << std::endl;
    std::cout << getTimeFromTimestamp(1639359048163) << std::endl;
    std::cout << getDateFromTimestamp(1639359048) << std::endl;
    std::cout << getTimeFromTimestamp(1639359048) << std::endl;
    // std::cout << getTimeFromTimestamp(9'503'593'600'000'000, true) << std::endl;
    // std::cout << getTimeFromTimestamp(1577928600020000000, true) << std::endl;
    // std::cout << getDateFromTimestamp(1639359048163936, false) << std::endl;
    // std::cout << time2timestamp("03:56:44.325000000");
    return 0;
}
