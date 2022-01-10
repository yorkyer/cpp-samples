#include <bits/stdc++.h>
#include <benchmark/benchmark.h>

const size_t N = 50;

static void vector(benchmark::State &state)
{
    std::vector<int> sample;
    for (int i = 0; i < N; ++i) {
        sample.push_back(i);
    }

    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i) {
            sample[i];
        }
    }
}

static void unordered_set(benchmark::State &state)
{
    std::unordered_set<int> sample;
    for (int i = 0; i < N; ++i) {
        sample.insert(i);
    }

    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i) {
            sample.find(i);
        }
    }
}

// Register the function as a benchmark
BENCHMARK(unordered_set);
BENCHMARK(vector);
// Run the benchmark
BENCHMARK_MAIN();
