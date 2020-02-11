// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <header2.hpp>

TEST(Stack, test_5){
        class A{
    public:
    A(int a, int b) {
        c = a + b;
    }
        int c;
    };
    myStack<A> s{};

    s.push_emplace(4, 6, 2);
    auto a = s.head;
    EXPECT_EQ(a.c, 12);
}

TEST(Stack, test_6){
    myStack<int> s{};

    s.push(6);
    s.push(9);
    s.pop();

    EXPECT_EQ(s.head(), 6);
}
