#pragma once

#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdint.h>
#include <string>
#include <mutex>

class LatencyStat
{
public:
    LatencyStat(const std::string &name, int64_t count)
    {
        name_ = name;
        count_ = count;
    }

    bool stat(int64_t val, bool clear=false)
    {
        lats_.push_back(val);
        if (lats_.size() % count_ != 0)
            return false;
        std::sort(lats_.begin(), lats_.end());
        printf("%10s %4ld %4ld %4ld %4ld [%4ld] %4ld %4ld %4ld %4ld\n",
            name_.data(),
            lats_[(int)(lats_.size() * 0.1)],
            lats_[(int)(lats_.size() * 0.2)],
            lats_[(int)(lats_.size() * 0.3)],
            lats_[(int)(lats_.size() * 0.4)],
            lats_[(int)(lats_.size() * 0.5)],
            lats_[(int)(lats_.size() * 0.6)],
            lats_[(int)(lats_.size() * 0.7)],
            lats_[(int)(lats_.size() * 0.8)],
            lats_[(int)(lats_.size() * 0.9)]);
        if (clear)
            lats_.clear();
        return true;
    }

    bool safeStat(int64_t val, bool clear=false)
    {
        std::unique_lock<std::mutex> lock(mutex_);
        return stat(val, clear);
    }

private:
    std::string name_;
    int64_t count_;
    std::vector<int64_t> lats_;
    std::mutex mutex_;
};