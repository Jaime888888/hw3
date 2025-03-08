#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <functional>
#include <stdexcept>

template <typename T, typename Compare = std::less<T>>
class Heap
{
public:
    Heap() {}

    void push(const T& item)
    {
        data.push_back(item);
        siftUp(data.size() - 1);
    }

    void pop()
    {
        if (data.empty()) throw std::out_of_range("Heap is empty");
        std::swap(data[0], data[data.size() - 1]);
        data.pop_back();
        siftDown(0);
    }

    T top() const
    {
        if (data.empty()) throw std::out_of_range("Heap is empty");
        return data[0];
    }

    bool empty() const { return data.empty(); }
    size_t size() const { return data.size(); }

private:
    std::vector<T> data;
    Compare comp;

    void siftUp(size_t index)
    {
        while (index > 0)
        {
            size_t parent = (index - 1) / 2;
            if (comp(data[parent], data[index])) break;
            std::swap(data[parent], data[index]);
            index = parent;
        }
    }

    void siftDown(size_t index)
    {
        size_t left, right, smallest;
        while ((left = 2 * index + 1) < data.size())
        {
            right = left + 1;
            smallest = (right < data.size() && comp(data[right], data[left])) ? right : left;
            if (comp(data[index], data[smallest])) break;
            std::swap(data[index], data[smallest]);
            index = smallest;
        }
    }
};

#endif
