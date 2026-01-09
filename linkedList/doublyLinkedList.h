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
    };
}


template <class Type>
ds::DoublyLinkedList<Type>::DoublyLinkedList():first(nullptr), last(nullptr), count(0){}