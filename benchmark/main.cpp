#include <benchmark/benchmark.h>
#include <vector>
#include <array>

static void BM_array(benchmark::State &state)
{
  // Perform setup here
  for (auto _ : state)
  {
    // This code gets timed
    std::array<int, 6> objects{0, 1, 2, 3, 4, 5};
  }
}

static void BM_vector(benchmark::State &state)
{
  // Perform setup here
  for (auto _ : state)
  {
    // This code gets timed
    std::vector<int> objects{0, 1, 2, 3, 4, 5};
  }
}



// Register the function as a benchmark
BENCHMARK(BM_array);

BENCHMARK(BM_vector);
// Run the benchmark
BENCHMARK_MAIN();
