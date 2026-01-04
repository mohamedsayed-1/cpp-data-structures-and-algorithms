#pragma once
#include <iostream>

namespace ds{
template <class Type>
class Array2D{
    private:
        size_t maxRow, maxCol;
        Type** arr;
    public:
        Array2D(int rowSize = 100, int colSize = 100);
};
}


template <class Type>
ds::Array2D<Type>::Array2D(int rowSize, int colSize){
    maxRow = (rowSize <= 0) ? 100 : rowSize;
    maxCol = (colSize <= 0) ? 100 : colSize;
    arr = new Type* [maxRow];
    for(size_t i = 0; i < maxRow; i++){ 
        arr[i] = new Type[maxCol];
    }
    for (size_t i = 0; i < maxRow; i++){
        for (size_t j = 0; j < maxCol; j++){
            arr[i][j] = Type();
        }
    }
}