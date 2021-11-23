#include <iostream>
#include <pystring.h>
#include <pprint.hpp>

using namespace std;

int main()
{
    pprint::PrettyPrinter printer;

    cout << boolalpha << pystring::endswith("endswith", "with") << endl;
    string str = "hello,1,hi";
    vector<string> result;
    pystring::split(str, result, ",");
    printer.print(result);
    
    return 0;
}
