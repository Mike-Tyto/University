#pragma once

typedef void* (*Sum) (void*, void*);
typedef void* (*Mult) (void*, void*);
typedef void* (*Zero)();
typedef void* (*One)();
typedef void (*Print) (void*);
typedef void* (*Generate)();
typedef  void* (*LinMultGen)();

typedef struct RingInfo{
	Sum sum;
	Mult mult;
	Zero zero;
	One one;
	Print print;
	Generate generate;
    LinMultGen lin_mult_gen;
}RingInfo;

void SetSum(RingInfo*, Sum);
void SetMult(RingInfo*, Mult);
void SetZero(RingInfo*, Zero);
void SetOne(RingInfo*, One);
void SetPrint(RingInfo*, Print);
void SetGenerate(RingInfo*, Generate);
void SetLinMultGen(RingInfo*, LinMultGen);

RingInfo* RingInfoCreate(Sum, Mult, Zero, One, Print, Generate, LinMultGen);
