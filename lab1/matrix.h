#pragma once
#include "ring_info.h"

typedef struct Element {
    RingInfo* ring_info;
    void* value;
} Element;

typedef struct Matrix {
    int height;
    int width;
    Element*** lines;
}Matrix;

Matrix* MatrixConstruct(int, int);
Element* ElementConstruct(RingInfo*, void*);
Matrix* MatrixRandomGenerate(RingInfo*, int, int);
void MatrixPrint(Matrix*);
Matrix* MatrixSum(Matrix*, Matrix*);
Matrix* MatrixProduct(Matrix*, Matrix*);
Matrix* MatrixTransposition(Matrix*);
Matrix* MatrixLinComb(Matrix*, int);
void MatrixFree(Matrix*);
