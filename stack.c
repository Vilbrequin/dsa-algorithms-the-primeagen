#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

typedef struct Node Node;

void createStack(int* arr, int size, Node** head, Node** prev_tail, Node** tail){
    if(arr == NULL){
        exit(1);
    }
    *head = (Node*)malloc(sizeof(Node));
    if(*head == NULL){
        exit(1);
    }
    (*head)->value = arr[0];
    (*head)->next = NULL;
    *tail = (Node*)malloc(sizeof(Node));
    *tail = *head;
    *prev_tail = NULL;
    for(int i = 1; i < size; i++){
        *prev_tail = *tail;
        Node* node = (Node*)malloc(sizeof(Node));
        node->next = NULL;
        node->value = arr[i];
        (*tail)->next = node;
        *tail = node;
    }
}

void display(Node* head){
    if(head == NULL){
        perror("Empty List Error !");
        exit(1);
    }
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL){
        exit(1);
    }
    node = head;
    while(node->next != NULL){
        printf("%d --> ", node->value);
        node = node->next;
    }
    printf("%d --> NULL\n", node->value);
}

void push(Node** tail, int value){
    if(tail == NULL || *tail == NULL){
        exit(1);
    }
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    (*tail)->next = node;
    *tail = node;
}

void pop(Node** prev_tail, Node** tail){
    if(tail == NULL || *tail == NULL){
        exit(1);
    }
    Node* node = (Node*)malloc(sizeof(Node));
    node = *tail;
    (*prev_tail)->next = NULL;
    *tail = *prev_tail;
    free(node);
}

int peek(Node** tail){
    if(tail == NULL || *tail == NULL){
        exit(1);
    }
    return (*tail)->value;
}
