
#include "iostream"
#include "map"
#include "vector"

using namespace std;

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right; 
    bool visited = false;
}Node;

Node *create_node(int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL; 
    new_node->right = NULL;
    
    return new_node;                
};

Node* push(Node *root,int data){
    if(data){
       if(root == NULL){
           return(create_node(data));
       }
      if (data < root->data)
         root->left = push(root->left,data);
      else if (data > root->data)
         root->right = push(root->right,data);
    };
};

void display_tree(Node *root){
    if(root == NULL){
        return;
    }
    else
    {
        display_tree(root->left);    
        cout << root->data;            
        display_tree(root->right);  
    }
};

void DFS(Node *root,int data){
    vector<Node*> s;
    
    while(root){
        if(root->data == data){
            cout << "Found";
            break;
        }

        s.push_back(root);
        root->visited = true;
        root = root->right;
    };

    while(s.size()){
        
    };
};

int main(){
    Node *root = create_node(0);
    push(root,-1);
    push(root,1);
    push(root,2);
    push(root,3);
    push(root,4);    
    push(root,5);
    push(root,6);
    push(root,7);
    push(root,8);

    DFS(root,10);

    return 0;
};

