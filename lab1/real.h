#pragma once

#include "ring_info.h"

typedef struct Real {
	RingInfo* ring_info;
	double real;
}Real;

Real* RealConstruct(double);
void* RealSum(void*, void*);
void* RealMult(void*, void*);
Real* RealZero();
Real* RealOne();

Real* RealGenerate();
void RealPrint(void*);
double GetReal(Real*);
Real* RealLinMultGen();
