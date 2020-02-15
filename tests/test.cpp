// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include "header.hpp"
#include "header2.hpp"



TEST(stack, Text){
stack<int> test;
int a = 2, b = 3, c = 4;

test.push(a);
test.push(b);
test.push(c);
test.push(12);

EXPECT_EQ(std::is_move_assignable<stack<int>>::value, true);
EXPECT_EQ(std::is_move_constructible<stack<int>>::value, true);

EXPECT_EQ(test.head(), 12);
EXPECT_EQ(test.pop(), 12);
EXPECT_EQ(test.pop(), 4);
EXPECT_EQ(test.pop(), 3);
EXPECT_EQ(test.pop(), 2);
}

TEST(stack_t, Text){
    stack_st<int> test;
    test.push_emplace(1);
    test.push_emplace(3);
    test.push(2);
    test.push(3);
    test.push(4);
    test.push(12);

    EXPECT_EQ(std::is_move_assignable<stack_st<int>>::value, true);
    EXPECT_EQ(std::is_move_constructible<stack_st<int>>::value, true);

    EXPECT_EQ(test.head(), 12);
    EXPECT_EQ(test.pop(), 12);
    EXPECT_EQ(test.pop(), 4);
    EXPECT_EQ(test.pop(), 3);
    EXPECT_EQ(test.pop(), 2);
    EXPECT_EQ(test.pop(), 3);
    EXPECT_EQ(test.pop(), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
