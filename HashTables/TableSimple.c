

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct{ 
    char name[MAX_NAME];
    int age;
}person;

person *HASH_TABLE[TABLE_SIZE];

unsigned char hash(char *name){

    int length = strnlen(name,MAX_NAME);
    unsigned int hash_value = 0;

    for (int i = 0; i <length; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE ;
    }        
    return hash_value;
};

void init_hash_table(){
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        HASH_TABLE[i] = NULL;
    }            
};

void printTables(){
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if(HASH_TABLE[i] == NULL){
            printf("\t%i\t ----->\t%s\t\n",i,"No Person");
        }
        else
        {
            printf("\t%i\t ----->\t%s\t\n",i,HASH_TABLE[i]->name);
        }        
    }
};

void hash_table_insert(person *p){
    if(p == NULL){
        return;
    }
    else
    {
        int index = hash(p->name);

        if(HASH_TABLE[index] != NULL){
            printf("Cant insert %s in table as the index is %d \t\n\n",p->name,index);
        }
        else
        {
            HASH_TABLE[index] = p;
        }        
    }    
};

void hash_table_lookup(char *name){
    
    int index = hash(name);

    if(HASH_TABLE[index] != NULL)
    {
        printf("Person %s found at index %d in the table \t\n\n",name,index);
    }   
    else
    {
        printf("Person %s not Found in table",name);
    }   
};

void hash_table_delete(char *name){
    
    int index = hash(name);

    if(HASH_TABLE[index] != NULL && ((strncmp(HASH_TABLE[index]->name,name,TABLE_SIZE)==0)) )
    {
        person *tmp = HASH_TABLE[index];
        HASH_TABLE[index] = NULL;

        printf("Person %s deleted from table \n\n",tmp->name);
    }   
    else
    {
        printf("Person %s not Found in table",name);
    }   
};

void main(){

    init_hash_table();   

    person Jane     = { .name = "Jane"    , .age = 20};    
    person Denny    = { .name = "Denny"   , .age = 21};    
    person Maris    = { .name = "Maris"   , .age = 19};    
    person Marc     = { .name = "Marc"    , .age = 25};    
    person Gates    = { .name = "Gates"   , .age = 15}; 
    person Jenny    = { .name = "Jenny"   , .age = 35};    
    person Anshuman = { .name = "Anshuman", .age = 30};    
    person Joy      = { .name = "Joy"     , .age = 41};    
    person william  = { .name = "william" , .age = 27};    
    person Tim      = { .name = "Tim"     , .age = 29};  

    hash_table_insert(&Jane);
    hash_table_insert(&Denny);
    hash_table_insert(&Maris);
    hash_table_insert(&Marc);
    hash_table_insert(&Gates);
    hash_table_insert(&Jenny);
    hash_table_insert(&Anshuman);
    hash_table_insert(&Joy);
    hash_table_insert(&william);
    hash_table_insert(&Tim);

    printTables();
};