#pragma once

#include "sequence.h"
#include "array.h"

template<typename T>
class ArraySequence : public Sequence<T>{
private:
    DynamicArray<T>* items;
public:
    ArraySequence() {
        this->items = new DynamicArray<T>();
    }

    ArraySequence(T* items, size_t size) {
        this->items = new DynamicArray<T>(items, size);
    }

    ArraySequence(const DynamicArray<T>& dynamicArray) {
        this->items = new DynamicArray<T>(dynamicArray);
    }

    virtual ~ArraySequence() {
        delete items;
    }

    Sequence<T>* Create() const override {
        return (Sequence<T>*) new ArraySequence<T>();
    }

//        T& GetFirst() const override {
//            return Get(0);
//        };

//        T& GetLast() const override {
//            int last = GetLength() - 1;
//            return Get(last);
//        };

    T& Get(int index) const override {
        return this->items->Get(index);
    };

    int GetLength() const noexcept override {
        return this->items->GetSize();
    }

    void Append(const T& item) noexcept override {
        int size = this->GetLength();
        this->items->Resize(size + 1);
        Set(size, item);
    }

    void Prepend(const T& item) noexcept override {
        int size = this->GetLength();
        this->items->Resize(size + 1);
        for (int i = size; i > 0; i--) {
            Set(i, Get(i - 1));
        }
        Set(0, item);
    }

    void InsertAt(const T& item, int index) override {
        if (index < 0 || index > this->GetLength()) {
            throw std::out_of_range("Index out of range");
        }

        if (index == 0){
            Prepend(item);
            return;
        }

        int size = this->GetLength();
        if (index == size){
            Append(item);
            return;
        }
        this->items->Resize(size + 1);
        for (int i = size; i > index; i--) {
            Set(i, Get(i - 1));
        }
        Set(index, item);
    }

    void Set(int index, T value) {
        this->items->Set(index, value);
    }

    auto& operator[] (const int index) const {
        return this->items->Get(index);
    }

    void Remove(int index) override {
        int size = this->GetLength();
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (int i = index; i > size - 1; i++) {
            Set(i, Get(i + 1));
        }
        this->items->Resize(size + 1);
   }
};