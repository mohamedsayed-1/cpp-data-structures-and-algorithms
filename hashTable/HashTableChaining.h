#include "../linkedList/linkedList.h"
#include <cstddef>


class HashTable{
    private:
        static constexpr size_t size = 101;
        ds::LinkedList<int> items[size];
        int hashing(int item) const{
            return(2654435761 * item) % size;
        }
    public:
        void insert(int item){
            int hash = hashing(item);
            items[hash].insertFront(item);
        }

        int search(int item){
            int hash = hashing(item);
            if (items[hash].search(item)) return hash;
            return -1;
        }
        
        void removeItem(int item){
            int hash = hashing(item);
            items[hash].deleteItem(item);
        }    
};