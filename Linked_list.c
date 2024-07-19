#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int value;
    struct Node* next;
};

typedef struct Node Node;

/************************************************ INITIALIZATION ************************************************/

void create_list(int* arr, int size, Node** head){
    if(size == 0 || arr == NULL){
        exit(1);
    }

    *head = (Node*)malloc(sizeof(Node));
    if(*head == NULL){
        perror("Allocation Failed !");
        exit(1);
    }
    (*head)->value = arr[0];
    (*head)->next = NULL;

    Node* tail = (Node*)malloc(sizeof(Node));
    tail = *head;

    for(int i = 1; i < size; i++){
        Node* new_node = (Node*)malloc(sizeof(Node));
        if(new_node == NULL){
            perror("Allocation Failed !");
            exit(1);
        }
        new_node->value = arr[i];
        new_node->next = NULL;

        tail->next = new_node;
        tail = new_node;
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

/************************************************ INSERTION ************************************************/

void inseartAtStart(Node** head, int value){
    if(head == NULL){
        exit(1);
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        exit(1);
    }    
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;
}

void insertAtEnd(Node** head, int value){
    if(head == NULL){
        exit(1);
    }
    Node* node = *head;
    if(node == NULL){
        exit(1);
    }
    while(node->next != NULL){
        node = node->next;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        exit(1);
    }
    node->next = new_node;
    new_node->next = NULL;
    new_node->value = value;
}

void insertAtPosition(Node** head, int position, int value){
    if(head == NULL || *head == NULL){
        exit(1);
    }
    Node* node = *head;
    if(node == NULL){
        exit(1);
    }
    if(position == 0){
        Node* new_node = (Node*)malloc(sizeof(Node));
        if(new_node == NULL){
            exit(1);
        }
        new_node->next = node;
        new_node->value = value;
        *head = new_node;
    }
    else {
        while(position){
            node = node->next;
            position--;
            if(position == 1){
                Node* prev_node = (Node*)malloc(sizeof(Node));
            }
        }
    }
}

/************************************************ DELETION ************************************************/

void deleteFromBeginning(Node** head){
    if(head == NULL || *head == NULL){
        exit(1);
    }
    Node* tmp = *head;
    if(tmp->next == NULL){ // only one node
        *head = NULL;
    }
    else {
        *head = (*head)->next;
    }
    free(tmp);
}

void deleteFromEnd(Node** head){
    if(head == NULL || *head == NULL){
        exit(1);
    }
    Node* tmp = *head;
    if(tmp == NULL){
        exit(1);
    }

    if(tmp->next == NULL){ // only one node
        *head = NULL;
        free(tmp);
        return;
    }

    Node* prev = tmp;
    while(tmp->next != NULL){
        prev = tmp;
        tmp = tmp->next;
    }
    prev->next = NULL;
    free(tmp);

}

void deleteByValue(Node** head, int value){
    if(head == NULL || *head == NULL){
        exit(1);
    }
    Node* current = *head;
    Node* prev = NULL;

    // Cas : Delete head nodes
    while(current != NULL && current->value == value){
        Node* tmp = *head;
        *head = (*head)->next;
        current = current->next;
        free(tmp);
    }

    // Cas : Delete non-head nodes
    while(current != NULL){
        if(current->value == value){
            Node* tmp = current;
            prev->next = current->next;
            current = current->next;
            free(tmp);
        }
        else{
            prev = current;
            current = current->next;
        }
    }
}

void deleteByPosition(Node** head, int position){
    if(head == NULL || *head == NULL){
        exit(1);
    }
    Node* current = *head;
    if(current == NULL){
        exit(1);
    }
    if(position == 0){//delete head node
        *head = current->next;
        free(current);
        return;
    }
    else{
        int count = 0;
        Node* prev = NULL;
        while(current != NULL){
            if(position == count){
                prev->next = current->next;
                free(current);
                return;
            }
            prev = current;
            current = current->next;
            count++;
        }
        printf("Positon %d not exist max position is %d!\n", position, count - 1);
        exit(1);
    }
}

/************************************************ SEARCH ************************************************/

int getValueByIndex(Node** head, int position){
    if(head == NULL || *head == NULL){
        exit(1);
    }
    Node* current = *head;
    if(current == NULL){
        exit(1);
    }
    int count = 0;
    while(current != NULL){
        if(count == position){
            return current->value;
        }
        count++;
        current = current->next;
    }
    printf("Positon %d not exist max position is %d!\n", position, count - 1);
    return -1;
}

bool exists(Node** head, int value){
    if(head == NULL || *head == NULL){
        exit(1);
    }

    Node* current = *head;
    if(current == NULL){
        exit(1);
    }
    
    while(current != NULL){
        if(current->value == value){
            return true;
        }
        current = current->next;
    }
    return false;
}