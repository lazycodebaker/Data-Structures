
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct node {
    int data;
    struct node *next;
}node;

typedef struct {
    node* head;
    node* tail;    
}queue;

void init_queue(queue *q){
    q->head = NULL;
    q->tail = NULL;
};

void enqueue(queue *q , int data){

    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if(!new_node){
        return;
    }
    
    if(q->tail != NULL){
        q->tail->next = new_node;
    }

    q->tail = new_node;

    if(q->head == NULL){
        q->head = new_node;
    }
};

void dequeue(queue *q){

    if(q->head == NULL){
        return;
    }

    node *temp = q->head;

    int res = temp->data;
    q->head = q->head->next;

    if(q->head == NULL){
        q->tail = NULL;
    }

    free(temp);

    printf("%d",res);
};

void isEmptyorFull(queue *q){

   if (q->head != NULL)
   {
       printf("Not empty");
   }       
   else
   {
       printf("Empty");
   }      
};

void printList(queue *q){
    while (q->head != NULL)
    {
        printf("%d",q->head->data);
        q->head = q->head->next;
    }    
};

void main()
{
    queue s1 ;

    init_queue(&s1);    

    enqueue(&s1,10);
    enqueue(&s1,11);
    enqueue(&s1,12);
    enqueue(&s1,13);
    enqueue(&s1,14);
    enqueue(&s1,15);

    isEmpty(&s1);

    printList(&s1);    
};









