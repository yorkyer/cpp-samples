#include "common.hpp"

struct A : public Common {
    std::string whoami() const override {
        return "A";
    }
};