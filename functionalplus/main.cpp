#include <iostream>
#include <vector>
#include <string>
#include <fplus/fplus.hpp>

using namespace std;

struct Cat
{
    double cuteness() const
    {
        return softness_ * temperature_ * roundness_ * fur_amount_ - size_;
    }
    std::string name_;
    double softness_;
    double temperature_;
    double size_;
    double roundness_;
    double fur_amount_;
};

int main(int argc, char **argv)
{
    std::vector<Cat> cats = {
        {"Tigger",   5, 5, 5, 5, 5},
        {"Simba",    2, 9, 9, 2, 7},
        {"Muffin",   9, 4, 2, 8, 6},
        {"Garfield", 6, 5, 7, 9, 5}};

    auto cutest_cat = fplus::maximum_on(std::mem_fn(&Cat::cuteness), cats);

    std::cout << cutest_cat.name_ <<
        " is happy and sleepy. *purr* *purr* *purr*" << std::endl;
    return 0;
}
