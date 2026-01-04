#pragma once
#include <iostream>
#include <stdexcept>

namespace ds{
    template<class Type>
    class LinkedList{
        private:
            struct Node{
                Type data;
                Node* next;
            };
            Node* first;
            Node* last;
            size_t count;
        public:
            LinkedList();
            bool isEmpty() const;
            void insertFront(const Type& item);
            void insertBack(const Type& item);
            void deleteFront();
            void deleteBack();
            bool search(const Type& item) const;
            void insertBefore(const Type& oldItem, const Type& newItem);
            void deleteItem(const Type& item);
            bool replace(const Type& item,const Type& newItem);
            const Type& getFirst()const;
            const Type& getLast()const;
            void display() const;
            size_t size() const;
            void reverse();
            void clear();
            LinkedList& operator=(const LinkedList<Type>& other);
            LinkedList(const LinkedList<Type>& other);
            ~LinkedList();
   };
}


template <class Type>
ds::LinkedList<Type>::LinkedList():first(nullptr), last(nullptr), count(0){}

template <class Type>
bool ds::LinkedList<Type>::isEmpty() const{
    return count == 0;
}

template <class Type>
void ds::LinkedList<Type>::insertFront(const Type& item){
    Node* newNode = new Node;
    newNode->data = item;
    if(isEmpty()) {
        newNode->next = nullptr;
        first = last = newNode;
    }
    else{
        newNode->next = first;
        first = newNode;
    }
    count++;
}

template <class Type>
void ds::LinkedList<Type>::insertBack(const Type& item){
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = nullptr;
    if(isEmpty()) {
        first = last = newNode;
    }
    else{
        last->next = newNode;
        last = newNode;
    }
    count++;
}

template <class Type>
void ds::LinkedList<Type>::deleteFront(){
    if (isEmpty()) throw std::runtime_error("Can't delete, the linked list is Empty");
    if (count == 1) {
        delete first;
        first = last = nullptr;
        count--;
        return;
    }
    Node* curr = first;
    first = first->next;
    delete curr;
    count--;
}

template <class Type>
void ds::LinkedList<Type>::deleteBack(){
    if (isEmpty()) throw std::runtime_error("Can't delete, the linked list is Empty");
    if (count == 1){deleteFront(); return;}
    Node* curr = first;
    while(curr->next != last) curr = curr->next;
    last = curr;
    curr = curr->next;
    delete curr;
    last->next = nullptr;
    count--;
}

template <class Type>
bool ds::LinkedList<Type>::search(const Type& item) const{
    Node* curr = first;
    while(curr != nullptr){
        if(curr->data == item) return true;
        curr = curr->next;
    }
    return false;
}

template <class Type>
void ds::LinkedList<Type>::insertBefore(const Type& item, const Type& newItem){
    if (isEmpty()) throw std::runtime_error("list is Empty");
    if(first->data == item){insertFront(newItem); return;}
    Node* curr = first;
    while(curr != nullptr && curr->next != nullptr){
        if(curr->next->data == item){
            Node* newNode = new Node{newItem, curr->next};
            curr->next = newNode;
            count++;
            return;
        } 
        curr = curr->next;
    }
    throw std::runtime_error("item is not found");
}

template <class Type>
void ds::LinkedList<Type>::deleteItem(const Type& item){
    if (isEmpty()) throw std::runtime_error("list is Empty");
    if(first->data == item){deleteFront(); return;}
    if(last->data == item){deleteBack(); return;}
    Node* curr = first->next;
    Node* prev = first;
    while(curr != nullptr){
        if(curr->data == item){
            prev->next = curr->next;
            delete curr;
            count--;
            return;
        } 
        curr = curr->next;
        prev = prev->next;
    }
    throw std::runtime_error("item is not found");
}

template <class Type>
bool ds::LinkedList<Type>::replace(const Type& oldItem,const Type& newItem){
    Node* curr = first;
    while(curr != nullptr){
        if(curr->data == oldItem){
            curr->data = newItem;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

template <class Type>
const Type& ds::LinkedList<Type>::getFirst()const{
    if (isEmpty()) throw std::runtime_error("list is Empty");
    return first->data;
}

template <class Type>
const Type& ds::LinkedList<Type>::getLast()const{
    if (isEmpty()) throw std::runtime_error("list is Empty");
    return last->data;
}

template <class Type>
void ds::LinkedList<Type>::display() const{
    Node* curr = first;
    while(curr != nullptr){
        std::cout << curr->data << "  ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

template <class Type>
size_t ds::LinkedList<Type>::size() const{
    return count;
}

template <class Type>
void ds::LinkedList<Type>::reverse(){
    if(count <= 1) return;
    Node* prev, * curr, * next;
    prev = next = nullptr;
    curr = first;
    last = first;
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    first = prev;
}

template <class Type>
void ds::LinkedList<Type>::clear() {
    while (!isEmpty()) deleteFront();
}

template <class Type>
ds::LinkedList<Type>& ds::LinkedList<Type>::operator=(const ds::LinkedList<Type>& other){
    if(this == &other) return *this;
    clear();
    Node* curr = other.first;
    while(curr != nullptr){
        insertBack(curr->data);
        curr = curr->next;
    }
    return *this;
}

template <class Type>
ds::LinkedList<Type>::LinkedList(const LinkedList<Type>& other):first(nullptr), last(nullptr), count(0){
    Node* curr = other.first;
    while(curr != nullptr){
        insertBack(curr->data);
        curr = curr->next;
    }
}

template <class Type>
ds::LinkedList<Type>::~LinkedList(){
    clear();
}