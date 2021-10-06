
#include "iostream"

class Node{
    public:
        int data;
        Node *next = NULL;
};

Node* stack;

Node* newNode(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;

    return temp;
};

bool isEmpty(){
    return stack == NULL;
};

void push(int data){
    Node* temp = new Node();
    temp->data = data;

    temp->next = stack;
    stack = temp;
};

void printStack(){
    if(stack == NULL){
        std::cout << "No Stack Made .." << std::endl;
    }

    while (stack != NULL){
        std::cout << stack->data << std::endl;
        stack = stack->next;
    };
    
};


int main(){

    push(10);
    push(12);
    push(11);
    push(13);

    printStack();

    isEmpty();
};