// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include <cstdio>
#include <iostream>

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
class myStack
{
public:
    myStack<T> () = default;
    explicit myStack(size_t countStack) : _countStack(countStack) {}

    ~myStack(){
        while (top){
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

template<typename T>
const T &myStack<T>::head() const {
    return top->data;
}


template<typename T>
void myStack<T>::push(const T &value) {
    if (_countStack) {
        stackOBJ<T> *node = new stackOBJ<T>{std::move(value), top};
        top = node;
        --_countStack;
    } else {
        exit(STACK_OVERFLOW);
    }
}

template<typename T>
void myStack<T>::pop() {
   // T value;
    if (top) {
        stackOBJ<T> *old = top;
        top = top->next_stackOBJ;
      //  value = old->data;
        delete old;
    } else {
        exit(STACK_UNDERFLOW);
    }
	//return value;
}


template<typename T>
void myStack<T>::push(T &&value) {
    if (_countStack) {
        stackOBJ<T> *node = new stackOBJ<T>{std::move(value), top};
        top = node;
        --_countStack;
    } else {
        exit(STACK_OVERFLOW);
    }
}
#endif // INCLUDE_HEADER_HPP_
