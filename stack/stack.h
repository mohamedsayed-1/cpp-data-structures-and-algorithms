#pragma once
#include <cstddef>


namespace ds{
    template <class Type>
    class Stack{
        private:
            Type* items;
            size_t maxSize;
            size_t length;
        public:
            Stack(int size = 100);
    };
}

template <class Type>
ds::Stack<Type>::Stack(int size):length(0), maxSize(size <= 0 ? 100 : size){
    items = new Type[maxSize];
}