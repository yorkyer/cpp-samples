#include "SString.hpp"

const SString A{105,103,111,104,106,118,109,113,104,97};

int main() {
    std::cout << A << std::endl;

    for (size_t i = 0; i < A.size(); ++i) {
        std::cout << A[i];
    }
    std::cout << std::endl;

    std::cout << A.getOriginalString();
    return 0;
}