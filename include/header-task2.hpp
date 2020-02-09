// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include <cstdio>

#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102

template<typename T>
class stackOBJ {
public:
    T data;
    stackOBJ *next_stackOBJ;
};


template<typename T>
class stack {
public:
    stack() = default;
    explicit stack(size_t countStack) : _countStack(countStack) {}

    ~stack(){
        while(top){
            auto* tmp = top;
            top = top->next_stackOBJ;
            delete tmp;
        }
    }

    template<typename ... Args>
    void push_emplace(Args &&... value);

    void push(T &&value);

    const T &head() const;

    T pop();

private:
    stackOBJ<T> *top = NULL;
    size_t _countStack = 10;
};
#endif // INCLUDE_HEADER_HPP_
