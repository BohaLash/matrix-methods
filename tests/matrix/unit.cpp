#include <iostream>
#include <gtest/gtest.h>
#include ".././lib/matrix/matrix.cpp"

using namespace std;

TEST(MatrixInverseTest, Size2Matrix) {
    Matrix<> A(2);
    Matrix<> B(2);

    A[0][0] = 3; A[0][1] = 4;
    A[1][0] = 5; A[1][1] = 7;

    B[0][0] = 7; B[0][1] = -4;
    B[1][0] = -5; B[1][1] = 3;

    A.output(cout);
    B.output(cout);
    A.inverse().output(cout);

    EXPECT_TRUE(A.inverse() == B);
}

TEST(MatrixInverseTest, Size3Matrix) {
    Matrix<> A(3);
    Matrix<> B(3);

    A[0][0] = 2; A[0][1] = 5; A[0][2] = 7;
    A[1][0] = 6; A[1][1] = 3; A[1][2] = 4;
    A[2][0] = 5; A[2][1] = -2; A[2][2] = -3;

    B[0][0] = 1; B[0][1] = -1; B[0][2] = 1;
    B[1][0] = -38; B[1][1] = 41; B[1][2] = -34;
    B[2][0] = 27; B[2][1] = -29; B[2][2] = 24;

    A.output(cout);
    B.output(cout);
    A.inverse().output(cout);

    EXPECT_TRUE(A.inverse() == B);
}

TEST(MatrixInverseTest, Size4Matrix) {
    Matrix<> A(4);
    Matrix<> B(4);

    A[0][0] = 2; A[0][1] = 1; A[0][2] = 0; A[0][3] = 0;
    A[1][0] = 3; A[1][1] = 2; A[1][2] = 0; A[1][3] = 0;
    A[2][0] = 1; A[2][1] = 1; A[2][2] = 3; A[2][3] = 4;
    A[3][0] = 2; A[3][1] = -1; A[3][2] = 2; A[3][3] = 3;

    B[0][0] = 2; B[0][1] = -1; B[0][2] = 0; B[0][3] = 0;
    B[1][0] = -3; B[1][1] = 2; B[1][2] = 0; B[1][3] = 0;
    B[2][0] = 31; B[2][1] = -19; B[2][2] = 3; B[2][3] = -4;
    B[3][0] = -23; B[3][1] = 14; B[3][2] = -2; B[3][3] = 3;

    A.output(cout);
    B.output(cout);
    A.inverse().output(cout);

    EXPECT_TRUE(A.inverse() == B);
}
