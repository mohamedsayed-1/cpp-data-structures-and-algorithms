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
        };
    }

template <class Type>
ds::CircularLinkedList<Type>::CircularLinkedList():first(nullptr), last(nullptr), count(0){}
