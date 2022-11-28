#include <string>
#include <memory>
#include <vector>
#include <iostream>

struct Common {
    virtual ~Common() = default;
    virtual std::string whoami() const = 0;
};


struct Singleon {
    Singleon() {
        std::cout << "Singleon" << std::endl;
    }

    static inline int x = 0;
};
