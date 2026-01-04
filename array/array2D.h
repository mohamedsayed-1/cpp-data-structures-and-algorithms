#pragma once
#include <iostream>
#include <stdexcept>

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
        Type at(int row, int col) const;
        void display()const;
        size_t rows() const;
        size_t cols() const;
        size_t size()const;
        void fill(const Type& element);
        void clear();
        void insert(int col, int row, const Type& newItem);
        void erase(int col, int row);
        std::pair<int, int> search(const Type& key)const;
        void enlarge(int newRowSize, int newColSize);
        void merge(const Array2D& other);
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

template <class Type>
Type ds::Array2D<Type>::at(int row, int col) const{
    if(row < 0 || row >= maxRow || col < 0 || col >= maxCol)
        throw std::out_of_range("invalid index");
    return arr[row][col];
}

template <class Type>
void ds::Array2D<Type>::display()const{
    for (size_t i = 0; i < maxRow; i++)
    {
        for (size_t j = 0; j < maxCol; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <class Type>
size_t ds::Array2D<Type>::rows() const{
    return maxRow;
}

template <class Type>
size_t ds::Array2D<Type>::cols() const{
    return maxCol;
}

template <class Type>
size_t ds::Array2D<Type>::size()const{
    return maxCol * maxRow;
}

template <class Type>
void ds::Array2D<Type>::fill(const Type& element){
    for (size_t i = 0; i < maxRow; i++){
        for (size_t j = 0; j < maxCol; j++){
            arr[i][j] = element;
        }
    }
}

template <class Type>
void ds::Array2D<Type>::clear(){ 
    for (size_t i = 0; i < maxRow; i++){
        for (size_t j = 0; j < maxCol; j++){
            arr[i][j] = Type();
        }
    }
}

template <class Type>
void ds::Array2D<Type>::insert(int row, int col, const Type& newItem){
    if(row < 0 || row >= maxRow || col < 0 || col >= maxCol)
        throw std::out_of_range ("invalid index");
    arr[row][col] = newItem;
}

template <class Type>
void ds::Array2D<Type>::erase(int row, int col){
    if(row < 0 || row >= maxRow || col < 0 || col >= maxCol)
        throw std::out_of_range ("invalid index");
    arr[row][col] = Type();
}

template <class Type>
std::pair<int, int> ds::Array2D<Type>::search(const Type& key)const{
    for (int i = 0; i < maxRow; i++){
        for (int j = 0; j < maxCol; j++)
        {
            if (arr[i][j] == key) return {i, j};
        }
    }
    return {-1, -1};
}

template <class Type>
void ds::Array2D<Type>::enlarge(int newRowSize, int newColSize){
    if(newRowSize <= maxRow || newColSize <= maxCol) 
        throw std::runtime_error("new size must be greater than current capacity");    
    Type** newArr = new Type* [newRowSize];
    for(size_t i = 0; i < newRowSize; i++){ 
        newArr[i] = new Type[newColSize];
    }
    for (size_t i = 0; i < maxRow; i++){
        for (size_t j = 0; j < maxCol; j++){
            newArr[i][j] = arr[i][j];
        }
    }
    for(size_t i = 0; i < maxRow; i++){
        delete[] arr[i];
    }
    delete[] arr;
    arr = newArr;
    maxRow = newRowSize;
    maxCol = newColSize;
}

template <class Type>
void ds::Array2D<Type>::merge(const ds::Array2D<Type>& other){
    Type** newArr = new Type*[maxRow+other.maxRow];
    size_t cols = maxCol > other.maxCol? maxCol: other.maxCol;
    for (size_t i = 0; i < maxRow+other.maxRow; i++){
        newArr[i] = new Type[cols];
    }
    for (size_t i = 0; i < maxRow; i++) {
        for (size_t j = 0; j < cols; j++) {
            newArr[i][j] = (j < maxCol) ? arr[i][j] : Type();
        }
    }
    for (size_t i = 0; i < other.maxRow; i++) {
        for (size_t j = 0; j < cols; j++) {
            newArr[maxRow + i][j] = (j < other.maxCol) ? other.arr[i][j] : Type();
        }
    }
    for(size_t i = 0; i < maxRow; i++){
        delete[] arr[i];
    }
    delete[] arr;
    arr = newArr;
    maxCol = cols;
    maxRow = maxRow+other.maxRow;
}