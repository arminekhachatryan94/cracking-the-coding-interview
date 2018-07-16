
#include <iostream>
using namespace std;

class Node {
    public:
        Node();
        Node(char val, Node * next);
        Node(char val);
        ~Node();
        void setVal(char val);
        void setNext(Node * next);
        char getVal();
        Node * getNext();
        void printList();
        void removeDuplicates();
        char findKthToLast(int k);
        bool deleteMiddleNode(Node & m);
    private:
        char val;
        Node * next;
};

int main() {
    Node n1('1');
    Node n2('2');
    Node n3('3');
    Node n4('4');
    Node n5('5');
    Node n6('6');
    Node n7('7');
    Node n8('8');

    n1.setNext(&n2);
    n2.setNext(&n3);
    n3.setNext(&n4);
    n4.setNext(&n5);
    n5.setNext(&n6);
    n6.setNext(&n7);
    n7.setNext(&n8);

    n1.printList();
    // n1.removeDuplicates();
    // n1.printList();

    // char k = n1.findKthToLast(9);
    // cout<<k<<endl;

    n1.deleteMiddleNode(n8);
    n1.printList();

}

Node::Node(){
    this->val = -1;
    next = NULL;
}

Node::Node(char val, Node * next) {
    this->val = val;
    this->next = next;
}

Node::Node(char val){
    this->val = val;
    next = NULL;
}

Node::~Node() {
    this->val = -1;
}

void Node::setVal(char val){
    this->val = val;
}

void Node::setNext(Node * next){
    this->next = next;
}

char Node::getVal(){
    return this->val;
}

Node * Node::getNext(){
    return this->next;
}

void Node::printList(){
    Node * n;
    n = this;
    cout<<"List:";
    while( n != NULL ){
        cout<<" "<<n->val;
        n = n->next;
    }
    cout<<endl;
}

/*
Problem 2.1
Remove Dups: Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem is a temporary buffer is not allowed?
*/
void Node::removeDuplicates(){
    // char v = this->val;
    
    Node * n;
    n = this;

    Node * d;
    d = this->next;

    Node * p; // pointer to node before d
    p = this;

    while( n != NULL && d != NULL ){
        while( d != NULL ){
            cout<<"p: "<<p->val<<", d: "<<d->val<<", n: "<<n->val<<endl;
            if( d->val == n->val ){
                p->next = d->next;
            }
            p = d;
            d = d->next;
        }
        cout<<endl;
        n = n->next;
        p = n;
        d = p->next;
    }

    n = this;
    while( n != NULL && n->next != NULL ){
        if( n->val == n->next->val ){
            n->next = n->next->next;
        } else {
            n = n->next;
        }
    }

/*     if( n->val == d->val ){
        p->next = d->next;
        d = d->next;
    }

    while( n != NULL && d != NULL ){
        p = n;
        while( d != NULL ){
            if( d->val == v || d->val == p->val ){
                p->next = d->next;
                cout<<p->val<<" "<<d->val<<endl;
            }
            p = d;
            d = d->next;
        }
        v = n->val;
        n = n->next;
        d = n;
    }
 */}

/*
Problem 2.2
Return Kth to Last: Implement an algorithm to
find the kth to last element of a singly linked list. */
char Node::findKthToLast(int k){
    Node * n = this;
    int len = 0;
    while( n != NULL ){
        len++;
        n = n->next;
    }
    if( k > len ){
        return -1;
    }
    n = this;
    for( int i = 0; i < len-k; i++ ){
        n = n->next;
    }
    return n->val;
}

/*
Problem 2.3
Delete Middle Node: Implement an algorithm to delete a node in the middle
(Le., any node but the first and last node, not necessarily the exact middle)
of a singly linked list, given only access to that node.

EXAMPLE
Input: the node c from the linked list a- >b- >c - >d - >e- >f
Result: nothing is returned, but the new linked list looks like a->b->d->e->f
*/
bool Node::deleteMiddleNode(Node & m){
    if( m.val == -1 || m.next == NULL ){
        m = NULL;
        return false;
    } else {
        Node next = *(m.next);
        m.val = next.val;
        m.next = next.next;
        return true;
    }
}

