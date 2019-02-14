//
// Created by Borbáls on 2019. 02. 07..
//

#include "apple.h"
#include "gtest/gtest.h"
#include <string>

class AppleTest : public ::testing::Test{
protected:
    void expectResult(bool expected);
    std::string apple;
    Apple app;
};

void AppleTest::expectResult(bool expected) {
    std::string result = app.getApple();
    ASSERT_EQ(result, "apple");
}

TEST_F(AppleTest, TestApple){
    expectResult(true);
}