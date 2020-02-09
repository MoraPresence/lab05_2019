// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include <cstdio>

#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102

template <typename T>
class stackOBJ{
public:
    T data;
    stackOBJ *next_stackOBJ;
};


template <typename T>
class stack
{
public:
    stack<T> () = default;
    explicit stack(size_t countStack) : _countStack(countStack) {}

    ~stack(){
        while(top){
            auto* tmp = top;
            top = top->next_stackOBJ;
            delete tmp;
        }
    }

    void push(T&& value);
    void push(const T& value);
    void pop();
    const T& head() const;

private:
    stackOBJ<T> *top = NULL;
    size_t _countStack = 10;
};
#endif // INCLUDE_HEADER_HPP_
