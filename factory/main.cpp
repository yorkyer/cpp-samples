#include <bits/stdc++.h> 
#include <pprint.hpp>
#include <backward.hpp>
#include <spdlog/spdlog.h>
#include <pystring.h>
#include <mio/mmap.hpp>
#include <spy/spy.hpp>
#include <args.hxx>
#include <tscns.h>
#include <dlfcn.h>
#include <common.hpp>

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


template<typename Func>
Func getFuncFromLibrary(const std::string &path, const std::string &func_name)
{
    void *handle = dlopen(path.data(), RTLD_NOW | RTLD_GLOBAL);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    Func func = (Func)dlsym(handle, func_name.data());
    if (!func) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    return func;
}

int main(int argc, char **argv)
{
    Singleon::x++;

    using Func = std::unique_ptr<Common> (*)();
    auto create_a = getFuncFromLibrary<Func>("../lib/libliba.so", "Create");
    auto create_b = getFuncFromLibrary<Func>("../lib/liblibb.so", "Create");

    auto a = create_a();
    P(a->whoami());

    auto b = create_b();

    P(a->whoami());
    P(b->whoami());

    P(Singleon::x);
    return 0;
}
