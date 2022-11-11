#include "common.hpp"

struct B : public Common {
    std::string whoami() const override {
        return "B";
    }
};