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
            bool isEmpty()const;
            bool isFull()const;
            void enqueue(const Type& item);
            Type dequeue();
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

template <class Type>
bool ds::queue<Type>::isEmpty()const{
    return length == 0;
}

template <class Type>
bool ds::queue<Type>::isFull()const{
    return length == maxSize;
}

template <class Type>
void ds::queue<Type>::enqueue(const Type& item){
    if(isFull()) throw std::runtime_error("queue is full");
    items[length] = item;
    length++;
}

template <class Type>
Type ds::queue<Type>::dequeue(){
    if(isEmpty()) throw std::underflow_error("queue is empty");
    Type item = items[0];
    for (size_t i = 0; i < length - 1; i++)
    {
        items[i] = items[i + 1];
    }
    length--;
    return item;
}