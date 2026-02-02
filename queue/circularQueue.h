#pragma once
#include <cstddef>
#include <iostream>
#include <stdexcept>


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
            void enqueue(const Type& item);            
            Type dequeue();
            const Type& getFront() const;
            void display()const;
            int search(const Type& item)const;
            void clear();
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

template<class Type>
void ds::Queue<Type>::enqueue(const Type& newItem){
    if(isFull()) throw std::overflow_error("Queue is full");
    items[(front+length) % maxSize] = newItem;
    length++;
}            

template<class Type>
Type ds::Queue<Type>::dequeue(){
    if(isEmpty()) throw std::underflow_error("Can't dequeue: Queue is empty");
    Type item = items[front]; 
    front = (front + 1) % maxSize;
    length--;
    return item;
}

template<class Type>
const Type& ds::Queue<Type>::getFront() const{
    if(isEmpty()) throw std::runtime_error("Queue is empty");
    return items[front];
}

template<class Type>
void ds::Queue<Type>::display()const{
    for (size_t i = 0; i < length; i++)
    {
        std::cout << items[(front + i) % maxSize] << " ";
    }
    std::cout <<std::endl;
}

template<class Type>
int ds::Queue<Type>::search(const Type& item)const{
    for (size_t i = 0; i < length; i++)
    {
        if(items[(front + i) % maxSize] == item) return i;  
    }
    return -1;
}

template<class Type>
void ds::Queue<Type>::clear(){
    length = front = 0;
}