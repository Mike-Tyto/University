#include <stdio.h>
#include <assert.h>

#include "matrix.h"
#include "int.h"
#include "real.h"

int CompareReal(double f, double s) {
     return (f - s) > -0.001 && (f - s) < 0.001;
}

int IntMatrixCompare(Matrix* matrix1, Matrix* matrix2,
                     int height, int weight) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < weight; j++) {
            int value1 = GetInt((Int*)matrix1->lines[i][j]->value);
            int value2 = GetInt((Int*)matrix2->lines[i][j]->value);
            if (value1 != value2) {
                return 0;
            }
        }
    }
    return 1;
}

int RealMatrixCompare(Matrix* matrix1, Matrix* matrix2,
                     int height, int weight) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < weight; j++) {
            double value1 = GetReal((Real*)matrix1->lines[i][j]->value);
            double value2 = GetReal((Real*)matrix2->lines[i][j]->value);
            if (!CompareReal(value1, value2)) {
                return 0;
            }
        }
    }
    return 1;
}

void TestIntSum(Int* el) {
    Int* first_p = IntConstruct(2);
    Int* second_p = IntConstruct(3);
    Int* first_m = IntConstruct(-2);
    Int* second_m = IntConstruct(-3);

    void* sum_pp = el->ring_info->sum(first_p, second_p);
    int res_pp = GetInt(sum_pp);
    void* sum_mm = el->ring_info->sum(first_m, second_m);
    int res_mm = GetInt(sum_mm);
    void* sum_pm = el->ring_info->sum(first_p, first_m);
    int res_pm = GetInt(sum_pm);
    void* sum_mp = el->ring_info->sum(first_m, second_p);
    int res_mp = GetInt(sum_mp);

    assert(res_pp == 5);
    assert(res_mm == -5);
    assert(res_pm == 0);
    assert(res_mp == 1);
}

void TestIntMult(Int* el) {
    Int* first_p = IntConstruct(2);
    Int* second_p = IntConstruct(3);
    Int* first_m = IntConstruct(-2);
    Int* second_m = IntConstruct(-3);

    void* prod_pp = el->ring_info->mult(first_p, second_p);
    int res_pp = GetInt(prod_pp);
    void* prod_mm = el->ring_info->mult(first_m, second_m);
    int res_mm = GetInt(prod_mm);
    void* prod_pm = el->ring_info->mult(first_p, first_m);
    int res_pm = GetInt(prod_pm);
    void* prod_mp = el->ring_info->mult(first_m, second_p);
    int res_mp = GetInt(prod_mp);

    assert(res_pp == 6);
    assert(res_mm == 6);
    assert(res_pm == -4);
    assert(res_mp == -6);
}

void TestFloatSum(Real* el) {
    Real *first_p = RealConstruct(2.5);
    Real *second_p = RealConstruct(3.11);
    Real *first_m = RealConstruct(-2.5);
    Real *second_m = RealConstruct(-3.11);

    void *sum_pp = el->ring_info->sum(first_p, second_p);
    double res_pp = GetReal(sum_pp);
    void *sum_mm = el->ring_info->sum(first_m, second_m);
    double res_mm = GetReal(sum_mm);
    void *sum_pm = el->ring_info->sum(first_p, first_m);
    double res_pm = GetReal(sum_pm);
    void *sum_mp = el->ring_info->sum(first_m, second_p);
    double res_mp = GetReal(sum_mp);

    assert(CompareReal(res_pp, 5.61));
    assert(CompareReal(res_mm, -5.61));
    assert(CompareReal(res_pm, 0));
    assert(CompareReal(res_mp, 0.61));
}

