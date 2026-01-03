#pragma once
#include <iostream>

namespace ds{
template <class Type>
class Array{
    private:
        size_t length, maxSize;
        Type* elements;
    public:
        Array(int size = 100);
};
}


template <class Type>
ds::Array<Type>::Array(int size): length(0){
    if (size <= 0) maxSize = 100;
    else maxSize = size;
    elements = new Type[maxSize];
}