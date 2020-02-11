// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <header.hpp>

TEST(myStack, test_1){
    myStack<int> s{};
    for (size_t index = 1; index <= 10; ++index) {
        s.push(index);
    }
    EXPECT_EQ(std::is_move_constructible<myStack<int>>::value, true);
    EXPECT_EQ(std::is_move_assignable<myStack<int>>::value, true);
    EXPECT_EQ(s.head(), 10);
}

TEST(myStack, test_2 ){
    myStack<int> s{};

    s.push(3);
    s.push(12);
    s.push(45);
    EXPECT_EQ(std::is_move_constructible<myStack<int>>::value, true);
    EXPECT_EQ(std::is_move_assignable<myStack<int>>::value, true);
    EXPECT_EQ(s.head(), 45);
}

TEST(myStack, test_3)
{
    myStack<int> s{};

    s.push(3);
    EXPECT_EQ(s.head(), 3);
    s.push(5);
    EXPECT_EQ(s.head(), 5);
    s.push(10);
    EXPECT_EQ(s.head(), 10);
    EXPECT_EQ(std::is_move_constructible<myStack<int>>::value, true);
    EXPECT_EQ(std::is_move_assignable<myStack<int>>::value, true);
}

TEST(myStack, test_4)
{
    myStack<int> s{};

    s.push(6);
    s.push(9);
    s.pop();
    EXPECT_EQ(std::is_move_constructible<myStack<int>>::value, true);
    EXPECT_EQ(std::is_move_assignable<myStack<int>>::value, true);
    EXPECT_EQ(s.head(), 6);
}
