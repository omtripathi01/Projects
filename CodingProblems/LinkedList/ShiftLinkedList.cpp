// Shifting nodes by k 
// k=2
// 0->1->2->3->4->5->NULL
// 4->5->0->1->2->3->NULL
// K can be +ve or -ve
// k = +ve means shifting should be forward
// k = -ve means shifting should be backward
// Test Case:
// 1. K can be greater than number of nodes in the list
// 2. 

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            next = NULL;
        }
};

void display(Node* head){
    if(head == NULL)return;
    Node* temp = head;
    cout<<"=============================="<<endl;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n=============================="<<endl;
}

Node* forwardShiftLinkedListByKPos(Node* head, int k){
    // forward shifting 
    // Node* newHead = NULL;
    Node* first = head;
    Node* second = head;
    for(int i=0;i<k;i++){
        second = second->next;
    }
    while(second->next != NULL){
        second = second->next;
        first = first->next;
    }
    second->next = head;
    head = first->next;
    first->next = NULL;

    return head;
}

Node* backwardShiftLinkedListByKPos(Node* head, int k){

    Node* first = head;
    Node* second = head;
    



}

int main(){

    Node* head = new Node(0);
    Node* temp = head;
    temp->next = new Node(1);
    temp->next->next = new Node(2);
    temp->next->next->next = new Node(3);
    temp->next->next->next->next = new Node(4);
    temp->next->next->next->next->next = new Node(5);
    display(head);
    Node* newHead = forwardShiftLinkedListByKPos(head, 2);
    display(newHead);
    return 0;
}