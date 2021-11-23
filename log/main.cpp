#include<bits/stdc++.h> 
#include <fmt/core.h>
using namespace std;

#ifndef NDEBUG
#define LOG(...) \
do { \
    fmt::print("[{}] ", __FUNCTION__); \
    fmt::print(__VA_ARGS__); \
    fmt::print(" [{}:{}]", __FILE__, __LINE__); \
    fmt::print("\n"); \
    fflush(stdout); \
} while (0)
#else
#define LOG(...)
#endif

int main(int argc, char **argv)
{
    LOG("hi {}", 1);
    LOG("hi {}", 2);
    LOG("hi {}", 3);
}
