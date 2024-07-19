#include <stdio.h>

int binary_search(int* arr, int size, int value){
    int low = 0;
    int high = size;
    while(low < high){
        int mid = (int)(low + high)/2;
        if(arr[mid] == value){
            return mid;
        }
        else if (arr[mid] < value){
            low = mid +1;
        }
        else {
            high = mid;
        }
    }
    return -1;
}

