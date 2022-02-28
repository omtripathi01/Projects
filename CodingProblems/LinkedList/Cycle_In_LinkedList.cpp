// Problem:- A linked List is given it may have cycles and you have to detect whether there is cycle in the 
// linked list or not

#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

// one method is to modify the structure of linked list 

// s.c. -->O(n)  and t.c.-->O(n) using hashing
bool detectCycle(Node *head){

    if(head == NULL || head->next == NULL || head->next->next == NULL)
        return false;
    
    unordered_set<Node*>us;
    Node* curr = head;

    while(curr != NULL){

        if(us.find(curr) != us.end()){
            return true;
        }
        us.insert(curr);
        curr = curr->next;

    }
    return false;
}

//=====================================================================================//

                            // Using Floyd Cycle Detection

//=====================================================================================//
// O(m+n) its the length of the linked list
bool isLoop(Node* head){

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL &&  fast->next != NULL){
        slow = slow->next;       // moving with speed 1
        fast = fast->next->next; // moving witb speed 2

        if(slow == fast)
            return true;
    }
    return false;

}

//=====================================================================================//

        // Now detect and remove the loop from linked list

//=====================================================================================//

// Algorithm:
// 1. Detect the loop using Floyd Loop Detection Technique
// 2. When the slow and fast pointer meet then simply move the slow poniter to the beginning
// 3. Then move both the pointers with same speed and the point they again meet will be the beginning
//    of the loop and use another pointer prev to store the prev node of the fast pointer 
// 4. in the end simply make prev->next = null 

bool detectAndRemoveTheLoop(Node* head){

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            break;

    }
    // improvements
    // if(slow == NULL || fast == NULL || fast->next == NULL){
    //     return false;
    // }
    // instead above if condition use below if condition
        if(slow != fast)
            return false;

    slow = head;

    // Improvement  
    // instead of using another pointer to store prev of fast pointer what we can do is :-
    
    // Node* prev = fast;
    // while(slow != fast){
    //     slow = slow->next;
    //     prev = fast;
    //     fast = fast->next;

    // }
    // prev->next = NULL;

    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;

    return true;

}

// variations of detecting and removing loop form linked list

//  1. Find the length of the loop 
//  2. Find the first node of the loop



int main()
{

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;
    // head->next->next->next->next = NULL;

    // when ll has only one node
    Node* head1 = new Node(1);
    head1->next = head1;


    cout<<"\n==================================\n";
    if( isLoop(head1))
        cout<<"Loop/Cycle exist"<<endl;
    else    
        cout<<"No Cycle"<<endl;
    cout<<"\n==================================\n";
    cout<<"\n==================================\n";
    if(detectAndRemoveTheLoop(head1))
        cout<<"Loop exists and it has been removed"<<endl;
    else    
        cout<<"No loop exists"<<endl;

    cout<<"\n==================================\n";




    return 0;
}