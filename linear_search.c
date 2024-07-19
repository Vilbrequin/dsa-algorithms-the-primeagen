#include <stdio.h>
#include <stdbool.h>

bool linear_search(int* arr, int size, int value){
    for(int i = 0; i < size; i++){
        if(arr[i] == value){
            return true;
        }
    }
    return false;
}