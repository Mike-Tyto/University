#include <iostream>

#include "sequence.h"
#include "array_sequence.h"
#include "list_sequence.h"
#include <cassert>


void TestArrSeq() {
    // Create
    Sequence<int>* as1 = new ArraySequence<int>;
    assert(as1->GetLength() == 0);

    // Append
    as1->Append(1);
    as1->Append(2);
    as1->Append(3);
    assert(as1->GetLength() == 3);
    assert(as1->Get(0) == 1);
    assert(as1->Get(1) == 2);
    assert(as1->Get(2) == 3);

    // Prepend
    as1->Prepend(0);
    assert(as1->GetLength() == 4);
    assert(as1->Get(0) == 0);
    assert(as1->Get(1) == 1);
    assert(as1->Get(2) == 2);
    assert(as1->Get(3) == 3);

    // InsertAt
    as1->InsertAt(4, 2);
    assert(as1->GetLength() == 5);
    assert(as1->Get(0) == 0);
    assert(as1->Get(1) == 1);
    assert(as1->Get(2) == 4);
    assert(as1->Get(3) == 2);
    assert(as1->Get(4) == 3);

    // GetFirst
    assert(as1->GetFirst() == 0);

    // GetLast
    assert(as1->GetLast() == 3);

    // GetSubsequence
    auto* as_sub = as1->GetSubsequence(1, 3);
    assert(as1->GetLength() == 5);
    assert(as_sub->GetLength() == 3);
    assert(as_sub->Get(0) == 1);
    assert(as_sub->Get(1) == 4);
    assert(as_sub->Get(2) == 2);

    // Concat
    auto* as_concat = as1->Concat(as_sub);
    assert(as1->GetLength() == 5);
    assert(as_sub->GetLength() == 3);
    assert(as_concat->GetLength() == 8);
    assert(as_concat->Get(0) == 0);
    assert(as_concat->Get(1) == 1);
    assert(as_concat->Get(2) == 4);
    assert(as_concat->Get(3) == 2);
    assert(as_concat->Get(4) == 3);
    assert(as_concat->Get(5) == 1);
    assert(as_concat->Get(6) == 4);
    assert(as_concat->Get(7) == 2);

    // Map
    auto make_double = [](int& val) { return val * 2; };
    auto* as_map = as1->Map(make_double);
    assert(as_map->GetLength() == 5);
    assert(as_map->Get(0) == 0);
    assert(as_map->Get(1) == 2);
    assert(as_map->Get(2) == 8);
    assert(as_map->Get(3) == 4);
    assert(as_map->Get(4) == 6);

    // Where
    auto IsOdd = [](int& val) { return val % 2 == 1; };
    auto* as_where = as1->Where(IsOdd);
    assert(as_where->GetLength() == 2);
    assert(as_where->Get(0) == 1);
    assert(as_where->Get(1) == 3);

    // Reduce
    auto Sum = [](int& val1, int& val2) { return val1 + val2; };
    auto as_sum = as1->Reduce(Sum, 5);
    assert(as_sum == 15);

    delete as1;
    delete as_sub;
    delete as_concat;
    delete as_map;
    delete as_where;

    std::cout << "ArraySequence tests were passed!" << std::endl;
}

void TestListSeq() {
        // Create
    Sequence<int>* ls1 = new ListSequence<int>;
    assert(ls1->GetLength() == 0);

    // Append
    ls1->Append(1);
    ls1->Append(2);
    ls1->Append(3);
    assert(ls1->GetLength() == 3);
    assert(ls1->Get(0) == 1);
    assert(ls1->Get(1) == 2);
    assert(ls1->Get(2) == 3);

    // Prepend
    ls1->Prepend(0);
    assert(ls1->GetLength() == 4);
    assert(ls1->Get(0) == 0);
    assert(ls1->Get(1) == 1);
    assert(ls1->Get(2) == 2);
    assert(ls1->Get(3) == 3);

    // InsertAt
    ls1->InsertAt(4, 2);
    assert(ls1->GetLength() == 5);
    assert(ls1->Get(0) == 0);
    assert(ls1->Get(1) == 1);
    assert(ls1->Get(2) == 4);
    assert(ls1->Get(3) == 2);
    assert(ls1->Get(4) == 3);

    // GetFirst
    assert(ls1->GetFirst() == 0);

    // GetLast
    assert(ls1->GetLast() == 3);

    // GetSubsequence
    auto* ls_sub = ls1->GetSubsequence(1, 3);
    assert(ls1->GetLength() == 5);
    assert(ls_sub->GetLength() == 3);
    assert(ls_sub->Get(0) == 1);
    assert(ls_sub->Get(1) == 4);
    assert(ls_sub->Get(2) == 2);

    // Concat
    auto* ls_concat = ls1->Concat(ls_sub);
    assert(ls1->GetLength() == 5);
    assert(ls_sub->GetLength() == 3);
    assert(ls_concat->GetLength() == 8);
    assert(ls_concat->Get(0) == 0);
    assert(ls_concat->Get(1) == 1);
    assert(ls_concat->Get(2) == 4);
    assert(ls_concat->Get(3) == 2);
    assert(ls_concat->Get(4) == 3);
    assert(ls_concat->Get(5) == 1);
    assert(ls_concat->Get(6) == 4);
    assert(ls_concat->Get(7) == 2);

    // Map
    auto MakeDouble = [](int& val) { return val * 2; };
    auto* ls_map = ls1->Map(MakeDouble);
    assert(ls_map->GetLength() == 5);
    assert(ls_map->Get(0) == 0);
    assert(ls_map->Get(1) == 2);
    assert(ls_map->Get(2) == 8);
    assert(ls_map->Get(3) == 4);
    assert(ls_map->Get(4) == 6);

    // Where
    auto IsOdd = [](int& val) { return val % 2 == 1; };
    auto* ls_where = ls1->Where(IsOdd);
    assert(ls_where->GetLength() == 2);
    assert(ls_where->Get(0) == 1);
    assert(ls_where->Get(1) == 3);

    // Reduce
    auto Sum = [](int& val1, int& val2) { return val1 + val2; };
    auto ls_sum = ls1->Reduce(Sum, 5);
    assert(ls_sum == 15);

    delete ls1;
    delete ls_sub;
    delete ls_concat;
    delete ls_map;
    delete ls_where;

    std::cout << "ListSequence tests passed!" << std::endl;
}

int main() {
    TestArrSeq();
    TestListSeq();
    return 0;
}