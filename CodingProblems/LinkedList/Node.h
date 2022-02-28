#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
        int data;
        Node* next;

        Node(){
            // default constructor
            this->data = 0;
            this->next = NULL;

            // if we don't want to use above two line then we can simply use constructor chaining and it will 
            // work same ... constructor chaining is calling another constructor from other constructor

            // Node(0); // it will same as above two lines
        }

        Node(int d){
            data = d;
            next = NULL;
        }

        // initializer list
        // Node(int d):
        //     data(d),
        //     next(NULL)
        //     {}



};
// if we want to be more genric then use this
// use template

// template <typename T>
// class Node{

//     public:
//         T data;
//         Node* next;

//         Node(){
//             // default constructor
//             this->data = 0;
//             this->next = NULL;

//             // if we don't want to use above two line then we can simply use constructor chaining and it will 
//             // work same ... constructor chaining is calling another constructor from other constructor

//             // Node(0); // it will same as above two lines
//         }

//         Node(T d){
//             data = d;
//             next = NULL;
//         }

//         // initializer list
//         // Node(T d):
//         //     data(d),
//         //     next(NULL)
//         //     {}

// };

// then we can make Node like 

// int main(){
//     Node<int> newNode; 
//     Node<char> newNode1;
// it is same as we use different containers

//     vector<int> vec;


// }
