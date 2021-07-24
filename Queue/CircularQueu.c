
#include <stdio.h>


typedef struct node {
    int data;
    struct node *next;
}node;

typedef struct {
    node* front;
    node* rear;    
}queue;


void init_queue(queue *q){
    q->front = NULL;
    q->rear = NULL;
};

void enQueue(queue* q, int data) 
{
    node* temp = malloc(sizeof(node));
    
    temp->data = data; 

    if (q->front == NULL) 
        q->front = temp; 
    else
        q->rear->next = temp; 
  
    q->rear = temp; 
    q->rear->next = q->front; 
};

void printList(queue *q){

    node* temp = q->front; 

    printf("\nElements in Circular Queue are: "); 

    while (temp->next != q->front) { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } 
    printf("%d", temp->data); 
};

void main(){
    
    queue q;

   init_queue(&q);

    enQueue(&q,10);
    enQueue(&q,11);
    enQueue(&q,12);
    enQueue(&q,13);
    enQueue(&q,14);

    printList(&q);

};
  