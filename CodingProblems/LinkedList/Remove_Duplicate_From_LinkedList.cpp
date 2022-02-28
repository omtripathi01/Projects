// Problem:- A sorted LinkedList is given and you have to remove duplicate elements from it

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

Node* createLinkedList(vector<int>v, Node* head=NULL){
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
// using two pointer

Node* removeDuplicates(Node* head){

    if(head == NULL || head->next == NULL)
        return head;
    Node* curr = head;
    Node* nxt = head->next;

//  no need of checking both curr and nxt because nxt is always ahead of curr so first nxt will become null
    // while(curr!=NULL && nxt != NULL){
    while(nxt != NULL){

        if(curr->data == nxt->data){
            curr->next = nxt->next;
            delete nxt;
            nxt = curr->next;
        }else{
            curr = nxt;
            nxt = nxt->next;
        }
    }
    return head;

}


// using one pointer 
Node* removeDuplicateFromSortedLL(Node* head){

    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* curr = head;
    while(curr != NULL){

        if(curr->next != NULL && curr->data == curr->next->data){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }else{
            curr = curr->next;
        }
    }
    return head;
}

// another variant of the question  remove all the duplicate nodes
// eg1. 1->1->2->3->3->4 
// output :- 2->4

Node* remove(Node* head){

    if(head == NULL || head->next == NULL)
        return head;

    Node* dummy = new Node;
    dummy->next = head;

    Node* curr = head;
    Node* prev = dummy;
    
    // dummy->next = curr;

    while(curr != NULL){

        while(curr->next != NULL && prev->next->data == curr->next->data){
            curr = curr->next;
        }
        if(prev->next == curr)
            prev = prev->next;
        else
            prev->next = curr->next;

        curr = curr->next;

    }

    return dummy->next;

 
}



int main()
{
    vector<int>test1 = {1,2,3,4,5,6}; // no duplicates
    vector<int>test2 = {1,1,1,1,1,1}; // all duplicates
    vector<int>test3 = {1,1,2,3,3,4,5}; // first element is duplicate
    vector<int>test4 = {1,2,2,2,3,3,4,5}; // more than one elements are duplicates
    vector<int>test5 = {1,2,2,2,2,2,2}; //last element is duplicate
    vector<int>test6 = {1,1};
    vector<int>test7 = {1,1,2,2,3,3,4};
    vector<int>test8 = {1,2,2,3,3,3,3,5};
    vector<int>test9 = {1,2,3,4,4};
    vector<int>test10 = {1,1,1,1,1,1,1}; // all duplicates
    Node* head = createLinkedList(test2);
    display(head);
    // head = removeDuplicates(head);
    // head = removeDuplicateFromSortedLL(head);
    head = remove(head);
    display(head);



    return 0;
}