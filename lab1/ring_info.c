#include <stdlib.h>
#include <stdio.h>

#include "ring_info.h"

void SetPrint(RingInfo* ring_info, Print print) {
    ring_info->print = print;
}

void SetGenerate(RingInfo* ring_info, Generate generate) {
    ring_info->generate = generate;
}
void SetSum(RingInfo* ring_info, Sum sum) {
    ring_info->sum = sum;
}

void SetMult(RingInfo* ring_info, Mult mult) {
    ring_info->mult = mult;
}

void SetZero(RingInfo* ring_info, Zero zero) {
    ring_info->zero = zero;
}

void SetOne(RingInfo* ring_info, One one) {
    ring_info->one = one;
}

void SetLinMultGen(RingInfo* ring_info, LinMultGen lin_mult_gen) {
    ring_info->lin_mult_gen = lin_mult_gen;
}

RingInfo* RingInfoCreate(Sum sum, Mult mult, Zero zero, One one, Print print,
                         Generate generate, LinMultGen lin_mult_gen) {
    struct RingInfo* ring_info = (RingInfo*)malloc(sizeof(struct RingInfo));
    SetSum(ring_info, sum);
    SetMult(ring_info, mult);
    SetZero(ring_info, zero);
    SetOne(ring_info, one);
    SetPrint(ring_info, print);
    SetGenerate(ring_info, generate);
    SetLinMultGen(ring_info, lin_mult_gen);
    return ring_info;
}