#include "SString.hpp"

const SString<89,87,95,88,90,70,93,65,88,81> A;

int main() {
    std::cout << A << std::endl;

    for (size_t i = 0; i < A.size(); ++i) {
        std::cout << A[i];
    }
    std::cout << std::endl;

    std::cout << A.getOriginalString();
    return 0;
}