void TestFloatMult(Real* el) {
    Real *first_p = RealConstruct(2.5);
    Real *second_p = RealConstruct(3.11);
    Real *first_m = RealConstruct(-2.5);
    Real *second_m = RealConstruct(-3.11);

    void *prod_pp = el->ring_info->mult(first_p, second_p);
    double res_pp = GetReal(prod_pp);
    void *prod_mm = el->ring_info->mult(first_m, second_m);
    double res_mm = GetReal(prod_mm);
    void *prod_pm = el->ring_info->mult(first_p, first_m);
    double res_pm = GetReal(prod_pm);
    void *prod_mp = el->ring_info->mult(first_m, second_p);
    double res_mp = GetReal(prod_mp);

    assert(CompareReal(res_pp ,7.775));
    assert(CompareReal(res_mm ,7.775));
    assert(CompareReal(res_pm ,-6.25));
    assert(CompareReal(res_mp ,-7.775));
}

void TestIntMatrixSum(Int* el) {
    Matrix* matrix1 = MatrixConstruct(2, 3);
    Matrix* matrix2 = MatrixConstruct(2, 3);
    Matrix* matrix_sum = MatrixConstruct(2, 3);

    matrix1->lines[0][0] = ElementConstruct(el->ring_info, IntConstruct(2));
    matrix1->lines[0][1] = ElementConstruct(el->ring_info, IntConstruct(0));
    matrix1->lines[0][2] = ElementConstruct(el->ring_info, IntConstruct(-1));
    matrix1->lines[1][0] = ElementConstruct(el->ring_info, IntConstruct(10));
    matrix1->lines[1][1] = ElementConstruct(el->ring_info, IntConstruct(-4));
    matrix1->lines[1][2] = ElementConstruct(el->ring_info, IntConstruct(0));

    matrix2->lines[0][0] = ElementConstruct(el->ring_info, IntConstruct(-1));
    matrix2->lines[0][1] = ElementConstruct(el->ring_info, IntConstruct(2));
    matrix2->lines[0][2] = ElementConstruct(el->ring_info, IntConstruct(3));
    matrix2->lines[1][0] = ElementConstruct(el->ring_info, IntConstruct(-10));
    matrix2->lines[1][1] = ElementConstruct(el->ring_info, IntConstruct(3));
    matrix2->lines[1][2] = ElementConstruct(el->ring_info, IntConstruct(-9));

    matrix_sum->lines[0][0] = ElementConstruct(el->ring_info, IntConstruct(1));
    matrix_sum->lines[0][1] = ElementConstruct(el->ring_info, IntConstruct(2));
    matrix_sum->lines[0][2] = ElementConstruct(el->ring_info, IntConstruct(2));
    matrix_sum->lines[1][0] = ElementConstruct(el->ring_info, IntConstruct(0));
    matrix_sum->lines[1][1] = ElementConstruct(el->ring_info, IntConstruct(-1));
    matrix_sum->lines[1][2] = ElementConstruct(el->ring_info, IntConstruct(-9));

    Matrix* matrix_res = MatrixSum(matrix1, matrix2);

    assert(IntMatrixCompare(matrix_sum, matrix_res, 2, 3));
}

void TestIntMatrixProd(Int* el) {
    Matrix* matrix1 = MatrixConstruct(2, 2);
    Matrix* matrix2 = MatrixConstruct(2, 1);
    Matrix* matrix_prod = MatrixConstruct(2, 1);

    matrix1->lines[0][0] = ElementConstruct(el->ring_info, IntConstruct(2));
    matrix1->lines[0][1] = ElementConstruct(el->ring_info, IntConstruct(0));
    matrix1->lines[1][0] = ElementConstruct(el->ring_info, IntConstruct(10));
    matrix1->lines[1][1] = ElementConstruct(el->ring_info, IntConstruct(-4));

    matrix2->lines[0][0] = ElementConstruct(el->ring_info, IntConstruct(-1));
    matrix2->lines[1][0] = ElementConstruct(el->ring_info, IntConstruct(2));

    matrix_prod->lines[0][0] = ElementConstruct(el->ring_info, IntConstruct(-2));
    matrix_prod->lines[1][0] = ElementConstruct(el->ring_info, IntConstruct(-18));

    Matrix* matrix_res = MatrixProduct(matrix1, matrix2);

    assert(IntMatrixCompare(matrix_prod, matrix_res, 2, 1));
}

