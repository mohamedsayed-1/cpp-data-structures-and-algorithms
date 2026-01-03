#pragma once
#include <iostream>
#include <stdexcept>

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
        Type at(int index)const;
        void display()const;
        void append(const Type& element);
        void insert(size_t index,const Type& newItem);
        // search the array for a given value, and return its index if found and -1 if not found
        int search(const Type& key)const;
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

template <class Type>
Type ds::Array<Type>::at(int index)const{
    if (index < 0 || index >= length) throw std::out_of_range("invalid index");
    return elements[index];
}

template <class Type>
void ds::Array<Type>::display()const{
    for (size_t i = 0; i < length; i++)
    {
        if (!(i % 10) && i != 0) std::cout << std::endl;
        std::cout << elements[i] << "  ";
    }
    std::cout << std::endl;
}

template <class Type>
void ds::Array<Type>::append(const Type& element){
    if (isFull()) throw std::runtime_error("array is full");
    elements[length] = element;
    length++;
}

template <class Type>
void ds::Array<Type>::insert(size_t index, const Type& newItem){
    if (index > length) throw std::out_of_range ("invalid index");
    if (isFull()) throw std::runtime_error("array is full");
    for (size_t i = length; i > index; i--)
    {
        elements[i] = elements[i - 1];
    }
    elements[index] = newItem;
    length++;
}

template <class Type>
int ds::Array<Type>::search(const Type& key)const{
    for (size_t i = 0; i < length; i++)
    {
        if(elements[i] == key) return i;
    }
    return -1;
}