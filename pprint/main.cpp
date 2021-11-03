#include <pprint.hpp>
#include <map>
#include <string>

using namespace std;

int main()
{
    pprint::PrettyPrinter printer;
    map<int, string> m{{1, "A"}, {2, "B"}, {3, "C"}, {4, "D"}};
    printer.print(m);
    return 0;
}
