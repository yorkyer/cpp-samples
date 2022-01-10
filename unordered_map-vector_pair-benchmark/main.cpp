#include <bits/stdc++.h>
#include <benchmark/benchmark.h>

const size_t N = 50;

static void vector(benchmark::State &state)
{
    std::vector<std::pair<int, int>> sample;
    for (int i = 0; i < N; ++i) {
        sample.push_back(std::make_pair(i, i));
    }

    for (auto _ : state)
    {
        int v;
        for (int i = 0; i < N; ++i) {
            v = sample[i].second;
        }
    }
}

static void unordered_map(benchmark::State &state)
{
    std::unordered_map<int, int> sample;
    for (int i = 0; i < N; ++i) {
        sample[i] = i;
    }

    for (auto _ : state)
    {
        int v;
        for (int i = 0; i < N; ++i) {
            v = sample[i];
        }
    }
}

// Register the function as a benchmark
BENCHMARK(unordered_map);
BENCHMARK(vector);
// Run the benchmark
BENCHMARK_MAIN();
