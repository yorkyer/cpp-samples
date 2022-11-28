#include "common.hpp"

struct A : public Common {
    std::string whoami() const override {
        Singleon::x ++;
        return "A";
    }
};

extern "C" std::unique_ptr<Common> Create() {
    return std::make_unique<A>();
}