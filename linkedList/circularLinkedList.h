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
            void insertBefore(const Type& item, const Type& newItem);
            void deleteItem(const Type& item);
            bool search(const Type& item) const;
            void replace(const Type& item, const Type& newItem);
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

template <class Type>
void ds::CircularLinkedList<Type>::insertBefore(const Type& item, const Type& newItem){
    if (isEmpty()) throw std::runtime_error("list is Empty");
    if(first->data == item){insertFront(newItem); return;}
    Node* curr = first->next;
    do{
        if(curr->next->data == item){
            Node* newNode = new Node{newItem, curr->next};
            curr->next = newNode;
            count++;
            return;
        }
        curr = curr->next; 
    }while(curr != first);
    throw std::runtime_error("item is not found");
}

template <class Type>
void ds::CircularLinkedList<Type>::deleteItem(const Type& item){
    if (isEmpty()) throw std::runtime_error("list is Empty");
    if(first->data == item){deleteFront(); return;}
    if(last->data == item){deleteBack(); return;}
    Node* curr = first->next;
    Node* prev = first;
    while(curr != first){
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
bool ds::CircularLinkedList<Type>::search(const Type& item) const{
    if (isEmpty()) return false;
    Node* curr = first;
    do{
        if(curr->data == item) return true;
        curr = curr->next;
    }while(curr != first);

    return false;
}

template <class Type>
void ds::CircularLinkedList<Type>::replace(const Type& item, const Type& newItem){
    if (isEmpty()) throw std::runtime_error("list is Empty");
    if(first->data == item){first->data = newItem; return;}
    if(last->data == item){last->data = newItem; return;}
    Node* curr = first->next;
    do{
        if(curr->data == item) {
            curr->data = newItem;
            return;
        }
        curr = curr->next;
    }while(curr != first);
    throw std::runtime_error("item is not found");
}