void TestIntMatrixTransp(Int* el) {
    Matrix* matrix1 = MatrixConstruct(2, 3);
    Matrix* matrix_transp = MatrixConstruct(3, 2);

    matrix1->lines[0][0] = ElementConstruct(el->ring_info, IntConstruct(2));
    matrix1->lines[0][1] = ElementConstruct(el->ring_info, IntConstruct(0));
    matrix1->lines[0][2] = ElementConstruct(el->ring_info, IntConstruct(-1));
    matrix1->lines[1][0] = ElementConstruct(el->ring_info, IntConstruct(10));
    matrix1->lines[1][1] = ElementConstruct(el->ring_info, IntConstruct(-4));
    matrix1->lines[1][2] = ElementConstruct(el->ring_info, IntConstruct(0));

    matrix_transp->lines[0][0] = ElementConstruct(el->ring_info, IntConstruct(2));
    matrix_transp->lines[0][1] = ElementConstruct(el->ring_info, IntConstruct(10));
    matrix_transp->lines[1][0] = ElementConstruct(el->ring_info, IntConstruct(0));
    matrix_transp->lines[1][1] = ElementConstruct(el->ring_info, IntConstruct(-4));
    matrix_transp->lines[2][0] = ElementConstruct(el->ring_info, IntConstruct(-1));
    matrix_transp->lines[2][1] = ElementConstruct(el->ring_info, IntConstruct(0));

    Matrix* matrix_res = MatrixTransposition(matrix1);

    assert(IntMatrixCompare(matrix_transp, matrix_res, 3, 2));
}

void TestRealMatrixSum(Real* el) {
    Matrix* matrix1 = MatrixConstruct(2, 3);
    Matrix* matrix2 = MatrixConstruct(2, 3);
    Matrix* matrix_sum = MatrixConstruct(2, 3);

    matrix1->lines[0][0] = ElementConstruct(el->ring_info, RealConstruct(2.5));
    matrix1->lines[0][1] = ElementConstruct(el->ring_info, RealConstruct(0.12));
    matrix1->lines[0][2] = ElementConstruct(el->ring_info, RealConstruct(-1.56));
    matrix1->lines[1][0] = ElementConstruct(el->ring_info, RealConstruct(10.31));
    matrix1->lines[1][1] = ElementConstruct(el->ring_info, RealConstruct(-4.29));
    matrix1->lines[1][2] = ElementConstruct(el->ring_info, RealConstruct(-0.6));

    matrix2->lines[0][0] = ElementConstruct(el->ring_info, RealConstruct(-1.09));
    matrix2->lines[0][1] = ElementConstruct(el->ring_info, RealConstruct(2.8));
    matrix2->lines[0][2] = ElementConstruct(el->ring_info, RealConstruct(3.0));
    matrix2->lines[1][0] = ElementConstruct(el->ring_info, RealConstruct(-10.91));
    matrix2->lines[1][1] = ElementConstruct(el->ring_info, RealConstruct(3.5));
    matrix2->lines[1][2] = ElementConstruct(el->ring_info, RealConstruct(-9.99));

    matrix_sum->lines[0][0] = ElementConstruct(el->ring_info, RealConstruct(1.41));
    matrix_sum->lines[0][1] = ElementConstruct(el->ring_info, RealConstruct(2.92));
    matrix_sum->lines[0][2] = ElementConstruct(el->ring_info, RealConstruct(1.44));
    matrix_sum->lines[1][0] = ElementConstruct(el->ring_info, RealConstruct(-0.6));
    matrix_sum->lines[1][1] = ElementConstruct(el->ring_info, RealConstruct(-0.79));
    matrix_sum->lines[1][2] = ElementConstruct(el->ring_info, RealConstruct(-10.59));

    Matrix* matrix_res = MatrixSum(matrix1, matrix2);

    assert(RealMatrixCompare(matrix_sum, matrix_res, 2, 3));
}

