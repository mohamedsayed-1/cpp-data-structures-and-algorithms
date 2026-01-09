#include <iostream>
#include <stdexcept>

namespace ds{
    template<class Type>
    class DoublyLinkedList{
        private:
            struct Node{
                Type data;
                Node* next;
                Node* prev;
            };
            Node* first;
            Node* last;
            size_t count;
            Node* findNode(const Type& item) const;
        public:
            DoublyLinkedList();
            bool isEmpty() const;
            void insertFront(const Type& item);
            void insertBack(const Type& item);
            void deleteFront();
            void deleteBack();
            bool search(const Type& item) const;
            void insertBefore(const Type& item, const Type& newItem);
            void deleteItem(const Type& item);
            bool replace(const Type& item, const Type& newItem);
            void display() const;
            size_t size() const;
            void clear();
            DoublyLinkedList& operator=(const DoublyLinkedList<Type>& other);
            DoublyLinkedList(const DoublyLinkedList<Type>& other);
            ~DoublyLinkedList();
    };
}


template <class Type>
ds::DoublyLinkedList<Type>::DoublyLinkedList():first(nullptr), last(nullptr), count(0){}

template <class Type>
bool ds::DoublyLinkedList<Type>::isEmpty() const{
    return count == 0;
}

template <class Type>
void ds::DoublyLinkedList<Type>::insertFront(const Type& item){
    Node* newNode = new Node{item, nullptr, nullptr};
    if(isEmpty()) {
        first = last = newNode;
    }
    else{
        newNode->next = first;
        first->prev = newNode;
        first = newNode;
    }
    count++;
}

template <class Type>
void ds::DoublyLinkedList<Type>::insertBack(const Type& item){
    Node* newNode = new Node{item, nullptr, nullptr};
    if(isEmpty()){
        first = last = newNode;
    }
    else{
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
    }
    count++;
}

template <class Type>
void ds::DoublyLinkedList<Type>::deleteFront(){
    if (isEmpty()){
        throw std::runtime_error("Can't delete, the linked list is Empty");
    }    
    else if (count == 1) {
        delete first;
        first = last = nullptr;
        count = 0;
    }
    else{
        Node* curr = first;
        first = first->next;
        first->prev = nullptr;
        delete curr;
        count--;
    }
}

template <class Type>
void ds::DoublyLinkedList<Type>::deleteBack(){
    if (isEmpty()) {
        throw std::runtime_error("Can't delete, the linked list is Empty");
    }   
    else if (count == 1) {
        delete first;
        first = last = nullptr;
        count = 0;
    }
    else{    
        Node* curr = last;
        last = last->prev;
        last->next = nullptr;
        delete curr;
        count--;
    }
}

template <class Type>
bool ds::DoublyLinkedList<Type>::search(const Type& item) const{
    return findNode(item) != nullptr; 
}

template <class Type>
void ds::DoublyLinkedList<Type>::insertBefore(const Type& item, const Type& newItem){
    Node* curr = findNode(item);
    if(curr == first){
        insertFront(newItem);
    }
    else if(curr){
        Node* newNode = new Node{newItem, curr, curr->prev};
        curr->prev->next = newNode;
        curr->prev = newNode; 
        count++;
    }
    else
        throw std::runtime_error("item is not found");
}

template <class Type>
void ds::DoublyLinkedList<Type>::deleteItem(const Type& item){
    if(first->data == item) deleteFront();
    else if(last->data == item) deleteBack();
    else {
        Node* deletedItem = findNode(item);
        if(deletedItem){
                deletedItem->next->prev = deletedItem->prev;
                deletedItem->prev->next = deletedItem->next;
                delete deletedItem;
                count--;
        }
        else
            throw std::runtime_error("item is not found");
    }
}

template <class Type>
bool ds::DoublyLinkedList<Type>::replace(const Type& item, const Type& newItem){
    Node* replacedNode = findNode(item);
    if(replacedNode){
        replacedNode->data = newItem;
        return true;
    }
    return false;
}

template <class Type>
typename ds::DoublyLinkedList<Type>::Node* ds::DoublyLinkedList<Type>::findNode(const Type& item) const{
    Node* curr = first;
    while(curr != nullptr){
        if(curr->data == item) return curr;
        curr = curr->next;
    }
    return nullptr;
}

template <class Type>
void ds::DoublyLinkedList<Type>::display() const{
    Node* curr = first;
    while(curr != nullptr){
        std::cout << curr->data << "  ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

template <class Type>
size_t ds::DoublyLinkedList<Type>::size() const{
    return count;
}

template <class Type>
void ds::DoublyLinkedList<Type>::clear() {
    while (!isEmpty()) deleteFront();
}

template <class Type>
ds::DoublyLinkedList<Type>& ds::DoublyLinkedList<Type>::operator=(const ds::DoublyLinkedList<Type>& other){
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
ds::DoublyLinkedList<Type>::DoublyLinkedList(const DoublyLinkedList<Type>& other):first(nullptr), last(nullptr), count(0){
    Node* curr = other.first;
    while(curr != nullptr){
        insertBack(curr->data);
        curr = curr->next;
    }
}

template <class Type>
ds::DoublyLinkedList<Type>::~DoublyLinkedList(){
    clear();
}