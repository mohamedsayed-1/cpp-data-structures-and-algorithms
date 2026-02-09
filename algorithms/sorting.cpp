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
    }
}