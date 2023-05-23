#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <iostream>
#include <fstream>

#include "new_matrix.h"
#include "new_matrix.c"
#include "matrix.h"
#include "matrix.c"
#include "ring_info.h"
#include "ring_info.c"
#include "int.h"
#include "int.c"
#include "real.h"
#include "real.c"

using namespace std::chrono;

int NewMatrixSum(char* file_name, RingInfo* ring_info){
    std::ofstream file;
    file.open(file_name);
    srand(time(NULL));
    if (!file.is_open()) {
        fprintf(stderr, "Can't open file\n");
        return 1;
    }
    double new_log[5] = {0};
    for (int n = 1000; n <= 5000; n += 1000) {
        for (int i = 0; i < 5; i++) {
            //double new_start = 0, new_end = 0;

            NewMatrix* new_matrix1 = NewMatrixConstruct(n, n, sizeof(Int) ,ring_info);
            new_matrix1 = NewMatrixFill(new_matrix1);
            NewMatrix* new_matrix2 = NewMatrixConstruct(n, n, sizeof(Int) ,ring_info);
            new_matrix2 = NewMatrixFill(new_matrix2);

            auto start = steady_clock::now();
            NewMatrix* new_matrix_sum = NewMatrixSum(new_matrix1, new_matrix2);
            auto end = steady_clock::now();
            std::chrono::duration<double> duration = end - start;
            auto time = duration_cast<milliseconds>(duration).count();
            file<<n<<"-"<<i<<": "<<new_log[i]<<std::endl;
            new_log[n/1000 - 1] += time;

            NewMatrixFree(new_matrix1);
            NewMatrixFree(new_matrix2);
            NewMatrixFree(new_matrix_sum);
            std::cout<<n<<": "<<time<<std::endl;
        }
    }
    printf("==============================\n");
    for (int i = 0; i < 5; i++) {
        new_log[i] = new_log[i]/5;
        std::cout<<new_log[i]<<std::endl;
        file<<new_log[i]<<std::endl;
    }
    file.close();
    return 0;
}

int MatrixSum(char* file_name, RingInfo* ring_info){
    std::ofstream file;
    file.open(file_name);
    srand(time(NULL));
    if (!file.is_open()) {
        fprintf(stderr, "Can't open file\n");
        return 1;
    }
    double log[5] = {0};
    for (int n = 1000; n <= 5000; n += 1000) {
        for (int i = 0; i < 5; i++) {
            //double start = 0, end = 0;

            Matrix* matrix1 = MatrixRandomGenerate(ring_info, n, n);
            Matrix* matrix2 = MatrixRandomGenerate(ring_info, n, n);

            auto start = steady_clock::now();
            Matrix* matrix_sum = MatrixSum(matrix1, matrix2);
            auto end = steady_clock::now();
            std::chrono::duration<double> duration = end - start;
            auto time = duration_cast<milliseconds>(duration).count();
            file<<n<<"-"<<i<<": "<<log[i]<<std::endl;
            log[n/1000 - 1] += time;

            MatrixFree(matrix1);
            MatrixFree(matrix2);
            MatrixFree(matrix_sum);
            std::cout<<n<<": "<<time<<std::endl;
        }
    }
    printf("==============================\n");
    for (int i = 0; i < 5; i++) {
        log[i] = log[i]/5;
        std::cout<<log[i]<<std::endl;
        file<<log[i]<<std::endl;
    }
    file.close();
    return 0;
}

void new_int_case() {
    char* new_int_file = "/mnt/c/Users/4842394/CLionProjects/sem2/new_int_time.txt";
    RingInfo* new_int_ring_info = RingInfoCreate(IntSum,
                                        IntMult,
                                        IntZero,
                                        IntOne,
                                        IntPrint,
                                        IntGenerate,
                                        IntLinMultGen);
    NewMatrixSum(new_int_file, new_int_ring_info);
}

void new_real_case() {
    char* new_real_file = "/mnt/c/Users/4842394/CLionProjects/sem2/new_real_time.txt";
    RingInfo* new_real_ring_info = RingInfoCreate(RealSum,
                                         RealMult, 
                                         RealZero,
                                         RealOne,
                                         RealPrint,
                                         RealGenerate,
                                         RealLinMultGen);
    NewMatrixSum(new_real_file, new_real_ring_info);
}

void int_case() {
    char* int_file = "/mnt/c/Users/4842394/CLionProjects/sem2/int_time.txt";
    Int* x = IntConstruct(2);
    MatrixSum(int_file, x->ring_info);
}

void real_case() {
    char* real_file = "/mnt/c/Users/4842394/CLionProjects/sem2/real_time.txt";
    Real* x = RealConstruct(2.5);
    MatrixSum(real_file, x->ring_info);
}

int main(){
    new_int_case();
    //  printf("===================\n");
    //  new_real_case();
    //  printf("===================\n");
    //  int_case();
    //  printf("===================\n");
    //  real_case();
    return 0;
}