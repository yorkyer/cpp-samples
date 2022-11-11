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

template <long N>
long fibonacci()
{
    if constexpr(N < 2) { return N; }
    else { return fibonacci<N - 1>() + fibonacci<N - 2>(); }
}

template <long N>
long fibonacci(long n)
{
    if(n == N) return fibonacci<N>();
    return (n < 2) ? n : (fibonacci<N>(n - 1) + fibonacci<N>(n - 2));
}

template <typename T>
void PrintInfo(T x)
{
    if constexpr (std::is_same_v<T, string>)
    {
        std::cout << "string with length " << x.length() << std::endl;
    }
    else if constexpr (std::is_same_v<T, int>)
    {
        std::cout << "int" << std::endl;
    }
    else
    {
        std::cout << "some other type" << std::endl;
    }
}




int main(int argc, char **argv)
{

    return 0;
}
