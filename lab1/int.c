#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ring_info.h"
#include "int.h"

Int* CreateInt() {
	return (Int*)malloc(sizeof(Int));
}

Int* IntConstruct(int n) {
	Int* integer = CreateInt();
	integer->integer = n;
	integer->ring_info = RingInfoCreate(IntSum, IntMult, IntZero, IntOne, IntPrint, IntGenerate, IntLinMultGen);
	return integer;
}

void* IntSum(void* r1, void* r2) {
	int int1 = GetInt((Int*)r1);
	int int2 = GetInt((Int*)r2);
	int res = int1 + int2;
	return IntConstruct(res);
}

void* IntMult(void* r1, void* r2) {
	int int1 = GetInt((Int*)r1);
	int int2 = GetInt((Int*)r2);
	int res = int1 * int2;
	return (void*)IntConstruct(res);
}

void* IntZero() {
	return (void*)IntConstruct(0);
}

void* IntOne() {
	return (void*)IntConstruct(1);
}
void IntPrint(void* integer) {
	int value = GetInt((Int*)integer);
	printf("%d", value);
}

int GetInt(Int* integer) {
	return integer->integer;
}

void* IntGenerate() {
	return (void*)IntConstruct(rand() % 99 + 1);
}

void* IntLinMultGen() {
    return (void*)IntConstruct(rand() % 11 - 5);
}