#include <time.h>
#include "new_matrix.h"
#include "ring_info.h"
#include "ring_info.c"
#include "int.h"
#include "real.h"
#include "int.c"

int main(){
    srand(time(NULL));
    RingInfo* ringInfo = RingInfoCreate(IntSum, IntMult, IntZero, IntOne, IntPrint, IntGenerate, IntLinMultGen);
    NewMatrix* matrix1 = NewMatrixConstruct(5, 4, sizeof(Int) ,ringInfo);
    matrix1 = NewMatrixFill(matrix1);
    NewMatrix* matrix2 = NewMatrixConstruct(5, 4, sizeof(Int) ,ringInfo);
    matrix2 = NewMatrixFill(matrix2);
    NewMatrixPrint(matrix1);
    printf("\n");
    NewMatrixPrint(matrix2);
    printf("\n");
    NewMatrix* matrix_sum = NewMatrixSum(matrix1, matrix2);
    NewMatrixPrint(matrix_sum);
    return 0;
}