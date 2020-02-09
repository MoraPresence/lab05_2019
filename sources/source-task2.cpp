// Copyright 2018 Your Name <your_email>
#include <header-task2.hpp>
#include <iostream>


template<typename T>
const T &stack<T>::head() const {
    return top->data;
}

template<typename T>
template<typename ... Args>
void stack<T>::push_emplace(Args &&... value) {
    push(T(value...));
}

template<typename T>
T stack<T>::pop() {
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
void stack<T>::push(T &&value) {
    if(_countStack) {
        stackOBJ<T> *node = new stackOBJ<T>;
        node->data = value;
        node->next_stackOBJ = top;
        top = node;
        --_countStack;
    }else{
        exit(STACK_OVERFLOW);
    }
}
