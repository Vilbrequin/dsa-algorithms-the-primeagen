#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct RingBuffer{
    int* arr;
    int capacity;
    int head;
    int tail;
    int size;
};

typedef struct RingBuffer RingBuffer;

void bufferInit(RingBuffer** buf, int size){
    *buf = (RingBuffer*)malloc(sizeof(RingBuffer));
    if(*buf == NULL){
        exit(1);
    } 
    (*buf)->arr = malloc(size*sizeof(int));
    if((*buf)->arr == NULL){
        free(*buf); // Free already allocated buffer
        exit(1);
    }
    (*buf)->capacity = size; // Capacity = max size of the ribg buffer
    (*buf)->head = 0;
    (*buf)->tail = 0;
    (*buf)->size = 0; // Size initially empty
}

void enqueue(RingBuffer** buf, int element){
    if(buf == NULL || *buf == NULL){
        exit(1);
    }
    // Check if the buffer is full 
    if((*buf)->size + 1 == (*buf)->capacity){
        // Allocate a new larger buffer where new capacity = 2 * current capacity
        RingBuffer* newBuffer = (RingBuffer*)malloc(sizeof(RingBuffer));
        if(newBuffer == NULL){
            free(newBuffer);
            exit(1);
        }
        int newCapacity = 2 * (*buf)->capacity;
        newBuffer->arr = (int*)malloc(newCapacity * sizeof(int));
        if(newBuffer->arr == NULL){
            free(newBuffer);
            exit(1);
        }
        newBuffer->capacity = newCapacity;
        newBuffer->size = 0;
        newBuffer->head = 0;
        newBuffer->tail = 0;

        // Copy elements from the old buffer to the new buffer
        for(int i = (*buf)->head; i != (*buf)->tail; i = (i + 1) % (*buf)->capacity){
            newBuffer->arr[newBuffer->tail] = (*buf)->arr[i];
            newBuffer->tail++;
            newBuffer->size++;
        }

        free((*buf)->arr);
        free(*buf);
        *buf = newBuffer;
    }
    (*buf)->arr[(*buf)->tail] = element;
    (*buf)->tail = (((*buf)->tail) + 1) % (*buf)->capacity;
    (*buf)->size++;
}


void dequeue(RingBuffer** buf){
    if(buf == NULL || *buf == NULL){
        exit(1);
    }

    // Check if the buffer is not empty
    if((*buf)->size == 0){
        exit(1);
    }

    (*buf)->head = ((*buf)->head + 1) % (*buf)->capacity;
    (*buf)->size--;
}

int peek(RingBuffer** buf){
    if(buf == NULL || *buf == NULL){
        return INT_MIN;
    }
    // Check if empty 
    if((*buf)->size == 0){
        return INT_MIN;
    }
    return (*buf)->arr[(*buf)->head];
}