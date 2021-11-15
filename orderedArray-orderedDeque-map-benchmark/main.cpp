#include <bits/stdc++.h>
#include <benchmark/benchmark.h>

const size_t N = 50;
const size_t N_ADD = 400;
const size_t N_DEL = 100;

std::vector<int> sample(N_ADD);
std::mt19937 ran(std::random_device{}());

struct Object
{
  int x{0};
  int y{0};
  std::vector<int> vec{std::vector<int>(10)};
};

static void orderedArray(benchmark::State &state)
{
    std::iota(sample.begin(), sample.end(), 0);
    std::vector<int> keys;
    std::vector<Object> values;

    for (auto _ : state)
    {
        std::shuffle(sample.begin(), sample.end(), ran);
        for (auto v : sample) {
            auto it = std::lower_bound(keys.begin(), keys.end(), v);
            values.emplace(values.begin() + (it - keys.begin()), Object());
            keys.emplace(it, v);
        }
        std::shuffle(sample.begin(), sample.end(), ran);
        int i = 0;
        for (auto v : sample) {
            auto it = std::lower_bound(keys.begin(), keys.end(), v);
            values.erase(values.begin() + (it - keys.begin()));
            keys.erase(it);
            ++i;
            if (i > N_DEL) break;
        }
    }
}

static void orderedDeque(benchmark::State &state)
{
    std::iota(sample.begin(), sample.end(), 0);
    std::deque<int> keys;
    std::deque<Object> values;

    for (auto _ : state)
    {
        std::shuffle(sample.begin(), sample.end(), ran);
        for (auto v : sample) {
            auto it = std::lower_bound(keys.begin(), keys.end(), v);
            values.emplace(values.begin() + (it - keys.begin()), Object());
            keys.emplace(it, v);
        }
        std::shuffle(sample.begin(), sample.end(), ran);
        int i = 0;
        for (auto v : sample) {
            auto it = std::lower_bound(keys.begin(), keys.end(), v);
            values.erase(values.begin() + (it - keys.begin()));
            keys.erase(it);
            ++i;
            if (i > N_DEL) break;
        }
    }
}

static void map(benchmark::State &state)
{
    std::iota(sample.begin(), sample.end(), 0);
    std::map<int, Object> map;
    for (auto _ : state)
    {
        std::shuffle(sample.begin(), sample.end(), ran);
        for (auto v : sample) {
            map.emplace(v, Object());
        }
        std::shuffle(sample.begin(), sample.end(), ran);
        int i = 0;
        for (auto v : sample) {
            map.erase(v);
            ++i;
            if (i > N_DEL) break;
        }
    }
}

// Register the function as a benchmark
BENCHMARK(orderedArray);
BENCHMARK(orderedDeque);
BENCHMARK(map);
// Run the benchmark
BENCHMARK_MAIN();
