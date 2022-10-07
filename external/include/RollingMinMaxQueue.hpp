#pragma once

#include <stdint.h>
#include <deque>
#include <functional>
#include <algorithm>
#include <limits>

namespace sta
{

template<typename K, typename V, typename Compare>
class MonotonicQueue
{
public:
    void push_back(K k, V v)
    {
        while (!q_.empty()) {
            if (!Compare()(q_.back().second, v))
                q_.pop_back();
            else
                break;
        }
        q_.push_back({k, v});
    }

    void pop_front_by_key(K min_k)
    {
        while (!q_.empty()) {
            if (q_.front().first < min_k)
                q_.pop_front();
            else
                break;
        }
    }

    V front_value() const
    {
        return q_.front().second;
    }

    V front_value_by_key(K min_k) const
    {
        for (auto &x : q_)
            if (x.first >= min_k)
                return x.second;
        return q_.back().second;
    }

    void clear()
    {
        q_.clear();
    }

    bool empty() const
    {
        return q_.empty();
    }

private:
    std::deque<std::pair<K, V>> q_;
};

template<typename K, typename V>
class MonotonicMinQueue : public MonotonicQueue<K, V, std::less<V>> { };

template<typename K, typename V>
class MonotonicMaxQueue : public MonotonicQueue<K, V, std::greater<V>> { };

template<typename K, typename V>
class MonotonicMinMaxQueue
{
public:
    void push_back(K k, V v)
    {
        minq_.push_back(k, v);
        maxq_.push_back(k, v);
    }

    void pop_front_by_key(K min_k)
    {
        minq_.pop_front_by_key(min_k);
        maxq_.pop_front_by_key(min_k);
    }

    V min() const
    {
        if (minq_.empty())
            return std::numeric_limits<V>::min();

        return minq_.front_value();
    }

    V max() const
    {
        if (maxq_.empty())
            return std::numeric_limits<V>::max();

        return maxq_.front_value();
    }

    V min_by_key(K min_k) const
    {
        if (minq_.empty())
            return std::numeric_limits<V>::min();

        return minq_.front_value_by_key(min_k);
    }

    V max_by_key(K max_k) const
    {
        if (maxq_.empty())
            return std::numeric_limits<V>::max();

        return maxq_.front_value_by_key(max_k);
    }

    void clear()
    {
        minq_.clear();
        maxq_.clear();
    }

    bool empty() const
    {
        return minq_.empty() || maxq_.empty();
    }

private:
    MonotonicMinQueue<K, V> minq_;
    MonotonicMaxQueue<K, V> maxq_;
};

template<typename T>
class RollingMinMaxQueueTemplate
{
public:
    RollingMinMaxQueueTemplate(int64_t period) : period_(period) { }

    void push_back(int64_t time, T elem)
    {
        queue_.push_back(time, elem);
        queue_.pop_front_by_key(time - period_);
    }

    T min() const
    {
        return queue_.min();
    }

    T max() const
    {
        return queue_.max();
    }

    T min(int64_t time) const
    {
        return queue_.min_by_key(time - period_);
    }

    T max(int64_t time) const
    {
        return queue_.max_by_key(time - period_);
    }

    void clear()
    {
        queue_.clear();
    }

    bool empty() const
    {
        return queue_.empty();
    }

private:
    int64_t period_;
    MonotonicMinMaxQueue<int64_t, T> queue_;
};

class RollingMinMaxQueue
{
public:
    static RollingMinMaxQueue* create(int period)
    {
        return new RollingMinMaxQueue(period);
    }

    RollingMinMaxQueue(int64_t period) : queue_(period)
    {
    }

    ~RollingMinMaxQueue() { }

    void push_back(int64_t time, double elem)
    {
        queue_.push_back(time, elem);
    }

    double min() const
    {
        return queue_.min();
    }

    double max() const
    {
        return queue_.max();
    }

    double min(int64_t time) const
    {
        return queue_.min(time);
    }

    double max(int64_t time) const
    {
        return queue_.max(time);
    }

    void clear()
    {
        queue_.clear();
    }

    bool empty() const
    {
        return queue_.empty();
    }
    
private:
    RollingMinMaxQueueTemplate<double> queue_;
};

}
