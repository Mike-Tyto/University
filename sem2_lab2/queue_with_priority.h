#pragma once

#include "sequence.h"
#include "pair.h"

// template <typename T>
// using Mapper = T(*)(T&);

// template <typename T>
// using Condition = bool(*)(T&);

// template <typename T>
// using Reducer = T(*)(T&, T&);

template<typename T, typename K>
class PriorityQueue {
private:
    Sequence<Pair<T, K>>* items;
public:
    PriorityQueue() {
        this->items = new ListSequence<Pair<T, K>>();
    }

    PriorityQueue(Pair<T, K>* items, size_t size) {
        this->items = new ListSequence<Pair<T, K>>(items, size);
    }

    PriorityQueue(const PriorityQueue<T, K>& queue) {
        this->items = new ListSequence<Pair<T, K>>();
        for (int i = 0; i < queue.Count(); i++) {
            this->InsertWithPriority(queue.Peek(i));
        }
    }

    ~PriorityQueue()
    {}

    int Count() const noexcept {
        return this->items->GetLength();
    }

    const Pair<T, K>& Peek(int ind) const {
        return this->items->Get(ind);
    }

    void InsertAt(const T& item, int index) {
        this->items->InsertAt(item, index);
    }

    void InsertWithPriority(Pair<T, K> value) noexcept{
        int i = 0;
        int len = this->Count();
        for (i; i < len; i++){
            if (value.GetLast() < this->Peek(i).GetLast()){
                break;
            }
        }
        this->items->InsertAt(value, i);
    }

    PriorityQueue<T, K> ConcatWithPriority(const PriorityQueue<T, K>& queue) {
        auto copy1 = queue;
        int len = this->Count();
        for (int i = 0; i < len; i++) {
            copy1.InsertWithPriority(this->Peek(i));
        }
        return copy1;
    }

    friend std::ostream& operator<< (std::ostream& os, const PriorityQueue<T, K>& queue) {
        os << queue.items;
        return os;
    }

    // PriorityQueue<T, K> Map(Mapper<T> func) {
    //     auto copy = this->items->Map(func);
    //     Queue<T> res = copy;
    //     delete copy;
    //     return res;
        
    // }

    // PriorityQueue<T, K> Where(Condition<T> filter) {
    //     auto copy = this->items->Where(filter);
    //     PriorityQueue<T, K> res = copy;
    //     delete copy;
    //     return res;
    // }

    // T Reduce (Reducer<T> reduce, T base) const {
    //     return this->items->Reduce(reduce, base);
    // }
};