#pragma once

#include <deque>
#include <vector>
#include <algorithm>
#include <stdio.h>

namespace sta
{

template<typename T>
class HistoricalQueue
{
public:
    HistoricalQueue(const std::vector<int> &lag_periods)
    {
        lag_periods_ = lag_periods;
        for (int period : lag_periods)
            max_lag_period_ = std::max(max_lag_period_, period);
        clear();
    }

    void PrivateOrderMessage.cpppush_back(int time_idx, const T &elem)
    {
        if (queue_.empty()) {
            queue_.push_back({time_idx, elem});
        }
        else if (time_idx > queue_.back().time_idx) {
            queue_.push_back({time_idx, elem});
        }
        else if (time_idx == queue_.back().time_idx) {
            queue_.back().elem = elem;
        }

        expire();
        update_pos();

        std::cout << "lag_positions: ";
        for (size_t lag_idx = 0; lag_idx < lag_periods_.size(); lag_idx++)
            std::cout << lag_positions_[lag_idx] << " ";
        std::cout << std::endl;
    }

    void clear()
    {
        queue_.clear();
        lag_positions_.resize(lag_periods_.size());
        for (size_t lag_idx = 0; lag_idx < lag_periods_.size(); lag_idx++)
            lag_positions_[lag_idx] = 0;
    }

    bool empty() const { return queue_.empty(); }
    size_t size() const { return queue_.size(); }

    const T& front() const { return queue_.front().elem; }
    const T& back() const { return queue_.back().elem; }

    T& at(size_t idx) { return queue_[idx].elem; }
    const T& at(size_t idx) const { return queue_[idx].elem; }

    const T& get_lagging(int time_idx, int lag_idx) const
    {
        int pos = get_lagging_pos(time_idx, lag_idx);
        if (pos < 0)
            return default_value_;
        else
            return queue_[pos].elem;
    }

    const T& get_lagging_slow(int time_idx, int lag_idx) const
    {
        if (queue_.empty())
            return default_value_;

        time_idx -= lag_periods_[lag_idx];
        for (int i = queue_.size() - 1; i >= 0; i--)
            if (time_idx >= queue_[i].time_idx)
                return queue_[i].elem;

        return default_value_;
    }

private:
    void expire()
    {
        int popped_cnt = 0;
        while (queue_.size() > 2) {
            if (queue_[1].time_idx + max_lag_period_ < queue_.back().time_idx) {
                queue_.pop_front();
                popped_cnt++;
            }
            else {
                break;
            }
        }
        if (popped_cnt > 0)
            for (int &pos : lag_positions_) {
                pos = std::max(0, pos - popped_cnt);
            }
    }

    void update_pos()
    {
        if (queue_.empty())
            return;
        int max_time_idx = queue_.back().time_idx;
        for (size_t lag_idx = 0; lag_idx < lag_periods_.size(); lag_idx++) {
            lag_positions_[lag_idx] = std::max(0, get_lagging_pos(max_time_idx, lag_idx));
        }
    }

    int get_lagging_pos(int time_idx, int lag_idx) const
    {
        time_idx -= lag_periods_[lag_idx];
        int pos = lag_positions_[lag_idx];
        while (pos + 1 < (int)queue_.size() && time_idx >= queue_[pos + 1].time_idx)
            pos++;
        if (queue_[pos].time_idx > time_idx)
            return -1;
        return pos;
    }

    struct QueueElem
    {
        int time_idx;
        T elem;
    };

    std::deque<QueueElem> queue_;
    std::vector<int> lag_periods_;
    std::vector<int> lag_positions_;
    int max_lag_period_{0};
    T default_value_;
};

}
