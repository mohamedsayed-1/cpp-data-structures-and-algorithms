#pragma once
#include <cstddef>
#include <stdexcept>
#include <iostream>


namespace ds{
    template <class Type>
    class Stack{
        private:
            Type* items;
            size_t maxSize;
            size_t length;
        public:
            Stack(int size = 100);
            ~Stack();
            Stack(const Stack<Type>& other);
            Stack& operator = (const Stack<Type>& other);
            void push(const Type& item);
            Type pop();
            const Type& peek()const;
            bool isEmpty()const;
            bool isFull()const;
            void display()const;
            size_t size()const;
            size_t capacity()const;
            void clear();
    };
}

template <class Type>
ds::Stack<Type>::Stack(int size):length(0), maxSize(size <= 0 ? 100 : size){
    items = new Type[maxSize];
}

template <class Type>
ds::Stack<Type>::~Stack(){
    delete[] items;
}

template <class Type>
ds::Stack<Type>::Stack(const Stack<Type>& other){
    Type* newArr = new Type[other.maxSize];
    for (size_t i = 0; i < other.length; i++)
    {
        newArr[i] = other.items[i];
    }
    maxSize = other.maxSize;
    length = other.length;
    items = newArr;
}

template <class Type>
ds::Stack<Type>& ds::Stack<Type>::operator = (const Stack<Type>& other){
    if(this == &other) return *this;
    Type* newArr = new Type[other.maxSize];
    for (size_t i = 0; i < other.length; i++)
    {
        newArr[i] = other.items[i];
    }
    delete[] items;
    maxSize = other.maxSize;
    length = other.length;
    items = newArr;
    return *this;
}

template <class Type>
void ds::Stack<Type>::push(const Type& item){
    if(isFull()) throw std::runtime_error("Stack is full");
    items[length++] = item;
}

template <class Type>
Type ds::Stack<Type>::pop(){
    if(isEmpty()) throw std::underflow_error("Stack is empty");
    return items[--length];
}

template <class Type>
const Type& ds::Stack<Type>::peek()const{
    if(isEmpty()) throw std::underflow_error("Stack is empty");
    return items[length - 1];
}

template <class Type>
bool ds::Stack<Type>::isEmpty()const{
    return length == 0;
}

template <class Type>
bool ds::Stack<Type>::isFull()const{
    return length == maxSize;
}

template <class Type>
void ds::Stack<Type>::display()const{
    for (size_t i = length; i > 0; i--){
        std::cout << items[i - 1] << std::endl;
    }
}

template <class Type>
size_t ds::Stack<Type>::size()const{
    return length;
}

template <class Type>
void ds::Stack<Type>::clear(){
    length = 0;
}

template <class Type>
size_t ds::Stack<Type>::capacity() const{ 
    return maxSize; 
}