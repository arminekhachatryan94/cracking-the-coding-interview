/*
Problem 2.1
Remove Dups: Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem is a temporary buffer is not allowed?
*/

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
    private:
        char val;
        Node * next;
};

int main() {
    Node n1('1');
    Node n2('2');
    Node n3('3');
    Node n4('2');
    Node n5('4');
    Node n6('1');

    n1.setNext(&n2);
    n2.setNext(&n3);
    n3.setNext(&n4);
    n4.setNext(&n5);
    n5.setNext(&n6);

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
    n = this->next;
    cout<<"List: "<<this->val;
    while( n != NULL ){
        cout<<" "<<(*n).getVal();
        n = (*n).getNext();
    }
    cout<<endl;
}