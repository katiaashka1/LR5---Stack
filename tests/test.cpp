// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include "header.hpp"
#include "header2.hpp"

class summ{
public:
    summ();
    summ(int a, int b, int c)
    {
        rez = a+b+c;
    }
    int rez;
};

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
    stack_st<summ> test_summ;
    stack_st<int> test;
    test_summ.push_emplace(1);
    test_summ.push_emplace(3);
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
    EXPECT_EQ(test_summ.pop().rez, 12);
    EXPECT_EQ(test_summ.pop().rez, 6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
