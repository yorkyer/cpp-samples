#include "common.hpp"

struct B : public Common {
    std::string whoami() const override {
        Singleon::x ++;
        return "B";
    }
};

extern "C" std::unique_ptr<Common> Create() {
    return std::make_unique<B>();
}