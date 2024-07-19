#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void print(int val){
    printf("%d\n", val);
}
int tow_crystal_balls(bool* breaks, int size){

    if (size <= 0 || breaks == NULL) {
        return -1; // Error case
    }

    // Initialization of the jump size
    int jump_size = (int)sqrt((double)size);

    // First Ball Drops
    int i = 0;
    for(i = jump_size; i < size; i += jump_size){
        if(breaks[i]){
            break;
        }
    } 

    // Second Ball Drops
    for(int j = i - jump_size; j < i; j++){
        if(breaks[j]){
            return j;
        }
    }
    
    // If the ball doesn’t break at the final drop point return i
    return i;
}
