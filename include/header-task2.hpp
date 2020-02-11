// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_TASK2_HPP_
#define INCLUDE_HEADER_TASK2_HPP_
#include <cstdio>
#include <iostream>

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
class myStack {
public:
    myStack() = default;
    explicit myStack(size_t countStack) : _countStack(countStack) {}

    ~myStack(){
        while (top){
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

template<typename T>
const T &myStack<T>::head() const {
    return top->data;
}

template<typename T>
template<typename ... Args>
void myStack<T>::push_emplace(Args &&... value) {
    push(T(std::move(value...)));
}

template<typename T>
T myStack<T>::pop() {
    T value;
    if (top) {
        stackOBJ<T> *old = top;
        top = top->next_stackOBJ;
        value = old->data;
        delete old;
        ++_countStack;
    } else {
        exit(STACK_UNDERFLOW);
    }
    return value;
}


template<typename T>
void myStack<T>::push(T &&value) {
    if (_countStack) {
        stackOBJ<T> *node = new stackOBJ<T>{std::move(value), top};
        top = node;
        --_countStack;
    }else{
        exit(STACK_OVERFLOW);
    }
}
#endif // INCLUDE_HEADER_TASK2_HPP_
