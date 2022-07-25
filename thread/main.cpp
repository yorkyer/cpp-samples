#include<bits/stdc++.h> 

using namespace std;

const size_t num_threads = 4;
std::condition_variable cv;
std::mutex mtx;
std::mutex task_mtx;

std::vector<std::function<void()>> tasks;
std::vector<std::thread> workers;
std::atomic<bool> stopped;

void g() {
    int ready_count{};

    {    
        std::scoped_lock lk{task_mtx};
        for (size_t i = 0; i < num_threads; i++) {
            tasks.emplace_back([&]() {
                int m = 0;
                for (int i = 0; i < 10000; ++i) {
                    m += i * i;
                }
                {
                    std::lock_guard<std::mutex> lock(mtx);
                    ready_count++;
                }
                cv.notify_one();
            });
        }
    }

    std::unique_lock lk{mtx};
    cv.wait(lk, [&]{ return ready_count == num_threads; });
}

int main(int argc, char **argv)
{
    for (size_t i = 0; i < num_threads; i++) {
        workers.emplace_back([&]() {
            while (!stopped) {
                {
                    std::scoped_lock lk(task_mtx);
                    if (!tasks.empty()) {
                        auto &task = tasks.back();
                        task();
                        tasks.pop_back();
                    }
                }
                
                using namespace std::chrono_literals;
                // std::this_thread::sleep_for(0ms);
            }
        });
    }

    for (int i = 0; i < 100000; i ++) {
        std::cout << i << std::endl;
        g();
    }
    stopped = true;

    for (auto &thread : workers) {
        thread.join();
    }
    return 0;
}
