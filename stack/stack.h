#pragma once
#include <cstddef>


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