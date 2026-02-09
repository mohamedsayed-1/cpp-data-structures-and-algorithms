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
        
        static void merge(int arr[], int* newArr,int leftStart, int leftEnd, int rightStart, int rightEnd){
            int start = leftStart;
            int newArrIndex = start;
            while(leftStart <= leftEnd && rightStart <= rightEnd){
                if(arr[leftStart] < arr[rightStart]){
                    newArr[newArrIndex++] = arr[leftStart++];
                } 
                else{
                    newArr[newArrIndex++] = arr[rightStart++];
                } 
            }
            while(leftStart <= leftEnd){
                newArr[newArrIndex++] = arr[leftStart++];
            }    
            while(rightStart <= rightEnd){
                newArr[newArrIndex++] = arr[rightStart++];
            } 
            for(int i = start; i <= rightEnd; i++){
                arr[i] = newArr[i];
            }
        }

        static void mergeSort(int arr[], int* newArr, int start, int end){
            if (start >= end) return;
            int mid = start + (end - start) / 2;
            mergeSort(arr, newArr, start, mid);
            mergeSort(arr, newArr, mid + 1, end);
            merge(arr, newArr, start, mid, mid + 1, end);
        }

        void mergeSort(int arr[], int size){
            int* newArr = new int[size];
            mergeSort(arr, newArr, 0, size-1);
            delete[] newArr;
        }

        static int partition(int arr[], int start, int end){
            int pivot = end, i = start - 1;
            for (int j = start; j < end; j++){
                if(arr[j] <= arr[pivot]){
                    std::swap(arr[j], arr[++i]);
                }
            }
            std::swap(arr[++i], arr[pivot]);
            return i;
        }

        static void quickSort(int arr[], int start, int end){
            if(start >= end) return;
            int pivotIndex = partition(arr, start, end);
            quickSort(arr, start, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, end);
        }

        void quickSort(int arr[], int size){
            quickSort(arr, 0, size - 1);
        }
    }
}