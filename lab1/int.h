#pragma once

#include "ring_info.h"

typedef struct Int {
    RingInfo* ring_info;
    int integer;
}Int;

Int* IntConstruct(int);
void* IntSum(void*, void*);
void* IntMult(void*, void*);
Int* IntZero();
Int* IntOne();
Int* IntGenerate();
void IntPrint(void*);
int GetInt(Int*);
Int* IntLinMultGen();
