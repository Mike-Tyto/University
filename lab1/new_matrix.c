#include <malloc.h>
#include <string.h>
#include <stdio.h>


#include "new_matrix.h"

NewMatrix* NewMatrixConstruct(int height, int width, int size, RingInfo* ring_info) {
    NewMatrix* matrix = (NewMatrix*)malloc(sizeof(NewMatrix));
    matrix->lines = malloc(height * width * size);
    matrix->height = height;
    matrix->size = size;
    matrix->width = width;
    matrix->ring_info = ring_info;
    return matrix;
}

int GetInd(int i, int j, int width) {
    return i * width + j;
}

NewMatrix* NewMatrixFill(NewMatrix* matrix) {
    int width = matrix->width;
    int height = matrix->height;
    int size = matrix->size;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int ind = GetInd(i, j, width);
            void* buff = matrix->ring_info->generate();
            memcpy(((char*)matrix->lines) + ind * size, buff, size);
            free(buff);
        }
    }
    return matrix;
}

void NewMatrixPrint(NewMatrix* matrix) {
    int width = matrix->width;
    int height = matrix->height;
    int size = matrix->size;
    RingInfo* ring_info = matrix->ring_info;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int ind = GetInd(i, j, width);
            ring_info->print(matrix->lines + ind * size);
            printf(" ");
        }
        printf("\n");
    }
}

NewMatrix* NewMatrixSum(NewMatrix* matrix1, NewMatrix* matrix2){
    int width = matrix1->width;
    int height = matrix2->height;
    int size = matrix1->size;
    RingInfo* ring_info = matrix1->ring_info;
    NewMatrix* matrix_sum = NewMatrixConstruct(height, width, size ,ring_info);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int ind = GetInd(i, j, width);
            void* first = matrix1->lines + ind * size;
            void* second = matrix2->lines + ind * size;
            void* buff = ring_info->sum(first, second);
            memcpy(((char*)matrix_sum->lines) + ind * size, buff, size);
        }
    }
    return matrix_sum;
}

void NewMatrixFree(NewMatrix* matrix){
    free(matrix->lines);
    free(matrix);
}
