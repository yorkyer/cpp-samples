#include <backward.hpp>

using namespace std;

void f3()
{
    int *n = nullptr;
    int a = *n;
}

void f2()
{
    f3();
}

void f1()
{
    f2();
}

int main()
{
    f1();
    return 0;
}
