#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ring_info.h"
#include "real.h"

Real* CreateReal() {
	return (Real*)malloc(sizeof(Real));
}

Real* RealConstruct(double n) {
	Real* real = CreateReal();
	real->real = n;
	real->ring_info = RingInfoCreate(RealSum, RealMult, RealZero, RealOne,
                                     RealPrint, RealGenerate, RealLinMultGen);
	return real;
}

void* RealSum(void* r1, void* r2) {
	double real1 = GetReal((Real*)r1);
	double real2 = GetReal((Real*)r2);
	double res = real1 + real2;
	return RealConstruct(res);
}

void* RealMult(void* r1, void* r2) {
	double real1 = GetReal((Real*)r1);
	double real2 = GetReal((Real*)r2);
	double res = real1 * real2;
	return RealConstruct(res);
}

void* RealZero() {
	return (void*)RealConstruct(0);
}
void* RealOne() {
	return (void*)RealConstruct(1);
}
void RealPrint(void* real) {
	double value = GetReal((Real*)real);
	printf("%.3f", value);
}

double GetReal(Real* real) {
	return real->real;
}

void* RealGenerate() {
	return (void*)RealConstruct((rand() % 4299)/43.0 + 1);
}

void* RealLinMultGen() {
    return (void*)RealConstruct((rand() % 9 - 4) + (rand() % 10) / 10.0);
}