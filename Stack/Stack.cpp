
#include "iostream"
#include "string"

using namespace std;

class Node{
    public:
        string data;
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


void push(string data){
    Node* temp = new Node();
    temp->data = data;

    temp->next = stack;
    stack = temp;
};

void pop(){  
    if(isEmpty()){
        return;
    };

    Node*temp = stack;
    stack = stack->next;

    std::cout << "Popped Data :" << temp->data << std::endl;

    delete(temp);
};

void peek(){  
    if (isEmpty()){
        return ;
    }
    std::cout<< stack->data << std::endl;

};

void printStack(){
    if(stack == NULL){
        std::cout << "No Stack Made .." << std::endl;
    };

    Node* temp = stack;

    while (temp != NULL){
        std::cout << temp->data << std::endl;
        temp = temp->next;
    };
};


void reverseString(string data){
    
};





int main(){

};