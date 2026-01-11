namespace ds{
    template<class Type>
    class CircularLinkedList{
        private:
            struct Node{
                Type data;
                Node* next;
            };
            Node* first;
            Node* last;
            size_t count;
        public:
            CircularLinkedList();
            bool isEmpty() const;
            void insertFront(const Type& item);
            void insertBack(const Type& item);
            void deleteFront();
            void deleteBack();
        };
    }

template <class Type>
ds::CircularLinkedList<Type>::CircularLinkedList():first(nullptr), last(nullptr), count(0){}

template <class Type>
bool ds::CircularLinkedList<Type>::isEmpty() const{
    return count == 0;
}

template <class Type>
void ds::CircularLinkedList<Type>::insertFront(const Type& item){
    Node* newNode = new Node{item, nullptr};
    if(isEmpty()) {
        first = last = newNode;
        newNode->next = first;
    }
    else{
        newNode->next = first;
        first = newNode;
        last->next = first;
    }
    count++;
}

template <class Type>
void ds::CircularLinkedList<Type>::insertBack(const Type& item){
    Node* newNode = new Node{item, nullptr};
    if(isEmpty()) {
        first = last = newNode;
        newNode->next = first;
    }
    else{
        last->next = newNode;
        last = newNode;
        newNode->next = first;
    }
    count++;
}

template <class Type>
void ds::CircularLinkedList<Type>::deleteFront(){
    if (isEmpty()) throw std::runtime_error("Can't delete, the linked list is Empty");
    if (count == 1) {
        delete first;
        first = last = nullptr;
        count--;
        return;
    }
    Node* curr = first;
    first = first->next;
    last->next = first;
    delete curr;
    count--;
}

template <class Type>
void ds::CircularLinkedList<Type>::deleteBack(){
    if (isEmpty()) throw std::runtime_error("Can't delete, the linked list is Empty");
    if (count == 1){deleteFront(); return;}
    Node* curr = first;
    while(curr->next != last) curr = curr->next;
    Node* tmp = last;
    last = curr;
    delete tmp;
    last->next = first;
    count--;
}