
#include <stdio.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

void pushFront(struct Node** head,int data){

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
 
    new_node->data = data; 
 
    new_node->next = *head; 

    new_node->prev = NULL; 
 
    if ((*head) != NULL) 
        (*head)->prev = new_node; 
 
    *head = new_node; 
};

void append(struct Node** head,int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 

    new_node->data = data;

    struct Node* last = *head;
    
    new_node->next = NULL;

    if (*head == NULL)
    { 
        new_node->prev = NULL; 
        *head = new_node; 
        return; 
    } 

    while (last->next != NULL) 
        last = last->next; 
 
    last->next = new_node; 
    new_node->prev = last; 
};

void printList(struct Node* head) 
{ 
    struct Node* last; 

    printf("\nTraversal in forward direction \n"); 
    while (head != NULL) { 
        printf(" %d ", head->data); 
        last = head; 
        head = head->next; 
    } 
 
    printf("\nTraversal in reverse direction \n"); 
    while (last != NULL) { 
        printf(" %d ", last->data); 
        last = last->prev; 
    } 
}; 

void insertBefore(struct Node** head , int position , int data){

        struct Node* pos;
        struct Node* temp = head;

        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 

        if(head == NULL){
            return;
        };

        for(int i = 0; i < position;i++){
            temp = temp->next;
        };    

        new_node->data = data;

        new_node->prev = temp->prev;
        temp->prev = new_node;
        new_node->next = temp;                  

         if (new_node->prev != NULL) 
            new_node->prev->next = new_node; 

        else
            head = new_node;        
};

void main() {

    struct Node* head = NULL; 

    append(&head, 1);      
    append(&head, 2);  
    append(&head, 3); 
    append(&head, 4);      
    append(&head, 5);  
    append(&head, 6); 
 
    printf("Created DLL is: "); 
    printList(head);     

    insertBefore(head,3,11);

    printf("List after new insertion");

    printList(head);
}
