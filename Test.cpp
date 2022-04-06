#include "doctest.h"
#include "Matrix.hpp"
#include <vector>
#include <stdlib.h>
using namespace zich;


void RandomVector(std::vector<double> &vec,int size){
for (size_t i = 0; i < size; i++)
{
   vec.push_back(rand() % 100 + 1);
}
}

TEST_CASE ("row*col NOT equal Throw test") {
    std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    std::vector<double> identity = {1, 0, 0, 1};
    Matrix a{arr, 3, 3};
    Matrix b{identity, 2, 2};   
    CHECK_THROWS(a + b);
    CHECK_THROWS(b + a);
    CHECK_THROWS(a - b);
    CHECK_THROWS(b - a);
    CHECK_THROWS(b * a);
    CHECK_THROWS(a * b);
}


TEST_CASE ("Compare and multiply matrices with different dimensions") {
    std::vector<double> vec1;
    std::vector<double> vec2;
    for (unsigned long i = 0; i < 15; i++) {
        RandomVector(vec1,10);
        RandomVector(vec2,6);
        Matrix mat1(vec1, 2, 5);
        Matrix mat2(vec2, 3 , 2);
        CHECK_THROWS(if (mat1 > mat2));
        CHECK_THROWS(if (mat1 < mat2));
        CHECK_THROWS(if (mat1 <= mat2));
        CHECK_THROWS(if (mat1 >= mat2));
        CHECK_THROWS(mat1 * mat2);
        CHECK_THROWS(mat2 * mat1);
        CHECK_THROWS(mat2 *= mat1);
        CHECK_THROWS(mat1 *= mat2);

    }
}

TEST_CASE ("good input - multiplication subtract and Addition between 2 matrices with same dimensions") {
    std::vector<double> vec1,vec2;
    for (unsigned long i = 2; i < 28; i+=2) {
        RandomVector(vec1,i);
        RandomVector(vec2,i);
        Matrix mat1(vec1, i, 1);
        Matrix mat2(vec2, i, 1);
        CHECK_NOTHROW(mat1 * mat2);
        CHECK_NOTHROW(mat2 * mat1);
        CHECK_NOTHROW(mat1 + mat2);
        CHECK_NOTHROW(mat1 - mat2);
    }
}

TEST_CASE ("negetive row and col or zero") {
    std::vector<double> vec={5,43,3,5,6,7,7,8,8,9};
            CHECK_THROWS(Matrix(vec, -20, -40));
            CHECK_THROWS(Matrix(vec, -22, -44));
            CHECK_THROWS(Matrix(vec, -2, -2));
            CHECK_THROWS(Matrix(vec, -80, -150));
            CHECK_THROWS(Matrix(vec, -9 ,-6));
            CHECK_THROWS(Matrix(vec, 0, -47));
            CHECK_THROWS(Matrix(vec, -61, -54));
            CHECK_THROWS(Matrix(vec, 0, -6));
            CHECK_THROWS(Matrix(vec, 44, 0));
            CHECK_THROWS(Matrix(vec, 0, 1));
            CHECK_THROWS(Matrix(vec, 6, 0));
            CHECK_THROWS(Matrix(vec, 0, 0));
}