#pragma once

#include <string>
#include <vector>

// #define OBF_DEBUG
#include "instr.h"

namespace SS
{

class SS {
private:
    std::vector<int> v;
    constexpr static const int ky[5] = {1, 2, 3, 4, 5};
    constexpr static const size_t ky_si = 5;

public:
    template<typename ... Vs>
    SS(Vs ... vs) {
        v = {vs...};
    }

#ifndef SS_NO_OBF
    std::string get() const { 
        OBF_BEGIN
        int i, j, k, ix, n, t;
        V(i) = V(ky[0]);
        V(j) = N(0);
        V(k) = N(0);
        V(ix) = N(0);
        V(n) = V(v[i]) - N(50);
        FOR(V(t) = N(0), V(t) < V(n), V(t) += N(1))
            V(i) += N(1);
            V(j) += V(v[i]) - N(50);
        ENDFOR
        std::string s;
        s.resize(j);
        FOR (V(i) += N(1), V(k) < V(j), V(i) += (V(ky[N(1)]) + N(1)))
            V(ix) %= V(ky_si);
            s[k] = (char)(v[i] ^ ky[ix]);
            V(k) += N(1);
            V(ix) += N(1);
        ENDFOR
        RETURN (s);
        OBF_END
    }
#else
    std::string get() const { 
        int i, j, k, ix;
        i = ky[0];
        j = 0;
        int n = v[i] - 50;
        for (int t = 0; t < n; ++t) {
            i += 1;
            j += v[i] - 50;
        }
        k = 0;
        ix = 0;
        std::string s;
        s.resize(j);
        for (i += 1; k < j; i += (ky[1] + 1)) {
            ix %= (ky_si);
            s[k] = (char)(v[i] ^ ky[ix]);
            k += 1;
            ix += 1;
        }
        return (s);
    }
#endif
};

}
