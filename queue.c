#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

typedef struct Node Node;

void createQueue(int* arr, int size, Node** head, Node** tail){
    if(arr == NULL){
        exit(1);
    }

    *head = (Node*)malloc(sizeof(Node));
    (*head)->value = arr[0];
    (*head)->next = NULL;
    *tail = *head;
    if(*head == NULL || *tail == NULL){
        exit(1);
    }

    int i = 1;
    for(i = 1; i < size; i++){
        Node* node = (Node*)malloc(sizeof(Node));
        if(node == NULL){
            exit(1);
        }
        node->value = arr[i];
        node->next = NULL;
        (*tail)->next = node;
        *tail = node;
    }
}

void display(Node* head){
    if(head == NULL){
        perror("Empty Queue Error !");
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

void enQueue(Node** tail, int value){
    if(tail == NULL || *tail == NULL){
        exit(1);
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    (*tail)->next = new_node;
    *tail = new_node;
}

void deQueue(Node** head){
    if(head == NULL || *head == NULL){
        exit(1);
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node = *head;
    *head =  new_node->next;
    free(new_node);

}
int peek(Node** head){
    if(head == NULL || *head == NULL){
        exit(1);
    }
    return (*head)->value;
}
