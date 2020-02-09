// Copyright 2018 Your Name <your_email>

#include <header.hpp>
#include <iostream>

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
    T value;
    if (top) {
        stackOBJ<T> *old = top;
        top = top->next_stackOBJ;
        value = old->data;
        delete old;
    } else {
        exit(STACK_UNDERFLOW);
    }
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
