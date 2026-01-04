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
   };
}

template <class Type>
ds::LinkedList<Type>::LinkedList():first(nullptr), last(nullptr), count(0){}
