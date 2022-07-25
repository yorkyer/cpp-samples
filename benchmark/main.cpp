#include <benchmark/benchmark.h>
#include <vector>
#include <array>
#include <memory>
#include <cstring>
#include <iostream>
#include <x86intrin.h>

float vsum(const __m256 &v) {
  __m256 sum = _mm256_hadd_ps(v, v);
  sum = _mm256_hadd_ps(sum, sum);
  float buffer[8];
  _mm256_storeu_ps(buffer, sum);
  return buffer[0] + buffer[4];
}

constexpr static int L3_CACHE_SIZE = 40 * 1024 * 1024;
std::vector<float> big_array(L3_CACHE_SIZE / sizeof(float));
float sum_;
void flush_cache() {
    for (size_t i = 0; i < big_array.size(); i++)
        sum_ += big_array[i];
}

constexpr static int L3_CACHE_SIZE_2 = 36 * 1024 * 1024;
std::vector<float> big_array_2(L3_CACHE_SIZE_2 / sizeof(float));
void flush_cache_2() {
    for (size_t i = 0; i < big_array_2.size(); i++)
        sum_ += big_array_2[i];
}


float sum(const __m256 &v) {
  float buffer[8];
  _mm256_storeu_ps(buffer, v);
  return buffer[0] + buffer[1] + buffer[2] + buffer[3] + 
         buffer[4] + buffer[5] + buffer[6] + buffer[7];
}

__m256 v;

static void vsum_bench(benchmark::State &state)
{
  // Perform setup here
  long long s = 0;
  int i = 0;
  for (auto _ : state)
  {
    i++;
    // This code gets timed
    flush_cache_2();
  }
  state.counters["i"] = benchmark::Counter(i);
}

static void sum_bench(benchmark::State &state)
{
  long long s = 0;
  // Perform setup here
  for (auto _ : state)
  {
    // This code gets timed
    // sum(v);
    flush_cache();
  }
}



// Register the function as a benchmark
// BENCHMARK(vsum_bench);

BENCHMARK(sum_bench);
BENCHMARK(vsum_bench);
// Run the benchmark
BENCHMARK_MAIN();
