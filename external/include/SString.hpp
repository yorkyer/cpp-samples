#pragma once

#include <string>
#include <iostream>
#include <array>

template<char ... Values>
class SString {
private:
    std::array<char, sizeof...(Values)> values = {Values...};
    constexpr static const char * key = "12345"; // change this
    constexpr static const size_t key_size = 5; // change this

public:
    char operator[](size_t i) const {
        return values[i] ^ key[i % key_size];
    }
    size_t size() const {
        return values.size();
    }

    std::string getOriginalString() const { 
        std::string s;
        s.resize(values.size());
        for (size_t i = 0; i < values.size(); ++i) {
            s[i] = values[i] ^ key[i % key_size];
        }
        return s;
    }

    template<char ... Vs>
    friend std::ostream& operator<<(std::ostream& os, const SString<Vs...>& ss);
};

template<char ... Values>
std::ostream& operator<<(std::ostream& os, const SString<Values...>& ss) {
    for (size_t i = 0; i < ss.size(); ++i) {
        os << ss[i];
    }
    return os;
}
