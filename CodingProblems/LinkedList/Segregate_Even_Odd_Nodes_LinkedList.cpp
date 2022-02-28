// Problem: Segregate Even And Odd Nodes of Linked List

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

    if(head == NULL)return;

    Node* curr = head;
    cout<<"\n======================================\n";
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<"\n======================================\n";
}

void segregateEvenOddNodes(Node* head){

    if(head == NULL || head->next == NULL || head->next->next == NULL){
        return;
    }

    Node* oddHead = head;
    Node* evenHead = head->next;
    Node* tempEvenHead = head->next;
    Node* curr = head->next->next;

    bool flag = true; // it works as incdicator when it is true it means curr is odd placed element otherwise even
    while(curr != NULL){
        if(flag){
            oddHead->next = curr;
            oddHead = curr;
            flag = false;
        }else{
            evenHead->next = curr;
            evenHead = curr;
            flag = true;
        }
        curr = curr->next;
    }
    evenHead->next = NULL;
    oddHead->next = tempEvenHead;

}

// Algorithm:- If we are maintaing Tail pointer as well then this approach works is good
// Start traversing the Linked List
// If the curr node is even then don't do anything otherwise
// move the curr node to the end tail->next = curr and tail = tail->next
// and afte whole traversal in the end update tail->next = NULL

// we can use this approach even when we don't have tail pointer but then we have to make two traversals of
// the linked list first traversal for finding the tail and second traversal for doing the same above thing

// better apporach is the above implemented approach 

// make all the even(data) nodes at first and odd data nodes at last 
Node* segregateEvenOddNode(Node* head){

    if(head == NULL || head->next == NULL)
        return head;
    
    Node* evenStart=NULL;
    Node* evenEnd = NULL;
    Node* oddStart=NULL;
    Node* oddEnd = NULL;

    for(Node* curr=head; curr!=NULL;curr = curr->next){
        // int x = curr->data;
        if(curr->data % 2 == 0){
            if(evenStart == NULL){
                evenStart = evenEnd = curr;
            }else{
                evenEnd->next = curr;
                evenEnd = evenEnd->next;
            }
        }else{
            if(oddStart == NULL){
                oddStart = oddEnd = curr;
            }else{
                oddEnd->next = curr;
                oddEnd = oddEnd->next;
            }
        }
    }
    evenEnd->next = oddStart;
    oddEnd->next = NULL;
    return evenStart;

}

// need of less pointers 

Node* rearrange(Node* head){

    if(head == NULL || head->next == NULL)
        return head;


    Node* odd = head, *even = head->next, *evenStart = head->next;

    while(true){

        if(odd == NULL || even == NULL || even->next == NULL){
            odd->next = evenStart;
            break;
        }

        odd->next = even->next;
        odd = odd->next;        // odd = even->next;


        // if(odd->next == NULL){
        //     even->next = NULL;
        //     odd->next = evenStart;
        //     break;
        // }

        even->next = odd->next;
        even = odd->next;       // even = even->next;
    }
    
    return head;
}


int main()
{

    Node* head = createLinkedList({1,2,3,4});

    // display(head);
    // segregateEvenOddNodes(head);
    // display(head);
    
    
    // display(head);
    // head = segregateEvenOddNode(head);
    // display(head);


    display(head);
    head = rearrange(head);
    display(head);
    
    return 0;
}