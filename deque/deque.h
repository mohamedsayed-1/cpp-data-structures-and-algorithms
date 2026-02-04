#pragma once
#include <cstddef>
#include <iostream>
#include <stdexcept>


namespace ds{
    template <class Type>
    class Deque{
        private:
            size_t length, front ,maxSize;
            Type* items;
        public:
            Deque(int size = 100);
            ~Deque();
            Deque(const Deque& other);
            Deque& operator =(const Deque& other);
            bool isEmpty() const;
            bool isFull() const;
            size_t size()const;
            size_t capacity()const;
            const Type& getFront() const;
            const Type& getBack() const;
            void insertFront(const Type& item);            
            void insertBack(const Type& item);            
            Type deleteFront();
            Type deleteBack();
            void display()const;
            int search(const Type& item)const;
            void clear();
    };
}


template<class Type>
ds::Deque<Type>::Deque(int size):maxSize(size <= 0 ? 100 : size), length(0), front(0){
    items = new Type[maxSize];
}

template<class Type>
ds::Deque<Type>::~Deque(){
    delete[] items;
}

template<class Type>
ds::Deque<Type>::Deque(const Deque& other){
    Type* newDeque = new Type[other.maxSize];
    for (size_t i = 0; i < other.length; i++)
    {
        newDeque[i] = other.items[(other.front + i) % other.maxSize];
    }
    maxSize = other.maxSize;
    front = 0;
    length = other.length;
    items = newDeque;
}

template<class Type>
ds::Deque<Type>& ds::Deque<Type>::operator=(const ds::Deque<Type>& other){
    if(this == &other) return *this;
    Type* newDeque = new Type[other.maxSize];
    for (size_t i = 0; i < other.length; i++)
    {
        newDeque[i] = other.items[(other.front + i) % other.maxSize];
    }
    delete[] items;
    maxSize = other.maxSize;
    front = 0;
    length = other.length;
    items = newDeque;
    return *this;
}

template<class Type>
bool ds::Deque<Type>::isEmpty() const{
    return length == 0;
}

template<class Type>
bool ds::Deque<Type>::isFull() const{
    return length == maxSize;
}

template<class Type>
size_t ds::Deque<Type>::size()const{
    return length;
}

template<class Type>
size_t ds::Deque<Type>::capacity()const{
    return maxSize;
}

template<class Type>
const Type& ds::Deque<Type>::getFront() const{
    if(isEmpty()) throw std::runtime_error("Deque is empty");
    return items[front];
}

template<class Type>
const Type& ds::Deque<Type>::getBack() const{
    if(isEmpty()) throw std::runtime_error("Deque is empty");
    return items[(front+length-1) % maxSize];
}

template<class Type>
void ds::Deque<Type>::insertFront(const Type& newItem){
    if(isFull()) throw std::runtime_error("Deque is full");
    front = front == 0 ? maxSize - 1 : front - 1;
    items[front] = newItem;
    length++;
}

template<class Type>
void ds::Deque<Type>::insertBack(const Type& newItem){
    if(isFull()) throw std::runtime_error("Deque is full");
    items[(front+length) % maxSize] = newItem;
    length++;
}

template<class Type>
Type ds::Deque<Type>::deleteFront(){
    if(isEmpty()) throw std::runtime_error("Can't delete: Deque is empty");
    Type item = items[front]; 
    front = (front + 1) % maxSize;
    length--;
    return item;
}

template<class Type>
Type ds::Deque<Type>::deleteBack(){
    if(isEmpty()) throw std::runtime_error("Can't delete: Deque is empty");
    Type item = items[(front + length - 1) % maxSize]; 
    length--;
    return item;
}

template<class Type>
void ds::Deque<Type>::display()const{
    for (size_t i = 0; i < length; i++)
    {
        std::cout << items[(front + i) % maxSize] << " ";
    }
    std::cout <<std::endl;
}

template<class Type>
int ds::Deque<Type>::search(const Type& item)const{
    for (size_t i = 0; i < length; i++)
    {
        if(items[(front + i) % maxSize] == item) return i;  
    }
    return -1;
}

template<class Type>
void ds::Deque<Type>::clear(){
    length = 0;
}