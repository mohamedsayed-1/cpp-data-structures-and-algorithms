namespace ds{
    template <class Type>
    class queue{
        private:
            Type* items;
            size_t maxSize;
            size_t length;
        public:
            queue(int size = 100);
            ~queue();
            queue(const queue<Type>& other);
            queue& operator = (const queue<Type>& other);
        };
}


template <class Type>
ds::queue<Type>::queue(int size):length(0){
    if(size <= 0) maxSize = 100;
    else maxSize = size;
    items = new Type[maxSize];
}

template <class Type>
ds::queue<Type>::~queue(){
    delete[] items;
}

template <class Type>
ds::queue<Type>::queue(const queue<Type>& other){
    Type* newArr = new Type[other.maxSize];
    for (size_t i = 0; i < other.length; i++)
    {
        newArr[i] = other.items[i];
    }
    maxSize = other.maxSize;
    length = other.length;
    items = newArr;
}

template <class Type>
ds::queue<Type>& ds::queue<Type>::operator = (const queue<Type>& other){
    if(this == &other) return *this;
    Type* newArr = new Type[other.maxSize];
    for (size_t i = 0; i < other.length; i++)
    {
        newArr[i] = other.items[i];
    }
    delete[] items;
    maxSize = other.maxSize;
    length = other.length;
    items = newArr;
    return *this;
}