#include <benchmark/benchmark.h>
#include <vector>
#include <array>
#include <memory>
#include <cstring>
#include <iostream>
#include <x86intrin.h>

void exception() {
  throw std::exception();
}

int error_code() {
    return -1;
}

int sum = 0;

__m256 v;

static void exception_bench(benchmark::State &state)
{
  // Perform setup here
  long long s = 0;
  for (auto _ : state)
  {
    // This code gets timed
    try {
        exception();
    }
    catch (const std::exception &excep) {
        sum += 1;
    }
  }
}

static void error_code_bench(benchmark::State &state)
{
  long long s = 0;
  // Perform setup here
  for (auto _ : state)
  {
    if (error_code() < 0) {
        sum += 1;
    }
  }
}



// Register the function as a benchmark
BENCHMARK(exception_bench);

BENCHMARK(error_code_bench);
// Run the benchmark

int main(int argc, char *argv[]) {
    ::benchmark::Initialize(&argc, argv);                              
    if (::benchmark::ReportUnrecognizedArguments(argc, argv)) return 1;
    ::benchmark::RunSpecifiedBenchmarks();                             
    ::benchmark::Shutdown(); 
    
    std::cout << sum << std::endl;                                          
    return 0;  
}
  
