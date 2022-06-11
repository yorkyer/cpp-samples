#include<bits/stdc++.h> 

using namespace std;

const size_t num_threads = 4;
std::condition_variable cv;
std::mutex mtx;

void g() {
    int ready_count{};
    std::vector<std::thread> threads;

    auto f = [&]() {
        int m = 0;
        for (int i = 0; i < 1000; ++i) {
            m += i * i;
        }
        {
            std::lock_guard<std::mutex> lock(mtx);
            ready_count++;
        }
        
        cv.notify_one();
    };

    threads.emplace_back(f);
    threads.emplace_back(f);
    threads.emplace_back(f);
    threads.emplace_back(f);

    std::unique_lock lk{mtx};
    cv.wait(lk, [&]{ return ready_count == num_threads; });

    for (auto &t : threads)
        t.join();
}

int main(int argc, char **argv)
{
    for (int i = 0; i < 100000; i ++) {
        std::cout << i << std::endl;
        g();
    }
    return 0;
}
