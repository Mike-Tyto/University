#include <iostream>
#include "queue.h"
#include "queue_with_priority.h"
#include "pair.h"
#include "structures.h"

int main() {
    int arr[] = {1, 2, 3, 4};
    Queue<int> queue(arr, 4);
    std::cout << queue << std::endl;
    // delete[] queue;
    queue.Enqueue(5);
    std::cout << queue << std::endl;
    std::cout << queue << std::endl;
    std::cout << queue.Peek(2) << std::endl;
    std::cout << "len: " << queue.Count() << std::endl;

    auto MakeDouble = [](int& val) { return val * 2; };
    auto IsOdd = [](int& val) { return val % 2 == 1; };
    auto Sum = [](int& val1, int& val2) { return val1 + val2; };

    auto map0 = queue.Map(MakeDouble);
    auto where0 = queue.Where(IsOdd);
    auto reduce0 = queue.Reduce(Sum, 0);
    auto concat0 = queue.Concat(map0);
    auto sub0 = concat0.GetSubQueue(2, 5);

    std::cout << map0 << std::endl;
    std::cout << where0 << std::endl;
    std::cout << reduce0 << std::endl;
    std::cout << concat0 << std::endl;
    std::cout << sub0 << std::endl;
    std::cout << queue << std::endl;


    Pair<int, int> pair(1, 5);
    std::cout << pair.GetFirst() << std::endl;
    Pair<int, int> new_pair = pair;
    std::cout << new_pair.GetLast() << std::endl;

    Complex a(1, 2);
    Complex b(3, 4);
    Complex c = a * 5;
    std::cout << &a << ' ' << &b << ' ' << &c << std::endl;

    Person A(1, "AB", "BC", "CD", 18);
    Person B(2, "DE", "BD", "EF", 21);
    std::cout << &A << std::endl;
    std::cout << &B << std::endl;

    Pair<int, int> p1(5, 10);
    Pair<int, int> p2(6, 15);
    Pair<int, int> p3(10, 100);
    Pair<int, int> p4(7, 1);
    Pair<int, int> p5(-5, 17);
    Pair<int, int> p6(-6, 20);
    Pair<int, int> arr1[] = {p1, p2, p3};
    Pair<int, int> arr2[] = {p4, p5, p6};
    PriorityQueue<int, int> pq1(arr1, 3);
    std::cout << pq1 << std::endl;
    PriorityQueue<int, int> pq2(arr2, 3);
    std::cout << pq2 << std::endl;
    // pq1.InsertWithPriority(p5);
    // std::cout << pq1 << std::endl;
    PriorityQueue<int, int> pq3 = pq1.ConcatWithPriority(pq2);
    std::cout << pq3 << std::endl;
    return 0;
}