#include <thread>
#include <chrono>
#include <cstddef>
#include <vector>
#include <string>
#include <x86intrin.h>
#include <algorithm>
#include <cmath>
#include <iostream>

#include "tscns.h" // https://github.com/MengRao/tscns/blob/master/tscns.h


float vsum(const __m256 &v) {
  __m256 sum = _mm256_hadd_ps(v, v);
  sum = _mm256_hadd_ps(sum, sum);
  float buffer[8];
  _mm256_storeu_ps(buffer, sum);
  return buffer[0] + buffer[4];
}

float sum(const __m256 &v) {
  float buffer[8];
  _mm256_storeu_ps(buffer, v);
  return buffer[0] + buffer[1] + buffer[2] + buffer[3] + 
         buffer[4] + buffer[5] + buffer[6] + buffer[7];
}

const static int count = 1000;

template <typename Vec, typename Str>
void print(Vec &vector, Str &name) {
    std::sort(vector.begin(), vector.end());
    std::cout << name << ","
              << vector[std::round(vector.size() * 0.05)] << ","
              << vector[std::round(vector.size() * 0.50)] << ","
              << vector[std::round(vector.size() * 0.95)] << "\n";
}

using std::chrono::microseconds;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;

inline long long getTime() {
    return duration_cast<microseconds>(high_resolution_clock::now().time_since_epoch()).count();
}

int main(int argc, char **argv) {
    TSCNS tn;
    tn.init();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    tn.calibrate();

    std::vector<int64_t> time_diffs;

    for (int i = 0; i < count; ++i) {
        auto start = tn.rdns();

        getTime();

        auto finish = tn.rdns();
        auto diff = finish - start;
        time_diffs.push_back(diff);
    }

    print(time_diffs, "time");

    return 0;
}