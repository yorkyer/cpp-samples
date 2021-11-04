#include <iostream>
#include <spy/spy.hpp>

using namespace std;

int main(int argc, char **argv)
{
    std::cout << spy::operating_system      << "\n";
    std::cout << spy::architecture          << "\n";
    std::cout << spy::simd_instruction_set  << "\n";
    std::cout << spy::compiler              << "\n";
    std::cout << spy::libc                  << "\n";
    std::cout << spy::stdlib                << "\n";
    return 0;
}
