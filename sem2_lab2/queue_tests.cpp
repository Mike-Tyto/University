#include <iostream>
#include <cassert>

#include "queue.h"
#include "pair.h"

// For better navigation:
// IntTests
// DoubleTests
// ComplexTests
// Aftermaths

void print(const char* c) {
    std::cout << "\t" << c << " test was passed!"<< std::endl;
}

// IntTests
void TestQueueIntCreate() {
    int arr[] = {1, 2, 3};
    Queue<int> q1(arr, 3);
    assert(q1.Count() == 3);
    assert(q1.Peek(0) == 1);
    assert(q1.Peek(1) == 2);
    assert(q1.Peek(2) == 3);
    print("Create");
}

void TestQueueIntEnqueue() {
    int arr[] = {1, 2, 3};
    Queue<int> q1(arr, 3);
    q1.Enqueue(5);
    assert(q1.Count() == 4);
    assert(q1.Peek(0) == 1);
    assert(q1.Peek(1) == 2);
    assert(q1.Peek(2) == 3);
    assert(q1.Peek(3) == 5);
    print("Enqueue");
}

void TestQueueIntDequeue() {
    int arr[] = {1, 2, 3};
    Queue<int> q1(arr, 3);
    assert(q1.Dequeue() == 1);
    assert(q1.Count() == 2);
    assert(q1.Peek(0) == 2);
    assert(q1.Peek(1) == 3);
    print("Dequeue");
}

void TestQueueIntConcat() {
    int arr1[] = {1, 2, 3};
    Queue<int> q1(arr1, 3);
    int arr2[] = {2, 4, 6};
    Queue<int> q2(arr2, 3);
    Queue<int> q_concat = q1.Concat(q2);
    assert(q_concat.Count() == 6);
    assert(q_concat.Peek(0) == 1);
    assert(q_concat.Peek(1) == 2);
    assert(q_concat.Peek(2) == 3);
    assert(q_concat.Peek(3) == 2);
    assert(q_concat.Peek(4) == 4);
    assert(q_concat.Peek(5) == 6);
    print("Concat");
}

void TestQueueIntSubQueue() {
    int arr1[] = {1, 2, 3, 2, 4, 6};
    Queue<int> q1(arr1, 6);
    Queue<int> q_sub = q1.GetSubQueue(2, 4);
    assert(q_sub.Count() == 3);
    assert(q_sub.Peek(0) == 3);
    assert(q_sub.Peek(1) == 2);
    assert(q_sub.Peek(2) == 4);
    print("Subqueue");
}

void TestQueueIntMap() {
    int arr[] = {1, 2, 3};
    Queue<int> q1(arr, 3);
    auto MakeDouble = [](int& val) { return val * 2; };
    auto q_map = q1.Map(MakeDouble);
    assert(q_map.Count() == 3);
    assert(q_map.Peek(0) == 2);
    assert(q_map.Peek(1) == 4);
    assert(q_map.Peek(2) == 6);
    print("Map");
}

void TestQueueIntWhere() {
    int arr[] = {1, 2, 3};
    Queue<int> q1(arr, 3);
    auto IsOdd = [](int& val) { return val % 2 == 1; };
    auto q_where = q1.Where(IsOdd);
    assert(q_where.Count() == 2);
    assert(q_where.Peek(0) == 1);
    assert(q_where.Peek(1) == 3);
    print("Where");
}

void TestQueueIntReduce() {
    int arr[] = {1, 2, 3};
    Queue<int> q1(arr, 3);
    auto Sum = [](int& val1, int& val2) { return val1 + val2; };
    auto q_reduce = q1.Reduce(Sum, 0);
    assert(q_reduce == 6);
    print("Reduce");
}

// DoubleTests
void TestQueueDoubleCreate() {
    double arr[] = {1.1, 2.2, 3.3};
    Queue<double> q1(arr, 3);
    assert(q1.Count() == 3);
    assert(q1.Peek(0) == 1.1);
    assert(q1.Peek(1) == 2.2);
    assert(q1.Peek(2) == 3.3);
    print("Create");
}

