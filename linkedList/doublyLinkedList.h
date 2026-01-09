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
    Node* curr = first;
    while(curr != nullptr){
        if(curr->data == item) return true;
        curr = curr->next;
    }
    return false;
}

template <class Type>
void ds::DoublyLinkedList<Type>::insertBefore(const Type& item, const Type& newItem){
    if (isEmpty()) throw std::runtime_error("list is Empty");
    if(first->data == item){insertFront(newItem); return;}
    Node* curr = first;
    while(curr->next != nullptr){
        if(curr->next->data == item){
            Node* newNode = new Node{newItem, curr->next, curr};
            curr->next->prev = newNode; 
            curr->next = newNode;
            count++;
            return;
        } 
        curr = curr->next;
    }
    throw std::runtime_error("item is not found");
}

template <class Type>
void ds::DoublyLinkedList<Type>::deleteItem(const Type& item){
    if (isEmpty()) throw std::runtime_error("list is Empty");
    if(first->data == item){deleteFront(); return;}
    if(last->data == item){deleteBack(); return;}
    Node* curr = first->next;
    while(curr != nullptr){
        if(curr->data == item){
            curr->next->prev = curr->prev;
            curr->prev->next = curr->next;
            delete curr;
            count--;
            return;
        } 
        curr = curr->next;
    }
    throw std::runtime_error("item is not found");
}

template <class Type>
bool ds::DoublyLinkedList<Type>::replace(const Type& item, const Type& newItem){
    Node* curr = first;
    while(curr != nullptr){
        if(curr->data == item) {
            curr->data = newItem;
            return true;
        }
        curr = curr->next;
    }
    return false;
}