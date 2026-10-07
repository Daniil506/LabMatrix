#include "pch.h"
#include "../LabMatrix/TVector.h"

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