void TestRealMatrixProd(Real* el) {
    Matrix* matrix1 = MatrixConstruct(2, 2);
    Matrix* matrix2 = MatrixConstruct(2, 1);
    Matrix* matrix_prod = MatrixConstruct(2, 1);

    matrix1->lines[0][0] = ElementConstruct(el->ring_info, RealConstruct(2.5));
    matrix1->lines[0][1] = ElementConstruct(el->ring_info, RealConstruct(0.1));
    matrix1->lines[1][0] = ElementConstruct(el->ring_info, RealConstruct(-10.01));
    matrix1->lines[1][1] = ElementConstruct(el->ring_info, RealConstruct(-0.99));

    matrix2->lines[0][0] = ElementConstruct(el->ring_info, RealConstruct(-1.54));
    matrix2->lines[1][0] = ElementConstruct(el->ring_info, RealConstruct(2.09));

    matrix_prod->lines[0][0] = ElementConstruct(el->ring_info, RealConstruct(-3.641));
    matrix_prod->lines[1][0] = ElementConstruct(el->ring_info, RealConstruct(13.346));

    Matrix* matrix_res = MatrixProduct(matrix1, matrix2);

    assert(RealMatrixCompare(matrix_prod, matrix_res, 2, 1));
}

void TestRealMatrixTransp(Int* el) {
    Matrix* matrix1 = MatrixConstruct(2, 3);
    Matrix* matrix_transp = MatrixConstruct(3, 2);

    matrix1->lines[0][0] = ElementConstruct(el->ring_info, RealConstruct(2.5));
    matrix1->lines[0][1] = ElementConstruct(el->ring_info, RealConstruct(0.89));
    matrix1->lines[0][2] = ElementConstruct(el->ring_info, RealConstruct(-1.01));
    matrix1->lines[1][0] = ElementConstruct(el->ring_info, RealConstruct(10.7));
    matrix1->lines[1][1] = ElementConstruct(el->ring_info, RealConstruct(-4.5));
    matrix1->lines[1][2] = ElementConstruct(el->ring_info, RealConstruct(-0.51));

    matrix_transp->lines[0][0] = ElementConstruct(el->ring_info, RealConstruct(2.5));
    matrix_transp->lines[0][1] = ElementConstruct(el->ring_info, RealConstruct(10.07));
    matrix_transp->lines[1][0] = ElementConstruct(el->ring_info, RealConstruct(0.89));
    matrix_transp->lines[1][1] = ElementConstruct(el->ring_info, RealConstruct(-4.5));
    matrix_transp->lines[2][0] = ElementConstruct(el->ring_info, RealConstruct(-1.01));
    matrix_transp->lines[2][1] = ElementConstruct(el->ring_info, RealConstruct(-0.51));

    Matrix* matrix_res = MatrixTransposition(matrix1);

    assert(RealMatrixCompare(matrix_transp, matrix_res, 3, 2));
}

int main() {
    Int* int_el = IntConstruct(1);

    TestIntSum(int_el);
    printf("Sum of integer numbers works properly!\n");
    TestIntMult(int_el);
    printf("Multiplication of integer numbers works properly!\n");

    Real* real_el = RealConstruct(1.0);

    TestFloatSum(real_el);
    printf("Sum of real numbers works properly!\n");
    TestFloatMult(real_el);
    printf("Multiplication of real numbers works properly!\n");

    TestIntMatrixSum(int_el);
    printf("Sum of integer matrices works properly!\n");
    TestIntMatrixProd(int_el);
    printf("Multiplication of integer matrices works properly!\n");
    TestIntMatrixTransp(int_el);
    printf("Transposition of integer matrix works properly!\n");

    TestRealMatrixSum(real_el);
    printf("Sum of real-elements matrices works properly!\n");
    TestRealMatrixProd(real_el);
    printf("Multiplication of real-elements matrices works properly!\n");
    TestIntMatrixTransp(int_el);
    printf("Transposition of real-elements matrix works properly!\n");

    printf("All tests were passed successfully!\n");

    return 0;
}