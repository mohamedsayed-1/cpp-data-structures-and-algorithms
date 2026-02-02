#pragma once

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