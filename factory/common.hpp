#include <string>

struct Common {
    virtual ~Common() = default;
    virtual std::string whoami() const = 0;
};