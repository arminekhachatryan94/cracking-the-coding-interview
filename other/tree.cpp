/*
Consider an undirected tree with N nodes, numbered from 1 to N. Each node has a label associated with it, which is an integer value. Different nodes can have the same label. Write a function that, given a zero indexed array A of length N, where A[j] is the label value of the (j + 1)-th node in the tree and a zero-indexed array E of length K = (N – 1) * 2 in which the edges of the tree are described, returns the length of the longest path such that all the nodes on that path have the same label. The length is the number of edges in that path.

Example:

A = [1, 1, 1, 2, 2]
E = [1, 2, 1, 3, 2, 4, 2, 5]

This tree is shown below. A node follows the form label, value.

----------1, 1

-----1, 2        1, 3

2, 4      2, 5
The function should return 2, because the longest path is 2->1->3, and there are 2 edges in this path.

Assume that 1 <= N <= 1000 and each element of the array A is an integer in the range [1, 1000000000].
*/

#include <iostream>
using namespace std;

typedef struct Node {
    int val;
    struct Node * leftChild;
    struct Node * rightChild;
} Node;

int longestPath(Node * head);
void printTree( Node * head );

int main() {
/*     Node a;
    a.val = 1;
    Node b;
    b.val = 2;
    b.leftChild = NULL;
    b.rightChild = NULL;
    Node c;
    c.val = 3;
    c.leftChild = NULL;
    c.rightChild = NULL;
    
    a.leftChild = &b;
    a.rightChild = &c;

    cout<<a.val<<" "<<(*(a.leftChild)).val<<" "<<(*(a.rightChild)).val<<endl;
    cout<<b.val<<" "<<(*(b.leftChild)).val<<" "<<(*(b.rightChild)).val<<endl;
    cout<<c.val<<" "<<(*(c.leftChild)).val<<" "<<(*(c.rightChild)).val<<endl;
 */
    int A[5] = {1, 1, 1, 2, 2};
    int E[8] = {1, 2, 1, 3, 2, 4, 2, 5};

    int A_size = sizeof(A)/sizeof(int);
    int E_size = sizeof(E)/sizeof(int);
    // cout<<A_size<<endl;

    cout<<endl<<endl;
    
    // set labels
    Node * nodes;
    Node * head; // head of tree; i format
    nodes = new Node[A_size];
    for( int i = 0; i < A_size; i++ ){
        (*(nodes+i)).val = A[i];
        (*(nodes+i)).leftChild = NULL;
        (*(nodes+i)).rightChild = NULL;
        if( A[i] == i+1 ){
            head = &(*(nodes+i));
        }
    }

    // set edges
    for( int i = 0; i < E_size; i+=2 ){
        // cout<<E[i]<<" "<<E[i+1]<<endl;
        if( (*(nodes+E[i]-1)).leftChild == NULL ){
            (*(nodes+E[i]-1)).leftChild = &(*(nodes + E[i+1]-1));
        } else {
            (*(nodes+E[i]-1)).rightChild = &(*(nodes + E[i+1]-1));
        }
    }

    // printTree(head);

    int sum = 0;

    int path = longestPath(head);
    cout<<path;

    /*
    for( int i = 0; i < A_size; i++ ){
        Node n = (*(nodes+i));
        Node * leftChild = n.leftChild;
        Node * rightChild = n.rightChild;
        cout<<n.val<<" ";
        if( leftChild == NULL ){
            cout<<"null ";
        } else {
            cout<<(*leftChild).val<<" ";
        }
        if( rightChild == NULL ){
            cout<<"null"<<endl;
        } else {
            cout<<(*rightChild).val<<endl;
        }
    }
    */
}

int longestPath(Node * head) {
    int val = (*head).val;
    Node * left = (*head).leftChild;
    Node * right = (*head).rightChild;
}

void printTree( Node * head ){
    cout<<(*head).val;
    cout<<endl;
    Node * left = (*head).leftChild;
    Node * right = (*head).rightChild;
    if( left != NULL ){
        printTree(left);
    } else {
        cout<<"null ";
    }
    if( right != NULL ){
        printTree(right);
    } else {
        cout<<"null"<<endl;
    }
}