void TestQueueDoubleEnqueue() {
    double arr[] = {1.1, 2.2, 3.3};
    Queue<double> q1(arr, 3);
    q1.Enqueue(5.5);
    assert(q1.Count() == 4);
    assert(q1.Peek(0) == 1.1);
    assert(q1.Peek(1) == 2.2);
    assert(q1.Peek(2) == 3.3);
    assert(q1.Peek(3) == 5.5);
    print("Enqueue");
}

void TestQueueDoubleDequeue() {
    double arr[] = {1.1, 2.2, 3.3};
    Queue<double> q1(arr, 3);
    assert(q1.Dequeue() == 1.1);
    assert(q1.Count() == 2);
    assert(q1.Peek(0) == 2.2);
    assert(q1.Peek(1) == 3.3);
    print("Dequeue");
}

void TestQueueDoubleConcat() {
    double arr1[] = {1.1, 2.2, 3.3};
    Queue<double> q1(arr1, 3);
    double arr2[] = {2.2, 4.4, 6.6};
    Queue<double> q2(arr2, 3);
    Queue<double> q_concat = q1.Concat(q2);
    assert(q_concat.Count() == 6);
    assert(q_concat.Peek(0) == 1.1);
    assert(q_concat.Peek(1) == 2.2);
    assert(q_concat.Peek(2) == 3.3);
    assert(q_concat.Peek(3) == 2.2);
    assert(q_concat.Peek(4) == 4.4);
    assert(q_concat.Peek(5) == 6.6);
    print("Concat");
}

void TestQueueDoubleSubQueue() {
    double arr1[] = {1.1, 2.2, 3.3, 2.2, 4.4, 6.6};
    Queue<double> q1(arr1, 6);
    Queue<double> q_sub = q1.GetSubQueue(2, 4);
    assert(q_sub.Count() == 3);
    assert(q_sub.Peek(0) == 3.3);
    assert(q_sub.Peek(1) == 2.2);
    assert(q_sub.Peek(2) == 4.4);
    print("Subqueue");
}

void TestQueueDoubleMap() {
    double arr[] = {1.1, 2.2, 3.3};
    Queue<double> q1(arr, 3);
    auto MakeDouble = [](double& val) { return val * 2; };
    auto q_map = q1.Map(MakeDouble);
    assert(q_map.Count() == 3);
    assert(q_map.Peek(0) == 2.2);
    assert(q_map.Peek(1) == 4.4);
    assert(q_map.Peek(2) == 6.6);
    print("Map");
}

void TestQueueDoubleWhere() {
    double arr[] = {1.1, -2.2, -3.3, 0};
    Queue<double> q1(arr, 3);
    auto IsNeg = [](double& val) { return val < 0; };
    auto q_where = q1.Where(IsNeg);
    assert(q_where.Count() == 2);
    assert(q_where.Peek(0) == -2.2);
    assert(q_where.Peek(1) == -3.3);
    print("Where");
}

void TestQueueDoubleReduce() {
    double arr[] = {1.1, 2.2, 3.3};
    Queue<double> q1(arr, 3);
    auto Sum = [](double& val1, double& val2) { return val1 + val2; };
    auto q_reduce = q1.Reduce(Sum, 0);
    assert(q_reduce == 6.6);
    print("Reduce");
}

// ComplexTests
void TestQueueComplexCreate() {
    double arr[] = {1.1, 2.2, 3.3};
    Queue<double> q1(arr, 3);
    assert(q1.Count() == 3);
    assert(q1.Peek(0) == 1.1);
    assert(q1.Peek(1) == 2.2);
    assert(q1.Peek(2) == 3.3);
    print("Create");
}

void TestQueueComplexEnqueue() {
    double arr[] = {1.1, 2.2, 3.3};
    Queue<double> q1(arr, 3);
    q1.Enqueue(5.5);
    assert(q1.Count() == 4);
    assert(q1.Peek(0) == 1.1);
    assert(q1.Peek(1) == 2.2);
    assert(q1.Peek(2) == 3.3);
    assert(q1.Peek(3) == 5.5);
    print("Enqueue");
}

void TestQueueComplexDequeue() {
    double arr[] = {1.1, 2.2, 3.3};
    Queue<double> q1(arr, 3);
    assert(q1.Dequeue() == 1.1);
    assert(q1.Count() == 2);
    assert(q1.Peek(0) == 2.2);
    assert(q1.Peek(1) == 3.3);
    print("Dequeue");
}

