#include "sorting.h"
#include <utility>

namespace ds{
    namespace algorithms{
        void selectionSort(int arr[], const int size){
            for(int i = 0; i < size - 1; i++){
                int minIndex = i;
                for(int j = i + 1; j < size; j++){
                    if (arr[minIndex] > arr[j]) {
                        minIndex = j;
                    }
                }
                std::swap(arr[minIndex], arr[i]);
            }
        }

        void bubbleSort(int arr[], const int size){
            for (int i = 0; i < size - 1; i++){
                bool isSorted = true;
                for(int j = 0; j < size - i - 1; j++){
                    if(arr[j] > arr[j + 1]) {
                        std::swap(arr[j], arr[j + 1]);
                        isSorted = false;
                    }
                }
                if(isSorted) break;
            }
        }

        void insertionSort(int arr[], const int size){
            for (int i = 1; i < size; i++){
                int keyItem = arr[i];
                int j = i - 1;
                while(j >= 0 && keyItem < arr[j]){
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = keyItem;
            }
        }
        static void heapify(int arr[], const int size, int index){
            if (index < 0) return;
            int leftChild = -1, rightChild = -1, max = index;
            if ((2 * index + 1) < size){
                leftChild = 2 * index + 1;
            }
            if ((2 * index + 2) < size){
                rightChild = 2 * index + 2;
            }
            if (rightChild == -1 && leftChild == -1) 
                return;
            if (rightChild == -1 && leftChild != -1){
                max = leftChild;
            }
            else{
                max = arr[leftChild] > arr[rightChild] ? leftChild : rightChild;
            }
            if (index != max && arr[index] < arr[max]){
                std::swap(arr[index], arr[max]);
                heapify(arr, size, max);        
            }
        }

        static void makeMaxHeap(int arr[], const int size){
            for(int i = size/2-1; i >= 0; i--){
                heapify(arr, size, i);
            }
        }

        void heapSort(int arr[], const int size){
            makeMaxHeap(arr, size);
            for(int i = size-1; i > 0; i--){
                std::swap(arr[0], arr[i]);
                heapify(arr, i, 0);
            }
        }
    }
}