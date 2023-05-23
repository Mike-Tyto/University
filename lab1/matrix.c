#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"

Element* ElementConstruct(RingInfo* ring_info, void* ptr) {
    Element* el = (Element*)malloc(sizeof(Element));
    el->ring_info = ring_info;
    el->value = ptr;
    return el;
}

Matrix* MatrixConstruct(int height, int width) {
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->width = width;
    matrix->height = height;
    Element*** lines = (Element***)malloc(height * sizeof(Element**));
    for (int i = 0; i < height; i++) {
        lines[i] = (Element**)malloc(width * sizeof(Element*));
    }

    matrix->lines = lines;

    return matrix;
}

Matrix* MatrixRandomGenerate(RingInfo* ringInfo, int height, int width) {
    Matrix* matrix = MatrixConstruct(height, width);
    for (int i = 0; i < matrix->height; i++) {
        for (int j = 0; j < matrix->width; j++) {
            void *randomValue = ringInfo->generate();
            Element* el = ElementConstruct(ringInfo, randomValue);
            matrix->lines[i][j] = el;
        }
    }
    return matrix;
}

void MatrixPrint(Matrix* matrix) {
    int width = matrix->width;
    int height = matrix->height;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Element *el = matrix->lines[i][j];
            el->ring_info->print(el->value);
            printf(" ");
        }
        printf("\n");
    }
}

Matrix* MatrixSum(Matrix* matrix1, Matrix* matrix2) {
    int width = matrix1->width;
    int height = matrix1->height;
    Matrix* matrix = MatrixConstruct(height, width);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Element* el1 = matrix1->lines[i][j];
            Element* el2 = matrix2->lines[i][j];
            void* x = el1->ring_info->sum(el1->value, el2->value);
            matrix->lines[i][j] = ElementConstruct(el1->ring_info, x);
        }
    }
    return matrix;
}

Matrix* MatrixProduct(Matrix* matrix1, Matrix* matrix2) {
    // NxM * MxK
    int width = matrix2->width; // K
    int height = matrix1->height; // N
    int height2 = matrix2->height; // M

    Matrix* matrix = MatrixConstruct(height, width); // NxK
    Element* el = matrix1->lines[0][0];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            void* first_prod = el->ring_info->mult(matrix1->lines[i][0]->value,
                                                   matrix2->lines[0][j]->value);
            matrix->lines[i][j] = ElementConstruct(el->ring_info,first_prod);
            for (int k = 1; k < height2; k++) {
                Element* el1 = matrix1->lines[i][k];
                Element* el2 = matrix2->lines[k][j];
                void* prod = el1->ring_info->mult(el1->value, el2->value);
                void* new_sum = el1->ring_info->sum(prod, matrix->lines[i][j]->value);
                matrix->lines[i][j] = ElementConstruct(el->ring_info,new_sum);
            }
        }
    }
    return matrix;
}

Matrix* MatrixTransposition(Matrix* matrix1) {
    int width = matrix1->width;
    int height = matrix1->height;
    Matrix* matrix = MatrixConstruct(width, height);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            matrix->lines[i][j] = matrix1->lines[j][i];
        }
    }
    return matrix;
}

Matrix* MatrixLinComb(Matrix* matrix, int ind) {
    int width = matrix->width;
    int height = matrix->height;
    Element* el = matrix->lines[0][0];
    for (int i = 0; i < height; i++) {
        if (i == ind) {
            continue;
        }
        void* mul = el->ring_info->lin_mult_gen();
        printf("multiplier of %d line =", i);
        el->ring_info->print(mul);
        printf("\n");
        for (int j = 0; j < width; j++) {
            void* prod = el->ring_info->mult(mul, matrix->lines[i][j]->value);
            void* new_sum = el->ring_info->sum(prod, matrix->lines[ind][j]->value);
            matrix->lines[ind][j] = ElementConstruct(el->ring_info,new_sum);
        }
    }
    return matrix;
}

void MatrixFree(Matrix* matrix){
    int height = matrix->height;
    int width = matrix->width;
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            free(matrix->lines[i][j]->value);
        }
        free(matrix->lines[i]);
    }

    free(matrix->lines);
}

