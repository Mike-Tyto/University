#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "matrix.h"
#include "int.h"
#include "real.h"
#include "ring_info.h"

int main() {

    srand(time(NULL));
    int height = rand() % 5 + 1;
    int width = rand() % 5 + 1;

    Int* x;
    int choice;

    printf("Enter [1] to work with integer values\n");
    printf("Enter [2] to work with real values\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            x = IntConstruct(2);
            break;
        case 2:
            x = (Real*) x;
            x = RealConstruct(2.34);
            break;
        default:
            x = IntConstruct(2);
            break;
    }

    printf("Enter [1] to sum two matrices\n");
    printf("Enter [2] to transpose matrix\n");
    printf("Enter [3] to multiply two matrices\n");
    printf("Enter [4] to make linear combination\n");

    int operation;
    scanf("%d", &operation);

    printf("\nFirst matrix\n");
    Matrix *matrix1 = MatrixRandomGenerate(x->ring_info, height, width);
    MatrixPrint(matrix1);

    switch (operation){
        case 1:
            printf("\nSecond matrix\n");
            Matrix *matrix2 = MatrixRandomGenerate(x->ring_info,
                                                   height, width);
            MatrixPrint(matrix2);

            printf("\nSum of matrices\n");
            Matrix *matrixSum = MatrixSum(matrix1, matrix2);
            MatrixPrint(matrixSum);
            break;
        case 2:
            printf("\nTranspose of first matrix\n");
            Matrix *matrix_trans = MatrixTransposition(matrix1);
            MatrixPrint(matrix_trans);
            break;
        case 3:
            printf("\nSecond matrix\n");
            int width2 = rand() % 5 + 1;
            Matrix *matrix3 = MatrixRandomGenerate(x->ring_info,
                                                   width, width2);
            MatrixPrint(matrix3);

            printf("\nProduct of first and second matrices\n");
            Matrix *matrix_prod = MatrixProduct(matrix1, matrix3);
            MatrixPrint(matrix_prod);
            break;
        case 4:
            printf("\nLinear combination of first matrix\n");
            matrix1 = MatrixLinComb(matrix1);
            MatrixPrint(matrix1);
            break;
        default:
            break;
    }
    return 0;
}