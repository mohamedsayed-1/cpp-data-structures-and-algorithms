#pragma once
#include <iostream>

namespace ds{
template <class Type>
class Array{
    private:
        size_t length, maxSize;
        Type* elements;
    public:
        Array(int size = 100);
        Array& operator=(const Array& other);
        Array(const Array& other);
        ~Array();
        bool isFull()const;
        bool isEmpty()const;
        size_t capacity()const;
        size_t size()const;
};
}


template <class Type>
ds::Array<Type>::Array(int size): length(0){
    if (size <= 0) maxSize = 100;
    else maxSize = size;
    elements = new Type[maxSize];
}

template <class Type>
ds::Array<Type>& ds::Array<Type>::operator=(const ds::Array<Type>& other){
    if(this == &other) return *this;
    Type* newArr = new Type[other.maxSize];
    for (size_t i = 0; i < other.length; i++)
    {
        newArr[i] = other.elements[i];
    }
    delete[] elements;
    elements = newArr;
    maxSize = other.maxSize;
    length = other.length;
    return *this;
}

template <class Type>
ds::Array<Type>::Array(const Array& other){
    Type* newArr = new Type[other.maxSize];
    for (size_t i = 0; i < other.length; i++)
    {
        newArr[i] = other.elements[i];
    }
    elements = newArr;
    maxSize = other.maxSize;
    length = other.length;
}

template <class Type>
ds::Array<Type>::~Array(){
    delete[] elements;
}

template <class Type>
bool ds::Array<Type>::isFull()const{
    return length >= maxSize;
}

template <class Type>
bool ds::Array<Type>::isEmpty()const{
    return length == 0;
}

template <class Type>
size_t ds::Array<Type>::capacity()const{
    return maxSize;
}

template <class Type>
size_t ds::Array<Type>::size()const{
    return length;
}
