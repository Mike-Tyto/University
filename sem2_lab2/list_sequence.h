#pragma once

#include "sequence.h"
#include "list.h"

template<typename T>
class ListSequence : public Sequence<T>{
private:
    LinkedList<T>* items;
public:
    ListSequence() {
        this->items = new LinkedList<T>();
    }

    ListSequence(T* items, size_t size) {
        this->items = new LinkedList<T>(items, size);
    }

    ListSequence(const ListSequence<T>& listSequence) {
        this->items = new LinkedList<T>(listSequence);
    }

    template <typename... Args>
    ListSequence(T head, Args... args) {
        this->items = new LinkedList<T>(head, args...);
    }

    virtual ~ListSequence() {
        delete items;
    }

    using Iterator = typename LinkedList<T>::ListIterator;

    Iterator begin()
    {
        return items->begin();
    }

    Iterator end()
    {
        return items->end();
    }

    Sequence<T>* Create() const override {
        return (Sequence<T>*) new ListSequence<T>();
    }

    T& Get(int index) const override {
        return this->items->Get(index);
    };

    int GetLength() const noexcept override {
        return this->items->GetLength();
    }

    void Append(const T& item) noexcept override {
        this->items->Append(item);
    }

    void Prepend(const T& item) noexcept override {
        this->items->Prepend(item);
    }

    void InsertAt(const T& item, int index) override {
        if (index < 0 || index > this->GetLength()) {
            throw std::out_of_range("Index out of range");
        }
        this->items->InsertAt(index, item);
    }

    auto& operator[] (const int index) const {
        return this->items->Get(index);
    }

    void Remove(int index) override {
        this->items->Remove(index);
    }
};