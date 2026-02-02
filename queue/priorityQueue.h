#pragma once
#include <cstddef>
#include <iostream>
#include <stdexcept>


namespace ds{
    template<class Type>
    class PriorityQueue{
        private:
            struct Node{
                Type data;
                Node* next;
            };
            Node* first;
            Node* last;
            size_t count;
        public:
            PriorityQueue();
            void enqueue(const Type& item);
            void dequeue();
            const Type& getFront()const;
            bool isEmpty() const;
            void display() const;
            size_t size() const;
            void clear();
    };
}

template <class Type>
ds::PriorityQueue<Type>::PriorityQueue():first(nullptr), last(nullptr), count(0){}

template <class Type>
void ds::PriorityQueue<Type>::enqueue(const Type& item){
    Node* newNode = new Node{item, nullptr};
    if(isEmpty()) {
        first = last = newNode;
    }
    else{
        if(item >= first->data){
            newNode->next = first;
            first = newNode;
        }
        else if(item <= last->data){
            last->next = newNode;
            last = newNode;
        }
        else{
            Node* curr = first;
            while(curr->next != nullptr && item < curr->next->data){
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }
    count++;
}

template <class Type>
void ds::PriorityQueue<Type>::dequeue(){
    if (isEmpty()) throw std::runtime_error("list is Empty");
    Node* curr = first;
    if (count == 1)
        first = last = nullptr;
    else 
        first = first->next;
    delete curr;
    count--;
} 

template <class Type>
const Type& ds::PriorityQueue<Type>::getFront()const{
    if (isEmpty()) throw std::runtime_error("list is Empty");
    return first->data;
}

template <class Type>
bool ds::PriorityQueue<Type>::isEmpty() const{
    return count == 0;
}

template <class Type>
void ds::PriorityQueue<Type>::display() const{
    Node* curr = first;
    while(curr != nullptr){
        std::cout << curr->data << "  ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

template <class Type>
size_t ds::PriorityQueue<Type>::size() const{
    return count;
}

template <class Type>
void ds::PriorityQueue<Type>::clear() {
    Node* curr = first;
    while(first != nullptr){
        curr = first;
        first = first->next;
        delete curr;
    }
    count = 0;
    first = last = nullptr;
}