void TestQueueComplexConcat() {
    double arr1[] = {1.1, 2.2, 3.3};
    Queue<double> q1(arr1, 3);
    double arr2[] = {2.2, 4.4, 6.6};
    Queue<double> q2(arr2, 3);
    Queue<double> q_concat = q1.Concat(q2);
    assert(q_concat.Count() == 6);
    assert(q_concat.Peek(0) == 1.1);
    assert(q_concat.Peek(1) == 2.2);
    assert(q_concat.Peek(2) == 3.3);
    assert(q_concat.Peek(3) == 2.2);
    assert(q_concat.Peek(4) == 4.4);
    assert(q_concat.Peek(5) == 6.6);
    print("Concat");
}

void TestQueueComplexSubQueue() {
    double arr1[] = {1.1, 2.2, 3.3, 2.2, 4.4, 6.6};
    Queue<double> q1(arr1, 6);
    Queue<double> q_sub = q1.GetSubQueue(2, 4);
    assert(q_sub.Count() == 3);
    assert(q_sub.Peek(0) == 3.3);
    assert(q_sub.Peek(1) == 2.2);
    assert(q_sub.Peek(2) == 4.4);
    print("Subqueue");
}

void TestQueueComplexMap() {
    double arr[] = {1.1, 2.2, 3.3};
    Queue<double> q1(arr, 3);
    auto MakeDouble = [](double& val) { return val * 2; };
    auto q_map = q1.Map(MakeDouble);
    assert(q_map.Count() == 3);
    assert(q_map.Peek(0) == 2.2);
    assert(q_map.Peek(1) == 4.4);
    assert(q_map.Peek(2) == 6.6);
    print("Map");
}

void TestQueueComplexWhere() {
    double arr[] = {1.1, -2.2, -3.3, 0};
    Queue<double> q1(arr, 3);
    auto IsNeg = [](double& val) { return val < 0; };
    auto q_where = q1.Where(IsNeg);
    assert(q_where.Count() == 2);
    assert(q_where.Peek(0) == -2.2);
    assert(q_where.Peek(1) == -3.3);
    print("Where");
}

void TestQueueComplexReduce() {
    double arr[] = {1.1, 2.2, 3.3};
    Queue<double> q1(arr, 3);
    auto Sum = [](double& val1, double& val2) { return val1 + val2; };
    auto q_reduce = q1.Reduce(Sum, 0);
    assert(q_reduce == 6.6);
    print("Reduce");
}

// Aftermaths
void TestQueueInt() {
    std::cout << "Int Queue Tests:" << std::endl;
    TestQueueIntCreate();
    TestQueueIntEnqueue();
    TestQueueIntDequeue();
    TestQueueIntConcat();
    TestQueueIntSubQueue();
    TestQueueIntMap();
    TestQueueIntWhere();
    TestQueueIntReduce();

    std::cout << "All int queue tests were passed!\n" << std::endl;;
}

void TestQueueDouble() {
    std::cout << "Double Queue Tests:" << std::endl;
    TestQueueDoubleCreate();
    TestQueueDoubleEnqueue();
    TestQueueDoubleDequeue();
    TestQueueDoubleConcat();
    TestQueueDoubleSubQueue();
    TestQueueDoubleMap();
    TestQueueDoubleWhere();
    TestQueueDoubleReduce();

    std::cout << "All double queue tests were passed!\n" << std::endl;;
}

void TestQueueComplex() {
    std::cout << "Complex Queue Tests:" << std::endl;
    TestQueueComplexCreate();
    TestQueueComplexEnqueue();
    TestQueueComplexDequeue();
    TestQueueComplexConcat();
    TestQueueComplexSubQueue();
    TestQueueComplexMap();
    TestQueueComplexWhere();
    TestQueueComplexReduce();

    std::cout << "All complex queue tests were passed!\n" << std::endl;;
}

void TestQueue() {
    TestQueueInt();
    TestQueueDouble();
    TestQueueComplex();

    std::cout << "All queue tests were passed!\n";
}

int main() {
    TestQueue();
    return 0;
}