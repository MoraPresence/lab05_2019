// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <header.hpp>
#include <header-task2.hpp>

TEST(myStack, test_1){
    myStack<int> s{};
    for (size_t index = 1; index <= 10; ++index) {
        s.push(index);
    }
    EXPECT_EQ(s.head(), 10);
}

TEST(myStack,test_2 ){
    myStack<int> s{};

    s.push(3);
    s.push(12);
    s.push(45);

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
}

TEST(myStack, test_4)
{
    myStack<int> s{};

    my_stack.push(6);
    my_stack.push(9);
    my_stack.pop();

    EXPECT_EQ(s.head(), 6);
}

TEST(Stack, test_5){
		class A{
	public:
	A(int a, int b) {
		c = a + b;
	}
		int c;
	};
	
    stack<A> s{};

    s.push_emplace(4,6,2);
	auto a = s.head;
    EXPECT_EQ(a.c, 12);
}

TEST(Stack, test_6){
    stack<int> s{};

    my_stack.push(6);
    my_stack.push(9);
    my_stack.pop();

    EXPECT_EQ(s.head(), 6);
}