#include "pch.h"
#include "../TVector.h"
#include "../TMathVector.h"
#include "../TMatrix.h"
TEST(TVectorTest, Size)
{
    TVector<int> vector(5);

    EXPECT_EQ(vector.size(), 5);
}

TEST(TVectorTest, Capacity)
{
    TVector<int> vector(5);

    EXPECT_EQ(vector.capacity(), 5);
}

TEST(TVectorTest, Index)
{
    TVector<int> vector(3);

    vector[0] = 10;
    vector[1] = 20;
    vector[2] = 30;

    EXPECT_EQ(vector[0], 10);
    EXPECT_EQ(vector[1], 20);
    EXPECT_EQ(vector[2], 30);
}

TEST(TVectorTest, Reserve)
{
    TVector<int> vector(5);

    vector.reserve(10);

    EXPECT_EQ(vector.size(), 5);
    EXPECT_EQ(vector.capacity(), 10);
}

TEST(TVectorTest, ShrinkToFit)
{
    TVector<int> vector(5);

    vector.reserve(10);
    vector.shrink_to_fit();

    EXPECT_EQ(vector.size(), 5);
    EXPECT_EQ(vector.capacity(), 5);
}
TEST(TVectorTest, Iterator)
{
    TVector<int> vector(3);

    vector[0] = 10;
    vector[1] = 20;
    vector[2] = 30;

    auto it = vector.begin();

    EXPECT_EQ(*it, 10);

    ++it;
    EXPECT_EQ(*it, 20);

    it++;
    EXPECT_EQ(*it, 30);
}

TEST(TVectorTest, IteratorDecrement)
{
    TVector<int> vector(3);

    vector[0] = 10;
    vector[1] = 20;
    vector[2] = 30;

    auto it = vector.end();

    --it;
    EXPECT_EQ(*it, 30);

    it--;
    EXPECT_EQ(*it, 20);
}

TEST(TVectorTest, IteratorArithmetic)
{
    TVector<int> vector(5);

    vector[0] = 10;
    vector[1] = 20;
    vector[2] = 30;
    vector[3] = 40;
    vector[4] = 50;

    auto it = vector.begin();

    EXPECT_EQ(*(it + 2), 30);

    it += 3;
    EXPECT_EQ(*it, 40);

    it -= 2;
    EXPECT_EQ(*it, 20);

    EXPECT_EQ(*(it - 1), 10);
}

TEST(TVectorTest, IteratorComparison)
{
    TVector<int> vector(3);

    auto first = vector.begin();
    auto second = vector.begin();

    EXPECT_TRUE(first == second);

    ++second;

    EXPECT_TRUE(first != second);
}

TEST(TVectorTest, ConstIterator)
{
    TVector<int> vector(3);

    vector[0] = 10;
    vector[1] = 20;
    vector[2] = 30;

    const TVector<int>& const_vector = vector;

    auto it = const_vector.begin();

    EXPECT_EQ(*it, 10);

    ++it;

    EXPECT_EQ(*it, 20);
}
TEST(TMathVectorTest, Addition)
{
    TMathVector<int> a(3);
    TMathVector<int> b(3);

    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    b[0] = 4;
    b[1] = 5;
    b[2] = 6;

    TMathVector<int> result = a + b;

    EXPECT_EQ(result[0], 5);
    EXPECT_EQ(result[1], 7);
    EXPECT_EQ(result[2], 9);
}

TEST(TMathVectorTest, Subtraction)
{
    TMathVector<int> a(3);
    TMathVector<int> b(3);

    a[0] = 5;
    a[1] = 7;
    a[2] = 9;

    b[0] = 1;
    b[1] = 2;
    b[2] = 3;

    TMathVector<int> result = a - b;

    EXPECT_EQ(result[0], 4);
    EXPECT_EQ(result[1], 5);
    EXPECT_EQ(result[2], 6);
}

TEST(TMathVectorTest, MultiplicationByNumber)
{
    TMathVector<int> vector(3);

    vector[0] = 1;
    vector[1] = 2;
    vector[2] = 3;

    TMathVector<int> result = vector * 5;

    EXPECT_EQ(result[0], 5);
    EXPECT_EQ(result[1], 10);
    EXPECT_EQ(result[2], 15);
}

TEST(TMathVectorTest, ScalarProduct)
{
    TMathVector<int> a(3);
    TMathVector<int> b(3);

    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    b[0] = 4;
    b[1] = 5;
    b[2] = 6;

    EXPECT_EQ(a * b, 32);
}

TEST(TMathVectorTest, Equality)
{
    TMathVector<int> a(3);
    TMathVector<int> b(3);

    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    b[0] = 1;
    b[1] = 2;
    b[2] = 3;

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a != b);
}
TEST(TMatrixTest, Size)
{
    TMatrix<int> matrix(2, 3);

    EXPECT_EQ(matrix.rows(), 2);
    EXPECT_EQ(matrix.columns(), 3);
}

TEST(TMatrixTest, Index)
{
    TMatrix<int> matrix(2, 3);

    matrix[0][0] = 10;
    matrix[0][1] = 20;
    matrix[0][2] = 30;

    matrix[1][0] = 40;
    matrix[1][1] = 50;
    matrix[1][2] = 60;

    EXPECT_EQ(matrix[0][0], 10);
    EXPECT_EQ(matrix[0][1], 20);
    EXPECT_EQ(matrix[0][2], 30);

    EXPECT_EQ(matrix[1][0], 40);
    EXPECT_EQ(matrix[1][1], 50);
    EXPECT_EQ(matrix[1][2], 60);
}

TEST(TMatrixTest, InheritedVectorOperations)
{
    TMatrix<int> matrix(2, 3);

    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;

    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;

    EXPECT_EQ(matrix.size(), 2);
    EXPECT_EQ(matrix[0][1], 2);
    EXPECT_EQ(matrix[1][2], 6);
}