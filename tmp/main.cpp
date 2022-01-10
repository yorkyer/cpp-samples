#include <bits/stdc++.h> 
#include <pprint.hpp>
#include <backward.hpp>
#include <spdlog/spdlog.h>
#include <pystring.h>
#include <mio/mmap.hpp>
#include <spy/spy.hpp>
#include <args.hxx>
#include <tscns.h>
#include <omp.h>

namespace backward
{
    backward::SignalHandling sh;
}


using namespace std;


#define P(...) \
do { \
    pprint::PrettyPrinter printer; \
    printer.quotes(false); \
    printer.compact(false); \
    printer.print(__VA_ARGS__); \
} while (0)

#define TIMETAG

class Timer {
 public:
  Timer() {
#ifdef TIMETAG
    int num_threads = 1;
    start_time_.resize(num_threads);
    stats_.resize(num_threads);
#endif  // TIMETAG
  }

  ~Timer() { Print(); }

#ifdef TIMETAG
  void Start(const std::string& name) {
    auto tid = omp_get_thread_num();
    start_time_[tid][name] = std::chrono::steady_clock::now();
  }

  void Stop(const std::string& name) {
    auto cur_time = std::chrono::steady_clock::now();
    auto tid = omp_get_thread_num();
    if (stats_[tid].find(name) == stats_[tid].end()) {
      stats_[tid][name] = std::chrono::duration<double, std::milli>(0);
    }
    stats_[tid][name] += cur_time - start_time_[tid][name];
  }

#else
  void Start(const std::string&) {}

  void Stop(const std::string&) {}
#endif  // TIMETAG

  void Print() const {
#ifdef TIMETAG
    std::unordered_map<std::string, std::chrono::duration<double, std::milli>>
        stats(stats_[0].begin(), stats_[0].end());
    for (size_t i = 1; i < stats_.size(); ++i) {
      for (auto it = stats_[i].begin(); it != stats_[i].end(); ++it) {
        if (stats.find(it->first) == stats.end()) {
          stats[it->first] = it->second;
        } else {
          stats[it->first] += it->second;
        }
      }
    }
    std::map<std::string, std::chrono::duration<double, std::milli>> ordered(
        stats.begin(), stats.end());
    for (auto it = ordered.begin(); it != ordered.end(); ++it) {
      spdlog::info("{} costs:\t {}", it->first, it->second.count() * 1e-3);
    }
#endif  // TIMETAG
  }
#ifdef TIMETAG
  std::vector<
      std::unordered_map<std::string, std::chrono::steady_clock::time_point>>
      start_time_;
  std::vector<std::unordered_map<std::string,
                                 std::chrono::duration<double, std::milli>>>
      stats_;
#endif  // TIMETAG
};


int f() {
    Timer timer;
    timer.Start("f");
    int i;
    for (i = 0; i < 100000; ++i) {
        i = i + i;
    }
    timer.Stop("f");
    return i;
}



// spdlog::debug("This message should be displayed..");    

// change log pattern

int main(int argc, char **argv)
{
    spdlog::set_level(spdlog::level::info); // Set global log level to debug
    spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

    f();
    return 0;
}
