#include <bits/stdc++.h>
#include "moodycamel/concurrentqueue.h"

using namespace std;

int main(int argc, char **argv)
{
    moodycamel::ConcurrentQueue<int*> q;

    int *results[5]; 

    int item;

    q.enqueue(&item);

    size_t found = q.try_dequeue_bulk(results, 5);
    std::cout << found << std::endl;
    return 0;
}
