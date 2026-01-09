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