#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <stdexcept>
#include <functional>

template <typename T, typename PComparator = std::less<T>>
class Heap
{
public:
    Heap(int m = 2, PComparator c = PComparator()) : m_(m), comp_(c) {}

    ~Heap() {}

    void push(const T &item)
    {
        data_.push_back(item);
        heapifyUp(data_.size() - 1);
    }

    const T &top() const
    {
        if (empty())
        {
            throw std::underflow_error("Heap is empty");
        }
        return data_[0];
    }

    void pop()
    {
        if (empty())
        {
            throw std::underflow_error("Heap is empty");
        }
        std::swap(data_[0], data_.back());
        data_.pop_back();
        if (!empty())
        {
            heapifyDown(0);
        }
    }

    bool empty() const
    {
        return data_.empty();
    }

    size_t size() const
    {
        return data_.size();
    }

private:
    std::vector<T> data_;
    int m_;
    PComparator comp_;

    void heapifyUp(size_t index)
    {
        if (index == 0)
            return;

        size_t parentIndex = (index - 1) / m_;
        if (comp_(data_[index], data_[parentIndex]))
        {
            std::swap(data_[index], data_[parentIndex]);
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(size_t index)
    {
        size_t bestChild = index;
        for (int i = 1; i <= m_; ++i)
        {
            size_t childIndex = m_ * index + i;
            if (childIndex < data_.size() && comp_(data_[childIndex], data_[bestChild]))
            {
                bestChild = childIndex;
            }
        }
        if (bestChild != index)
        {
            std::swap(data_[index], data_[bestChild]);
            heapifyDown(bestChild);
        }
    }
};

#endif
