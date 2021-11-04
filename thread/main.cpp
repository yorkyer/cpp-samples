#include<bits/stdc++.h> 

using namespace std;

void f()
{
    int sum = 0;
    for (int i = 0; i < 1000000000; ++i) {
        sum += i * i;
    }
    cout << sum << endl;
}

int main(int argc, char **argv)
{
    vector<thread> threads;
    threads.emplace_back(thread(f));
    threads.emplace_back(thread(f));
    threads.emplace_back(thread(f));
    threads.emplace_back(thread(f));

    for (auto &t : threads) t.join();
    return 0;
}
