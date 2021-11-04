#include <iostream>
#include <args.hxx>

using namespace std;

int main(int argc, char **argv)
{
    args::ArgumentParser parser("This is a test program.", "Contact yorkyer93@gmail.com");
    args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});
    args::ValueFlag<int> integer(parser, "integer", "The integer flag", {'i'});
    args::ValueFlagList<char> characters(parser, "characters", "The character flag", {'c'});
    args::Flag bar(parser, "bar", "The bar flag", {'b', "bar"});
    args::Positional<std::string> foo(parser, "foo", "The foo position");
    args::PositionalList<double> numbers(parser, "numbers", "The numbers position list");
    try
    {
        parser.ParseCLI(argc, argv);
    }
    catch (args::Help)
    {
        std::cout << parser;
        return 0;
    }
    catch (args::ParseError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }
    catch (args::ValidationError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }

    if (integer) { std::cout << "i: " << args::get(integer) << std::endl; }
    if (characters) { for (const auto ch: args::get(characters)) { std::cout << "c: " << ch << std::endl; } }
    if (bar) { std::cout << "b: " << args::get(bar) << std::endl; }
    if (foo) { std::cout << "f: " << args::get(foo) << std::endl; }
    if (numbers) { for (const auto nm: args::get(numbers)) { std::cout << "n: " << nm << std::endl; } }

    return 0;
}
