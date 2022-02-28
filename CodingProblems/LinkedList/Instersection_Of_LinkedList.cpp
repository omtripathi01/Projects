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
// t.c. O(m+n) s.c. O(n)/O(m)
// Naive Approach:-
// Traverse the LL and store all the nodes in hash map 
// then traverse the other ll and keep on looking the node in map 
// if u find the node in map then return that node
// otherwise return NULL

// Effecient Approach :

// t.c. = O(m+n)  s.c. O(1)
// Traverse first ll and count it nodes call it C1
// Traverse second ll and count it nodes call it C2
// then find d = abs(c1-c2)
// then traverse d times in the bigger ll 
// then start traversing both the ll and keep on comparing nodes 
// if u find commom node then return node otherwise return NULL

Node* instersectingNode(Node* first, Node* second){

    if(first == NULL || second == NULL)
        return NULL;
    
    int count1=0, count2=0, diff=0;
    Node* curr = first;
    while(curr != NULL){
        count1++;
        curr = curr->next;
    }
    curr = second;
    while(curr != NULL){
        count2++;
        curr = curr->next;
    }   

    diff = abs(count1 - count2);
    curr = NULL;
    Node* curr1 = NULL;
    if(count1>count2){
        curr = first;
        curr1 = second;
    }
    else if(count2>count1){
        curr = second;
        curr1 = first;
    }   

    while(diff--){
        curr = curr->next;
    }

    while(curr != NULL && curr1 != NULL){
        if(curr == curr1){
            // cout<<"\nInstersecting Node is : "<<curr->data<<endl;
            return curr;
        }
        curr = curr->next;
        curr1 = curr1->next;
    }
    return NULL;
}


int main()
{

    Node* first  = createLinkedList({1,2,3,4,6,7,78,6,5});
    Node* second = new Node(5);
    // second->next = first->next->next->next->next;

    display(first);
    display(second);

    Node* intersection = instersectingNode(first, second);
    if(intersection == NULL){
        cout<<"\nNO INTERSECTION"<<endl;
    }else{
        cout<<"\nINSTERSECTING NODE IS : "<<intersection->data<<endl;
    }




    return 0;
}