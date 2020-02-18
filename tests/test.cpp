// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include "header.hpp"

TEST(stack, Text) {
    stack<int> test;
    int a = 2, b = 3, c = 4;

    test.push(a);
    test.push(b);
    test.push(c);
    test.push(12);
    test.push_emplace(15);

    EXPECT_EQ(std::is_move_assignable<stack<int>>::value, true);
    EXPECT_EQ(std::is_move_constructible<stack<int>>::value, true);

    EXPECT_EQ(test.head(), 15);
    EXPECT_EQ(test.pop(), 15);
    EXPECT_EQ(test.pop(), 12);
    EXPECT_EQ(test.pop(), 4);
    EXPECT_EQ(test.pop(), 3);
    EXPECT_EQ(test.pop(), 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
