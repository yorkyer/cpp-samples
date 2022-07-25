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


struct A {
    int a = 3;
    virtual void f() {
        P("A");
    }
    void g() {
        P("A");
    }
};

struct B : public A {
    virtual void f() {
P("B");
    }
    virtual void g() {
P("B");
    }
};

struct C : public B {
     void f() {
P("C");
    }
         void g() {
P("C");
    }
};

struct D : public C {
    void f() {
        P("D");
    }
        void g() {
        P("D");
    }
};


void f(long long a, long long b = 3) {
    P("f1");
}

void f(int64_t a) {
    P("f2");
}

TSCNS tn;

int main() {
    tn.init();

    std::unordered_map<int, int> map;

    for (int i = 0; i < 1'000'000; ++i) {
        map[i] = i;
    }

    int sum = 0;
    for (int i = 0; i < 1'000'000; i += 1000) {
        auto start = tn.rdns();
        sum += map[i];
        P(tn.rdns() - start);
    }
    P(sum);

    return 0;
}