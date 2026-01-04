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
            void deleteFront();
            void deleteBack();
            bool search(const Type& item) const;
            void insertBefore(const Type& oldItem, const Type& newItem);
            void deleteItem(const Type& item);
            bool replace(const Type& item,const Type& newItem);
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