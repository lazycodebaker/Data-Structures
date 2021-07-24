
#include <stdio.h>
#include <stdlib.h>

#define HASHTABLE_SIZE 20

typedef struct node{
    int value;
    struct node *next;
}node;

node *getHashTable(){
    node *hashTable = calloc(HASHTABLE_SIZE,sizeof(node));
    return hashTable;
};

void insert_new_node(node *head , int data){

    node *new_node = malloc(sizeof(node));
    new_node->value = data;
    new_node->next = NULL;

    if(head == NULL){
        head = new_node;
    }
    else
    {
        node *current = head;

        while(current->next != NULL){
            current = current->next;            
        }    
        current->next = new_node;
    }
};

int get_hash_key(key){
    return key % HASHTABLE_SIZE;
};

void insert_into_table(node* hash_table , int data){

    int index = get_hash_key(data);

    if(hash_table[index] == NULL){
        hash_table[index] = malloc(sizeof(node));
        node *head = NULL;        
        insert_new_node(&head,data);
        hash_table[index] = head;
    }
    else
    {
        node *head = hash_table[index];
        insert_new_node(&head,data);
        hash_table[index] = head;
    }
};

void display_table(node *hash_table){
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        node *head = hash_table[i];
        printf("%d Table Key",i);

        if(head == NULL){
            printf("NULL");
        }
        else
        {
            node *current = head;

            while (current->next != NULL)
            {
                printf("%d",current->value);
                current = current->next;
            }
        }
    } 
};

void main(){
    node **hashTable = getHashTable();

    insert_into_table(&hashTable,10);
    insert_into_table(&hashTable,41);
    insert_into_table(&hashTable,16);
    insert_into_table(&hashTable,23);
    insert_into_table(&hashTable,45);
    insert_into_table(&hashTable,45);
    insert_into_table(&hashTable,50);
    insert_into_table(&hashTable,86);
    insert_into_table(&hashTable,98);
    insert_into_table(&hashTable,17);

    display_table(&hashTable);
};