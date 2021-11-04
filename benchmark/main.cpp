#include <benchmark/benchmark.h>
#include <vector>

struct Object {
    int x{0};
    int y{0};
};

static void BM_push_back(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    std::vector<Object> objects;
    objects.push_back(Object{1, 2});
  }
}

static void BM_emplace_back(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    std::vector<Object> objects;
    objects.emplace_back(Object{1, 2});
  }
}

// Register the function as a benchmark
BENCHMARK(BM_push_back);
BENCHMARK(BM_emplace_back);
// Run the benchmark
BENCHMARK_MAIN();

