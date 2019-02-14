//
// Created by Borbáls on 2019. 02. 07..
//
#include "gtest/gtest.h"
#include "sum.h"
#include <vector>

class SummerTester : public ::testing::Test{
protected:
    void expectResult(int expected);

    Sum summer;
    std::vector<int> example;
};

void SummerTester::expectResult(int expected) {
    int result=summer.sum(example);
    ASSERT_EQ(result, 100);
}

TEST_F(SummerTester, blabla){
    example={4, 11, 32, 7};
    expectResult(true);
}