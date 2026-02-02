#pragma once
#include <cstddef>


namespace ds{
    template <class Type>
    class Queue{
        private:
            size_t length, front ,maxSize;
            Type* items;
        public:
            Queue(int size = 100);
            ~Queue();
            Queue(const Queue& other);
            Queue& operator =(const Queue& other);
            bool isEmpty() const;
            bool isFull() const;
            size_t size()const;
            size_t capacity()const;
    };
}

template<class Type>
ds::Queue<Type>::Queue(int size):length(0), front(0){
    if (size <= 0) maxSize = 100;
    else maxSize = size;
    items = new Type[maxSize];
}

template<class Type>
ds::Queue<Type>::~Queue(){
    delete[] items;
}

template<class Type>
ds::Queue<Type>::Queue(const Queue& other){
    Type* newQueue = new Type[other.maxSize];
    for (size_t i = 0; i < other.length; i++)
    {
        newQueue[i] = other.items[(other.front + i) % other.maxSize];
    }
    maxSize = other.maxSize;
    front = 0;
    length = other.length;
    items = newQueue;
}

template<class Type>
ds::Queue<Type>& ds::Queue<Type>::operator =(const ds::Queue<Type>& other){
    if(this == &other) return *this;
    Type* newQueue = new Type[other.maxSize];
    for (size_t i = 0; i < other.length; i++)
    {
        newQueue[i] = other.items[(other.front + i) % other.maxSize];
    }
    delete[] items;
    maxSize = other.maxSize;
    front = 0;
    length = other.length;
    items = newQueue;
    return *this;
}

template<class Type>
bool ds::Queue<Type>::isEmpty() const{
    return length == 0;
}

template<class Type>
bool ds::Queue<Type>::isFull() const{
    return length == maxSize;
}

template<class Type>
size_t ds::Queue<Type>::size()const{
    return length;
}

template<class Type>
size_t ds::Queue<Type>::capacity()const{
    return maxSize;
}