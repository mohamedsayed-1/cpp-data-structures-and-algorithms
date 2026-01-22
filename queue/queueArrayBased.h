namespace ds{
    template <class Type>
    class queue{
        private:
            Type* items;
            size_t maxSize;
            size_t length;
        public:
            queue(int size = 100);
        };
}

template <class Type>
ds::queue<Type>::queue(int size):length(0){
    if(size <= 0) maxSize = 100;
    else maxSize = size;
    items = new Type[maxSize];
}