#include<bits/stdc++.h>
#include "Node.h"
using namespace std;

Node* createLinkedList(vector<int>v, Node* head=NULL){
    if(v.size() == 0)
        return NULL;
    int i=0;
    if(head == NULL){
        head = new Node(v[0]);
        i=1;
    }
    Node* curr = head;
    for(;i<v.size();i++){
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


int get_size(Node* head){

    Node* curr = head;
    int size = 0;
    while(curr != NULL){
        size++;
        curr = curr->next;
    }

    return size;
}


// in this we have considered that number are given in correct order in linked list
Node* add(Node* larger, Node* smaller){
 vector<int>fi;
    Node* curr = larger;
    while(curr != NULL){
        fi.push_back(curr->data);
        curr = curr->next;
    }
    vector<int>se(fi.size(),0);
    int i=0;
    curr = smaller;
    while(curr != NULL){
        se[i++] = curr->data;
        curr = curr->next; 
    }
    reverse(se.begin(),se.begin()+i);
    reverse(se.begin(),se.end());
    int carry = 0;
    //debugging
    // cout<<"\n-------------------------------\n";
    // for(auto i : fi)
    //     cout<<i<<" ";
    // cout<<endl;
    // for(auto i : se)
    //     cout<<i<<" ";
    // cout<<"\n-------------------------------\n";
    for(int i=fi.size()-1;i>=0;i--){
        fi[i] += se[i]+carry;
        if(fi[i]>9){
            carry = 1;  // because when adding two one digit number first digit of result cannot be more than 1
            fi[i] = fi[i]%10;
        }else{
            carry = 0;
        }
    }

    // debugging
    // cout<<"\n-------------------------------\n";
    // for(auto i : fi)
    //     cout<<i<<" ";
    // cout<<endl;
    // for(auto i : se)
    //     cout<<i<<" ";
    // cout<<"\n-------------------------------\n";
    Node* head = NULL;
    if(carry == 1){
        head = new Node(1);
    }
    head = createLinkedList(fi, head);
    return head;

}


Node* addNumbersOfLL(Node* first, Node* second){

    if(first == NULL && second == NULL)
        return NULL;    
    else if(first == NULL)
        return second;
    else if(second == NULL)
        return first;
    
    int firstLen = get_size(first);
    int secondLen = get_size(second);

    if(firstLen >= secondLen){
        return add(first, second);
    }

    return add(second, first);  

}

// when numbers are given in opposite order in ll
// eg. num = 123  then ll = 3->2->1->NULL (opposite manner)

Node* addTwoNumbers(Node* a, Node* b){

    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;

    Node dummy;
    Node* ptr = &dummy;

    int sum = 0, carry = 0;

    while(a != NULL || b != NULL){

        sum = ((a == NULL)?0 : a->data) + ((b == NULL)?0 : b->data) + carry;
        carry = sum/10;
        sum = sum%10;

        ptr->next = new Node(sum);
        ptr = ptr->next;

        if(a != NULL){
            a = a->next;
        }

        if(b != NULL){
            b = b->next;
        }

    } 

    if(carry > 0){
        ptr->next = new Node(carry);
        ptr = ptr->next;
    }

    return dummy.next;

}


int main()
{

    vector<int>l1 = {9,9,9,9,9};
    vector<int>l2 = {9,1};

    Node* first = createLinkedList(l1);
    Node* second = createLinkedList(l2);

    display(first);
    display(second);

    Node* sumNode = addNumbersOfLL(first, second);
    display(sumNode);
    Node* sum = addTwoNumbers(first, second);
    display(sum);


    return 0;
}