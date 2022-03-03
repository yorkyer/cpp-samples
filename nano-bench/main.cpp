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


int main(int argc, char **argv) {
    TSCNS tn;
    tn.init();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    tn.calibrate();

    std::vector<int64_t> vsum_diffs;
    std::vector<int64_t> sum_diffs;
    __m256 v;

    for (int i = 0; i < count; ++i) {
        auto start = tn.rdns();

        vsum(v);

        auto finish = tn.rdns();
        auto diff = finish - start;
        vsum_diffs.push_back(diff);
    }

    for (int i = 0; i < count; ++i) {
        auto start = tn.rdns();

        sum(v);

        auto finish = tn.rdns();
        auto diff = finish - start;
        sum_diffs.push_back(diff);
    }

    print(vsum_diffs, "vsum");
    print(sum_diffs, "sum");

    return 0;
}