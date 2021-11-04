#include <iostream>
#include <pystring.h>

using namespace std;

int main()
{
    cout << boolalpha << pystring::endswith("endswith", "with") << endl;
    return 0;
}
