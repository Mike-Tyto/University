#pragma once

#include "ring_info.h"

typedef struct Real {
	RingInfo* ring_info;
	double real;
}Real;

Real* RealConstruct(double);
void* RealSum(void*, void*);
void* RealMult(void*, void*);
void* RealZero();
void* RealOne();

void* RealGenerate();
void RealPrint(void*);
double GetReal(Real*);
void* RealLinMultGen();
