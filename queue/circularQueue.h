#pragma once
#include <cstddef>


namespace ds{
    template <class Type>
    class Queue{
        private:
            size_t length, front ,maxSize;
            Type* items;
        public:
            Queue(int size = 100);
    };
}

template<class Type>
ds::Queue<Type>::Queue(int size):length(0), front(0){
    if (size <= 0) maxSize = 100;
    else maxSize = size;
    items = new Type[maxSize];
}