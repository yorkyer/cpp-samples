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

#define P(...)                         \
    do                                 \
    {                                  \
        pprint::PrettyPrinter printer; \
        printer.quotes(false);         \
        printer.compact(false);        \
        printer.print(__VA_ARGS__);    \
    } while (0)

int sum;

void g()
{
    for (int i = 0; i < 100; i++)
    {
        sum++;
        sum *= 10;
        sum /= 7;
        sum %= 4;
        sum *= 10;
        sum /= 7;
        sum %= 4;
        sum *= 10;
        sum /= 7;
        sum %= 4;
    }
}

void h()
{
    for (int i = 0; i < 100; i++)
    {
        sum++;
        sum *= 10;
        sum /= 7;
        sum %= 4;
        sum *= 10;
        sum /= 7;
        sum %= 4;
        sum *= 10;
        sum /= 7;
        sum %= 4;
    }
}

void f()
{
    for (int i = 0; i < 2000000; i++)
    {
        if (i % 2 == 0)
        {
            g();
        }
        else
        {
            h();
        }
    }
}

int main(int argc, char **argv)
{
    f();
    P(sum);
    return 0;
}
