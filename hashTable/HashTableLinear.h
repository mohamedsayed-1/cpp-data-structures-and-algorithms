#pragma once
#include <climits>
#include <cstddef>


class HashTableLinear{
    private:
        size_t size, count;
        int* items;
        static constexpr int EMPTY = INT_MIN;
        static constexpr int DELETED = INT_MIN + 1;
        int hashing(int item) const{
            return(2654435761 * item) % size;
        }
        bool isPrime(int num) const{
            if(num < 2) return false;
            for(int i = 2; i * i <= num; i++){
                if (num % i == 0) return false;
            }
            return true;
        }
        int nextPrime(int num) const{
            while(!isPrime(num)) num++;
            return num;
        }

        void rehash(){
            int newSize = nextPrime(size * 2);
            HashTableLinear newHashTable(newSize);
            for (int i = 0; i < size; i++){
                if (items[i] == EMPTY || items[i] == DELETED) continue;
                newHashTable.insert(items[i]);
            }
            delete[] items;
            size = newHashTable.size;
            count = newHashTable.count;
            items = newHashTable.items;
            newHashTable.items = nullptr;
        }

    public:
        HashTableLinear(int s = 101):size(s <= 0 ? 101 : s), count(0){
            items = new int [size];
            for(int i = 0; i < size; i++) items[i] = EMPTY;
        }

        ~HashTableLinear(){
            delete[] items;
        }

        HashTableLinear(const HashTableLinear& other){
            int * newItems = new int [other.size];
            for(int i = 0; i < other.size; i++){
                newItems[i] = other.items[i];
            }
            count = other.count;
            size = other.size;
            items = newItems;
        }

        HashTableLinear& operator =(const HashTableLinear& other){
            if(this == &other) return *this;
            int * newItems = new int [other.size];
            for(int i = 0; i < other.size; i++){
                newItems[i] = other.items[i];
            }
            delete [] items;
            count = other.count;
            size = other.size;
            items = newItems;
            return *this;
        }

        void insert(int item){
            if(count / static_cast<double>(size) >= 0.7) rehash();
            int hash = hashing(item);
            int start = hash;
            do{
                if (items[hash] == EMPTY || items[hash] == DELETED){
                    items[hash] = item;
                    count++;
                    return;
                }
                hash = (hash + 1) % size;
            } while (hash != start);
        }
        
        int search(int item)const{
            int hash = hashing(item);
            int start = hash;
                while(items[hash] != EMPTY){                    
                    if (items[hash] == item) return hash;
                        hash = (hash + 1) % size;
                    if (hash == start) return -1;
                }
            return -1;
        }
        
        void removeItem(int item){
            int hash = search(item);
            if (hash != -1){
                items[hash] = DELETED;
                count--;
            }
        }
};