#include <chrono>
#include <iostream>

int foo(int a, int b){
    return a + b;
}

int main(){
    int a = 50;
    int b = 390;
    auto start = std::chrono::high_resolution_clock::now();
    int c = foo(a, b);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken by function: " << std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count() << " nanoseconds" << std::endl;
    std::cout<<c<<"\n";
    auto t =  std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count() * 2;
    std::cout<<t<<std::endl;
    return 0;
}