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
    if(isEmpty()){
        insertFront(item);
    }
    else{
        Node* newNode = new Node{item, nullptr, last};
        last->next = newNode;
        last = newNode;
        count++;
    }
}