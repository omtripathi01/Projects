#include<bits/stdc++.h>
#include<conio.h>
#include "Node.h"
using namespace std;

Node* createLinkedList(vector<int>v, Node* head=NULL){
    if(v.size() == 0)
        return NULL;
    if(head == NULL){
        head = new Node(v[0]);
    }
    Node* curr = head;
    for(int i=1;i<v.size();i++){
        Node* newNode = new Node(v[i]);
        curr->next = newNode;
        curr = curr->next;
    }    
    return head;
}

void display(Node* head){

    if(head == NULL){
        cout<<"\n===================Empty=================\n";
        return;
    }

    Node* curr = head;
    cout<<"\n======================================\n";
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<"\n======================================\n";
}


// Approach 1(Using Stack):    t.c. O(n) s.c O(n)  2 traversal of linked list
// Algo:
// 1. Create a stack
// 2. Traverse the linked list and fill the stack
// 3. Again traverse the linked list and keep on checking the top of stack if it matches with the linked list
//    current node then do this uptil end otherwise break and return false;

// Approach 2(Using Stack):  t.c. O(n) s.c. O(n)    1 traversal of LL 4
// this time i will store half linked list in stack

// Approach 3(Using Recursion):

bool isPalindrome(Node **left, Node* right){
    if(right == NULL)
        return true;

    bool isPalin = isPalindrome(left, right->next);
    if(!isPalin){
        return false;
    }

    bool isDataEqual = ((*left)->data == right->data);
    (*left) = (*left)->next;
    return isDataEqual;
}

bool isPalindrome(Node* head){
    return isPalindrome(&head, head);
}


bool checkPalindrome(Node* head){

    if(head == NULL || head->next == NULL)
        return true;

    stack<Node*>st;

    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL){
        st.push(slow);
        slow = slow->next;
        fast = fast->next->next;
    }

    if(st.size()%2 == 0){
        slow = slow->next;
    }
    while(slow != NULL && !st.empty()){
        if(slow->data != st.top()->data){
            return false;
        }
        slow = slow->next;
        st.pop();
    }
    
    if(slow != NULL || !st.empty()){
        return false;
    }

    return true;
}

int main()
{
    
    vector<vector<int>>testCase = {{1,1,1,1,1,1},
                               {1,1,2,2,1,1},
                               {1,1,2,1,1},
                               {1,2,3,2,4},
                               {1,2,3,2,1},
                               {1,2,3,2,1,1,1},
                               {1},
                               {}};

    // int choose;
    // cout<<"\nEnter your choice: ";
    // cin>>choose;
    // cout<<"\n";
    // Node* head = createLinkedList(test[choose]);

    // display(head);

    // cout<<"\n================================";
    // if(checkPalindrome(head)){
    //     cout<<"\nGiven LinkedList is Palindrome"<<endl;
    // }else{
    //     cout<<"\nLinked List is Not Palindrome"<<endl;
    // }
    // cout<<"\n================================";


    for(int i=0;i<testCase.size();i++){

        Node* head = createLinkedList(testCase[i]);
        display(head);
        cout<<"\n================================";
        if(isPalindrome(head)){
            cout<<"\nGiven LinkedList is Palindrome"<<endl;
            getch();
        }else{
            cout<<"\nLinked List is Not Palindrome"<<endl;
            getch();
        }
        cout<<"\n================================";

    }


    return 0;
}