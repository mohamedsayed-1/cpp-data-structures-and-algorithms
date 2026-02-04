#pragma once


namespace ds{
    template <class Type>
    class Deque{
        private:
            size_t length, front ,maxSize;
            Type* items;
        public:
            Deque(int size = 100);
    };
}


template<class Type>
ds::Deque<Type>::Deque(int size):maxSize(size <= 0 ? 100 : size), length(0), front(0){
    items = new Type[maxSize];
}