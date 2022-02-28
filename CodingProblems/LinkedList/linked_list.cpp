#include<bits/stdc++.h>
#include<conio.h>
#include "Node.h"
using namespace std;

class SinglyLinkedList{

    public:
        Node* head;

        SinglyLinkedList(){
            head = NULL;
        }

        void insert(int data); // by default insert at the beginning
        // Function Overloading 
        void insert(int index, int data); // insert at particular index;

        void remove(); // 

};

class LinkedList{

    public: 
        int size;
        Node* head;
        Node* tail;

        LinkedList(){
            size = 0;
            head = tail = NULL;
        }

        void push_front(int data);
        void push_back(int data);

        void pop_front();
        void pop_back();

        void insertAt(int index, int data);
        void deleteAt(int index);

        int peek();
        int get_size();

        void display();
        void erase();

        void reverse();
        Node* recur(Node* head, int k);
        void reverseK(int k);
};
void LinkedList :: push_front(int data){

    Node* node = new  Node(data);
    if(head == NULL){
        head = tail = node;
        size++;
        return;
    }

    node->next = head;
    head = node;
    size++;

} 

void LinkedList :: push_back(int data){

    Node* node = new Node(data);
    if(head == NULL){
        head = tail = node;
        size++;
        return;
    }

    tail->next = node;
    tail = node;
    size++;

}

void LinkedList :: pop_front(){

    if(head == NULL){
        cout<<"List is empty (UnderFlow)."<<endl;
        return;
    }

    if(size == 1){
        head = tail = NULL;
        size--;
        return;
    }

    head = head->next;
    size--;

}

void LinkedList :: pop_back(){

    if(size == 0){
        cout<<"List is empty (UnderFlow)."<<endl;
        return;
    }

    if(size == 1){
        head = tail = NULL;
        size--;
        return;
    }

    Node* curr = head;
    while(curr->next->next != NULL)
        curr = curr->next;
    
    tail = curr;
    tail->next = NULL;
    size--;

}

void LinkedList :: insertAt(int index, int data){

    if(index > size || index < 0){
        cout<<"Invalid index(OutOfRange)."<<endl;
        return;
    }
    
    if(index == 0){
        push_front(data);
        return;
    }
    if(index == size){
        push_back(data);
        return;
    }
    int pos = index;
    Node* node = new Node(data);
    Node* curr = head;
    while(--pos){
        curr = curr->next;
    }
    
    node->next = curr->next;
    curr->next = node;
    size++;

}

void LinkedList :: deleteAt(int index){
    
    if(index >= size || index < 0){
        cout<<"Invalid index(OutOfRange)."<<endl;
        return;
    }

    if(index == 0){
        pop_front();
        return;
    }
    if(index == size-1){
        pop_back();
        return;
    }

    Node* curr = head;
    while(--index)
        curr = curr->next;
    
    curr->next = curr->next->next;
    size--;
}
void LinkedList :: display(){

    if(head == NULL){
        cout<<"List is empty."<<endl;
        return;
    }
    Node* curr = head;
    cout<<"\n=============================\n";
    for(int i=0;i<size;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }

    cout<<"\n=============================\n";
}


int LinkedList :: peek(){
    if(head == NULL){
        cout<<"List is empty."<<endl;
        return -1;
    }
    return head->data;
}

int LinkedList :: get_size(){
    return size;
}

void LinkedList :: erase(){
    head = tail = NULL;
}

void LinkedList :: reverse(){

    if(head == NULL || head->next == NULL) return;

    tail = head;
    Node* prev = NULL;
    Node* curr = head;
    Node* nxt = NULL;
    // Node* nxt = curr->next;
    while(curr != NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        // nxt = curr->next;  // this will give an error because as next is pointing to next of curr
        // suppose when curr->next = null and then next will point to null and then in this line we
        // will be accessing the null->next which will break out code so it is imp that we don't access
        // null  
    }
    head = prev;

}
// one approach is store the data of the linked list in stack and then again traverse the linked list 
// and update all the elements  (this appreoach can be used when data updation is allowed)


// now a value k will be given and we have to reverse the parts of length k of the linked list

// eg. 1->2->3->4->5->6->7->8  k = 3
// 3->2->1->6->5->4->8->7->NULL


void LinkedList :: reverseK(int k){
    head = recur(head, k);    
}

Node* LinkedList :: recur(Node* head, int k){

    if(k<0){
        cout<<"\nK must be positive"<<endl;
        return head;
    }
    if(head == NULL || head->next == NULL){
        return head;
    }
    int i=k;
    Node* curr = head;
    Node* prev = NULL;
    Node* nxt = NULL;

    while(i-- && curr != NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    // cout<<"\n"<<prev->data<<" "<<prev->next->data<<" "<<curr->data<<" "<<curr->next->data<<"\n";
    // getch();
    head->next = recur(curr, k);
    return prev;
}



int main()
{
    LinkedList ll;
    ll.push_front(20); // 20
    ll.push_back(30);  // 20 30
    ll.push_front(10); // 10 20 30
    ll.push_back(40);  // 10 20 30 40 50
    ll.push_back(50);  // 10 20 30 40 50
    ll.push_back(60);  // 10 20 30 40 50 60
    ll.display();
    // cout<<"\nSize : "<<ll.get_size()<<endl;
    
    // cout<<"Peek: "<<ll.peek()<<endl;

     // reverse a linke list 
    // cout<<ll.head->data<<" ";
    //  ll.reverse();
    //  cout<<"\nReversed Linked List: "<<endl;
    //  ll.display();
     int k = 3;
     cout<<"\nEnter K: ";
     cin>>k;
     ll.reverseK(k);
     cout<<"\nReverse linked list in :"<<k<<" parts"<<endl;
     ll.display();
    // cout<<ll.head->data<<" ";

    return 0;
}

// for testing linked list
    // ll.deleteAt(2);
    // ll.display();

    // ll.insertAt(2, 30);
    // ll.display();

    // ll.pop_front();
    // ll.display();
    // ll.push_front(10);
    // ll.display();

    // ll.pop_back();
    // ll.display();
    // ll.push_back(60);
    // ll.display();

    // ll.insertAt(0, 0);
    // ll.display();
    // ll.deleteAt(0);
    // ll.display();

    // ll.deleteAt(5);
    // ll.display();
    // ll.insertAt(5, 60);
    // ll.display();

    // ll.erase();
    // ll.display();