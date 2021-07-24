#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct node *next;
}node;

node *new_node(int data){
    node *temp = malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    
    return temp;
};

void printList(node *list){
    node *temp = list;

    if(temp == NULL){
        printf("No List Created...");
    }    
    else
    {
        while (temp != NULL)
        {
            printf("%d \n",temp->data);
            temp = temp->next;     
        }
        printf("\n");
    };
};

void insert_node(node *head,int data){
    node *temp = new_node(data);
    temp->next = NULL;

    node *last = head;

    if(head == NULL){
        head = temp;
        return;
    }
    else{
        while (last->next != NULL)
        {
            last = last->next;            
        }        
        last->next = temp;
        return;
    }    
};

void delete_at(node *head,int value){
    node *last = head;  
    node *prev = NULL;

    if(head == NULL){
        printf("No List Created...");
        return;
    }
    else
    {
        if(head->data == value){
            head = last->next;            
            free(head);
            return;
        };

        while (last != NULL && last->data != value){
            prev = last;
            last = last->next;
        }        

        if(last == NULL){return;};

        prev->next = last->next;
        printf("Node deleted , popped value is %d",last->data);
        free(last);        
    }   
};

int get_length_iterative(node *head){
    if(head == NULL){
        return;
    }
    else
    {
        int c = 0;

        while (head != NULL)
        {
            head = head->next;

            c +=1;
        }     

        return c;           
    }    
};

int get_length_recursive(node *head){
    if(head == NULL){
        return;
    }
    else
    {
        return 1 + get_length_recursive(head->next);        
    }    
};

void search_value_iterative(node *head,int value){
    if(head == NULL){
        return;
    }
    else
    {
        int pos = 1;
        while (head != NULL && head->data != value)
        {
            head = head->next;
            pos +=1;       
        } 
        printf("Value Found at pos %d in the list.",pos);   
    }    
};

void search_value_recursive(node *head,int value){
    if(head == NULL){
        return;
    }
    else
    {
        if(head->data == value){
            printf("Value Found in the list at pos");
        }
        else
        {
            return search_value_recursive(head->next,value);            
        }        
    }    
};

void getNth_node(node *head,int n){
    node *temp = head;

    if(temp == NULL){
        return;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            temp = temp->next;
        }            
        printf("Node Data at %d pos is %d",n,temp->data);         
    }    
};

void find_middle_node(node *head){
    node *slow = head;
    node *fast = head;

    if(head == NULL){
        return;
    }else
    {
        node *fast_ptr;
        while (fast != NULL && fast->next != NULL)
        {
            fast_ptr = fast->next;
            fast = fast_ptr->next;            
            slow = slow->next;
        }                

        printf("Middle node data is %d",slow->data);
    }    
};

void getNthnode_fromEnd(node *head,int n){ //method 1
    node *ref = head;
    node *main = head;

    for (int i = 0; i < n; i++)
    {
        ref = ref->next;        
    }    

    while (ref->next != NULL)
    {
        ref = ref->next;
        main = main->next;        
    }    

    printf("Nth Node that is %d node from End is %d",n,main->data);
};

void mergeList(node *a,node *b){
    node *temp = NULL;

    if(a == NULL){
        temp = a;
    }
    else
    {
        temp = b;        
    }    

    if(a->data <= b->data){
        temp = a;
        a = a->next;
    }
    else
    {
        temp = b;
        b = b->next;        
    }    

    node *temp_tail = temp;

    while (a != NULL && b != NULL)
    {
        node *t = NULL;

        if (a->data <= b->data)
        {
            t = a;
            a = a->next;            
        }          
        else
        {
            t = b;
            b = b->next;            
        }              

        temp_tail->next = t;
        temp_tail = t;
    }    

    if(a != NULL){
        temp_tail->next = a;
    }
    else if (b != NULL)
    {
        temp_tail->next = b;
    }    

    printList(temp);
};

void printList_reverse(node *list){
    if(list == NULL){
        return;
    }        
    printList_reverse(list->next);
    printf("%d",list->data);       
};

void sortedList_intersection(node *a ,node *b){
    node *dummy;
    node *tail = &dummy;    
    dummy->next = NULL;

    while (a != NULL && b != NULL)
    {
        if(a->data == b->data)
        {
            insert_node(&(tail->next),a->data);

            tail = tail->next;
            a = a->next;
            b = b->next;            
        }
        else if(a->data < b->data)
        {           
            a = a->next;    
        }                 
        else
        {
            b = b->next;                
        }            
    };   

    printf("Intersection of both the List are ::");
    printList(dummy);
};     

void main()
{
    node *list1 = new_node(1);
    node *list2 = new_node(5);

    insert_node(list1,2);
    insert_node(list1,3);
    insert_node(list1,4);
    insert_node(list1,5);
    insert_node(list1,6);
    insert_node(list1,7);

    insert_node(list2,6);
    insert_node(list2,7);
    insert_node(list2,8);
    insert_node(list2,9);
    
    sortedList_intersection(list1,list2);
};