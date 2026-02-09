#include "searching.h"


namespace ds{
    namespace algorithms{
        int linearSearch(int arr[], int size, int item){
            for (int i = 0; i < size; i++){
                if (arr[i] == item) return i;
            }
            return -1;
        }

        int binarySearch(int arr[], int size, int item){
            int start = 0, end = size - 1;
            while (start <= end)
            {
                int half = start + (end - start) / 2;
                if (arr[half] == item) return half;
                if (item > arr[half]) start = half + 1;
                else end = half - 1;
            }
            return -1;
        }

        static int binarySearchRecursive(int arr[], int start, int end, int item){
            if (start > end) return -1;
            int half = start + (end - start)/2;
            if (item == arr[half]) return half;
            if (item > arr[half]) return binarySearchRecursive(arr, half+1, end, item);
            return binarySearchRecursive(arr, start, half - 1, item);
        }

        int binarySearchRecursive(int arr[], int size, int item){
            return binarySearchRecursive(arr, 0, size - 1, item);
        }
    }
}