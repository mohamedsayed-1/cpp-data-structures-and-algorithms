#pragma once
#include <climits>
#include <cstddef>


class HashTableQuadratic{
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
            HashTableQuadratic newHashTable(newSize);
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
        HashTableQuadratic(int tableSize = 101): size(tableSize), count(0){
            if (tableSize <= 0) size = 101;
            items = new int [size];
            for(int i = 0; i < size; i++) items[i] = EMPTY;
        }

        ~HashTableQuadratic(){
            delete[] items;
        }
        
        HashTableQuadratic(const HashTableQuadratic& other){
            int * newItems = new int [other.size];
            for(int i = 0; i < other.size; i++){
                newItems[i] = other.items[i];
            }
            count = other.count;
            size = other.size;
            items = newItems;
        }

        HashTableQuadratic& operator =(const HashTableQuadratic& other){
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
            for(int i = 0; i < size; i++){
                int prob = (hash + i * i) % size;
                if (items[prob] == EMPTY || items[prob] == DELETED){
                    items[prob] = item;
                    count++;
                    return;
                }
            } 
        }
        
        int search(int item) const{
            int hash = hashing(item);
            for(int i = 0; i < size; i++){
                int prob = (hash + i * i) % size;
                if (items[prob] == item) return prob;                
                if (items[prob] == EMPTY) return -1;                
            }    
            return -1;
        }
        
        void removeItem(int item){
            int hash = search(item);
            if (hash != -1) {
                items[hash] = DELETED;
                count--;
            }
        }
};