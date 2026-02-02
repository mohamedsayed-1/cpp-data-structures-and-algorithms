#pragma once

namespace ds{
    template<class Type>
    class PriorityQueue{
        private:
            struct Node{
                Type data;
                Node* next;
            };
            Node* first;
            Node* last;
            size_t count;
        public:
            PriorityQueue();
    };
}

template <class Type>
ds::PriorityQueue<Type>::PriorityQueue():first(nullptr), last(nullptr), count(0){}