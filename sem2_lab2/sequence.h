#pragma once

#include <functional>
#include <iostream>

template <typename T>
using Mapper = T(*)(T&);

template <typename T>
using Condition = bool(*)(T&);

template <typename T>
using Reducer = T(*)(T&, T&);

template<typename T>
class Sequence{
public:
    virtual ~Sequence() {};
    virtual Sequence<T>* Create() const = 0;
    virtual T& Get(int index) const = 0;
    virtual int GetLength() const noexcept = 0;
    virtual void Append(const T& item) noexcept = 0;
    virtual void Prepend(const T& item) noexcept = 0;
    virtual void InsertAt(const T& item, int index) = 0;
    virtual void Remove(int index) = 0;

T& GetFirst() const {
    if (this->IsEmpty()) {
        throw std::out_of_range("Index out of range");
    }
    return Get(0);
};

T& GetLast() const {
    if (this->IsEmpty()) {
        throw std::out_of_range("Index out of range");
    }
    int last = GetLength() - 1;
    return Get(last);
};

    Sequence<T>* GetSubsequence(int startIndex, int endIndex){
        if (startIndex < 0 || endIndex >= this->GetLength()) {
            throw std::out_of_range("Index out of range");
        }

        Sequence<T>* res = this->Create();
        for (int i = startIndex; i <= endIndex; i++){
            res->Append(this->Get(i));
        }
        return res;
    }

    Sequence<T>* Concat(Sequence <T> *list) {
        Sequence<T>* res = this->Create();

        for (int i = 0; i < this->GetLength(); i++){
            res->Append(this->Get(i));
        }

        for (int i = 0; i < list->GetLength(); i++){
            res->Append(list->Get(i));
        }
        return res;
    }

    bool IsEmpty() const noexcept{
        return this->GetLength() == 0;
    }

    friend std::ostream& operator<< (std::ostream& os, Sequence<T>* array) {
        if (array->GetLength() == 0) {
            os << "[]";
        }
        else {
            os << "[";

            for (size_t i = 0; i < array->GetLength() - 1; i++) {
                os << array->Get(i) << ", ";
            }
            os << array->Get(array->GetLength() - 1) << "]";
        }
        return os;
    }

    bool operator== (const Sequence<T>& sequence)
    {
        if (this->GetLength() != sequence.GetLength()) {
            return false;
        }

        for (int i = 0; i < this->GetLength(); i++)
        {
            if (this->Get(i) != sequence.Get(i)) {
                return false;
            }
        }

        return true;
    }

    auto& operator[] (const int index) const {
        return this->Get(index);
    }

    Sequence<T>* Map(Mapper<T> func) const {
        Sequence<T>* result = this->Create();

        for (size_t i = 0; i < this->GetLength(); i++)
            result->Append(func(this->Get(i)));

        return result;
    }

    Sequence<T>* Where(Condition<T> filter) const {
        Sequence<T>* result = this->Create();

        for (size_t i = 0; i < this->GetLength(); i++) {
            if (filter(this->Get(i)))
                result->Append(this->Get(i));
        }

        return result;
    }

    T Reduce(Reducer<T> reduce, T base) const {

        for (size_t i = 0; i < GetLength(); i++) {
            base = reduce(Get(i), base);
        }

        return base;
    }
};