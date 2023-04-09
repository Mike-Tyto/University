#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ring_info.h"
#include "int.h"

Int* CreateInt() {
	return malloc(sizeof(Int));
}

Int* IntConstruct(int n) {
	Int* integer = CreateInt();
	integer->integer = n;
	integer->ring_info = RingInfoCreate(IntSum, IntMult, IntZero, IntOne, IntPrint, IntGenerate, IntLinMultGen);
	return integer;
}

void* IntSum(void* r1, void* r2) {
	double int1 = GetInt(r1);
	double int2 = GetInt(r2);
	double res = int1 + int2;
	return IntConstruct(res);
}

void* IntMult(void* r1, void* r2) {
	int int1 = GetInt(r1);
	int int2 = GetInt(r2);
	int res = int1 * int2;
	return IntConstruct(res);
}

Int* IntZero() {
	return IntConstruct(0);
}

Int* IntOne() {
	return IntConstruct(1);
}
void IntPrint(void* integer) {
	int value = GetInt((Int*)integer);
	printf("%d", value);
}

int GetInt(Int* integer) {
	return integer->integer;
}

void FreeInt(Int* integer) {
	free(integer->ring_info);
	integer->ring_info = NULL;
	free(integer);
	integer = NULL;
}

Int* IntGenerate() {
	return IntConstruct(rand() % 99 + 1);
}

Int* IntLinMultGen() {
    return IntConstruct(rand() % 11 - 5);
}