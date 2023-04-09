#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ring_info.h"
#include "real.h"

Real* CreateReal() {
	return malloc(sizeof(Real));
}

Real* RealConstruct(double n) {
	Real* real = CreateReal();
	real->real = n;
	real->ring_info = RingInfoCreate(RealSum, RealMult, RealZero, RealOne,
                                     RealPrint, RealGenerate, RealLinMultGen);
	return real;
}

void* RealSum(void* r1, void* r2) {
	double real1 = GetReal(r1);
	double real2 = GetReal(r2);
	double res = real1 + real2;
	return RealConstruct(res);
}

void* RealMult(void* r1, void* r2) {
	double real1 = GetReal(r1);
	double real2 = GetReal(r2);
	double res = real1 * real2;
	return RealConstruct(res);
}

Real* RealZero() {
	return RealConstruct(0);
}
Real* RealOne() {
	return RealConstruct(1);
}
void RealPrint(void* real) {
	double value = GetReal((Real*)real);
	printf("%.3f", value);
}

double GetReal(Real* real) {
	return real->real;
}

Real* RealGenerate() {
	return RealConstruct((rand() % 4299)/43.0 + 1);
}

Real* RealLinMultGen() {
    return RealConstruct((rand() % 9 - 4) + (rand() % 10) / 10.0);
}