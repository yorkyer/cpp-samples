#include <iostream>
// #include <fmt/core.h>
#include <fmt/format.h>

using namespace std;

int main(int argc, char **argv)
{
    fmt::print("The answer is {:#<10.2f}.\n", 42.24243);
    fmt::print("Don't {}\n", "panic");
    fmt::print(stderr, "System error code = {}\n", errno);
    fmt::print("I'd rather be {1} than {0}.\n", "right", "happy");
    fmt::print("Hello, {name}! The answer is {number}. Goodbye, {name}.\n",
           fmt::arg("name", "World"), fmt::arg("number", 42));
    using namespace fmt::literals;
    fmt::print("Hello, {name}! The answer is {number}. Goodbye, {name}.\n",
            "name"_a="World", "number"_a=42);
    return 0;
}
