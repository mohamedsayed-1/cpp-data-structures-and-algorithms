#pragma once

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