// Type of DFS traversals in Tree:-
// Inorder Traversal   --> Left Root Right
// Preorder Traversal  --> Root Left Right
// Postorder Traversal --> Left Right Root

// BFS Traversal:-
// Level Order Traversal

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;


class Tree{

    public:
        Node* root;

        Tree():
            root(NULL)
        {}

        Node* createTree(const vector<char>nodeData);
        
        void inorderTraversal(Node* root);
        void preorderTraversal(Node* root);
        void postorderTraversal(Node* root);

        void levelOrderTraversal(Node* root);

        void display(Node* root);

};

Node* Tree :: createTree(const vector<char>nodeData){
    Node* root = new Node(nodeData[0]);
    queue<Node*>q;
    q.push(root);
    int i = 1;
    int n = nodeData.size();
    while(!q.empty() && i<n){
        int count = q.size();
        for(int j=0;j<count;j++){
            Node* curr = q.front();
            q.pop();

            if(nodeData[i] != 'N'){
                curr->left = new Node(nodeData[i]);
                q.push(curr->left);
            }else{
                curr->left = NULL;
            }
            if(i+1 < n && nodeData[i+1] != 'N'){
                curr->right = new Node(nodeData[i+1]);
                q.push(curr->right);
            }else{
                curr->right = NULL;
            }
            i+=2;  
        }
    }
    return root;

}

void Tree :: inorderTraversal(Node* root){

    if(root == NULL) return;

    inorderTraversal(root->left);   // left
    cout<<root->data<<" ";          // root
    inorderTraversal(root->right);  // right
    
}
void Tree :: preorderTraversal(Node* root){

    if(root == NULL) return;

    cout<<root->data<<" ";          // root
    preorderTraversal(root->left);  // left
    preorderTraversal(root->right); // right

}
void Tree :: postorderTraversal(Node* root){

    if(root == NULL) return;

    postorderTraversal(root->left); // left
    postorderTraversal(root->right);// right    
    cout<<root->data<<" ";          // root   

}

void Tree :: levelOrderTraversal(Node* root){
    if(root == NULL) return;
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        int count = q.size();

        for(int i=0;i<count;i++){
            Node* curr = q.front();
            cout<<curr->data<<" ";
            q.pop();
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
        cout<<endl;
    }
}
void Tree :: display(Node *root){
    levelOrderTraversal(root);
}


int main()
{

    Tree t;
    Node* root = t.createTree({'1','2','3','4','5','6','7'});

    t.display(root);
    cout<<"\nPreorder : ";
    t.preorderTraversal(root);
    cout<<"\nInorder : ";
    t.inorderTraversal(root);
    cout<<"\nPostorder : ";
    t.postorderTraversal(root);


    return 0;
}