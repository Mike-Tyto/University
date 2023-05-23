#pragma once
#include "ring_info.h"

typedef struct NewMatrix {
    int height;
    int width;
    int size;
    void* lines;
    RingInfo* ring_info;
}NewMatrix;

NewMatrix* NewMatrixSum(NewMatrix*, NewMatrix*);
NewMatrix* NewMatrixConstruct(int, int, int, RingInfo*);
NewMatrix* NewMatrixFill(NewMatrix*);
void NewMatrixPrint(NewMatrix*);
int GetInd(int, int, int);
void NewMatrixFree(NewMatrix*);