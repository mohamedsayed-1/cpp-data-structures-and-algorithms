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
        Array2D(const Array2D& other);
        Array2D& operator=(const Array2D& other);
        ~Array2D();
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

template <class Type>
ds::Array2D<Type>::Array2D(const Array2D& other){
    Type** newArr = new Type*[other.maxRow];
    for(size_t i = 0; i < other.maxRow; i++){
        newArr[i] = new Type[other.maxCol];
    }
    for (size_t i = 0; i < other.maxRow; i++){
        for (size_t j = 0; j < other.maxCol; j++){
            newArr[i][j] = other.arr[i][j];
        }
    }
    arr = newArr;
    maxRow = other.maxRow;
    maxCol = other.maxCol;
}

template <class Type>
ds::Array2D<Type>& ds::Array2D<Type>::operator=(const ds::Array2D<Type>& other){
    if(this == &other) return *this;
    Type** newArr = new Type*[other.maxRow];
    for(size_t i = 0; i < other.maxRow; i++){
        newArr[i] = new Type[other.maxCol];
    }
    for (size_t i = 0; i < other.maxRow; i++){
        for (size_t j = 0; j < other.maxCol; j++){
            newArr[i][j] = other.arr[i][j];
        }
    }
        for(size_t i = 0; i < maxRow; i++){
        delete[] arr[i];
    }
    delete[] arr;
    arr = newArr;
    maxRow = other.maxRow;
    maxCol = other.maxCol;
    return *this;
}

template <class Type>
ds::Array2D<Type>::~Array2D(){
    for(size_t i = 0; i < maxRow; i++){
        delete[] arr[i];
    }
    delete[] arr;
}