#pragma once

#include <string>
#include <iostream>
#include <array>
#include <vector>

class SString {
private:
    std::vector<int> values;
    constexpr static const int key[5] = {1, 2, 3, 4, 5}; // change this
    constexpr static const size_t key_size = 5; // change this

public:
    // SString(std::initializer_list<short> list) {
    //     values.insert(values.end(), list.begin(), list.end());
    // }

    template<typename ... Vs>
    SString(Vs ... vs) {
        values = {vs...};
    }

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
            s[i] = (char)(values[i] ^ key[i % key_size]);
        }
        return s;
    }

    friend std::ostream& operator<<(std::ostream& os, const SString& ss);
};

std::ostream& operator<<(std::ostream& os, const SString& ss) {
    for (size_t i = 0; i < ss.size(); ++i) {
        os << ss[i];
    }
    return os;
}
