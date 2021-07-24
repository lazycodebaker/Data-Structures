
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* head;

void push(int data){

    Node* new_node = malloc(sizeof(Node));

    if(new_node == NULL) return;
    
    new_node->data = data;
    new_node->next = head;

    head = new_node;  
};

void printList(){
    while (head != NULL)
    {
        printf("%d",head->data);

        head = head->next;
    };    
};

int pop(){

    if(head == NULL) return;

    int result = head->data;

    printf("%d Result is ",result);

    Node* temp = head;

    head = head->next;

    free(temp);

    return result;
};

void main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);

    printList();

    printf("%d Popped Element is ",pop());
};


