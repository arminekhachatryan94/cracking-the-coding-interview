
#include <iostream>
#include <list>
#include <map>
#include <iterator>
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
        Node operator+ (Node const & n2);
    private:
        char val;
        Node * next;
};

Node addReverseLists(Node a, Node b);
Node addForwardLists(Node a, Node b);
bool isPalindrome(Node n);
Node intersection(Node m, Node n);
Node loopDetection(Node n);

int main() {
    Node a1('6');
    Node a2('1');
    Node a3('7');
    Node b1('2');
    Node b2('9');
    Node b3('5');
    a1.setNext(&a2);
    b1.setNext(&a2);
    a2.setNext(&a3);
    a3.setNext(&b2);
    b2.setNext(&b3);

    a1.printList();
    b1.printList();

    Node r = addForwardLists(a1, b1);
    r.printList();

    // is Palindrome
    Node * p = NULL;
    Node * p_back = NULL;
    for( int i = 0; i <= 6; i++ ){
        Node * p1 = new Node;
        if( i <= 6/2 ){
            p1->setVal(i + '0');
        } else {
            p1->setVal(6-i + '0');
        }
        p1->setNext(NULL);
        if( p == NULL ){
            p = p1;
            p_back = p1;
        } else {
            p_back->setNext(p1);
            p_back = p_back->getNext();
        }
    }
    (*p).printList();
    cout<<"isPalindrome: "<<(isPalindrome(*p)? "true" : "false")<<endl;

    cout<<endl<<endl<<"Intersection ";
    Node t = intersection(a1, b1);
    t.printList();

    Node c1('A');
    Node c2('B');
    Node c3('C');
    Node c4('D');
    Node c5('E');
    c1.setNext(&c2);
    c2.setNext(&c3);
    c3.setNext(&c4);
    c4.setNext(&c5);
    c5.setNext(&c3);

    Node loop = loopDetection(c1);
    cout<<"loopDetection: "<<loop.getVal()<<endl;
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
}

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
Input: the node c from the linked list a->b->c->d->e->f
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

/*
Problem 2.4
Partition: Write code to partition a linked list around a value x,
such that all nodes less than x come before all nodes greater than
or equal to x. If x is contained within the list, the values of x
only need to be after the elements less than x (see below). The
partition element x can appear anywhere in the "right partition";
it does not need to appear between the left and right partitions.
EXAMPLE
Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition=5]
Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
*/

/*
Problem 2.5
Sum Lists: You have two numbers represented by a linked list, where
each node contains a single digit. The digits are stored in reverse
order, such that the 1's digit is at the head of the list. Write a
function that adds the two numbers and returns the sum as a linked list.
EXAMPLE
Input: (7-> 1 -> 6) + (5 -> 9 -> 2) .That is, 617 + 295. Output:2 -> 1 -> 9.That is, 912.
FOLLOW UP
Suppose the digits are stored in forward order. Repeat the above problem.
Input: (6 -> 1 -> 7) + (2 -> 9 -> 5).That is, 617 + 295. Output:9 -> 1 -> 2.That is, 912.
*/
Node addReverseLists(Node a, Node b) {
    Node * ptr1;
    Node * ptr2;

    ptr1 = &a;
    ptr2 = &b;

    list<int> a1;
    list<int> b1;

    while( ptr1 != NULL ){
        a1.push_front(ptr1->getVal()-'0');
        ptr1 = ptr1->getNext();
    }
    cout<<endl;
    while( ptr2 != NULL ){
        b1.push_front(ptr2->getVal()-'0');
        ptr2 = ptr2->getNext();
    }

    int num1 = 0;
    int num2 = 0;
    int sum = 0;
    while( a1.size() != 0 ){
        int n = a1.front();
        a1.pop_front();
        num1 *= 10;
        num1 += n;
    }
    while( b1.size() != 0 ){
        int n = b1.front();
        b1.pop_front();
        num2 *= 10;
        num2 += n;
    }
    sum = num1+num2;

    list<int> c1;
    while( sum != 0 ){
        c1.push_front((sum%10) + '0');
        sum -= sum%10;
        sum /= 10;
    }

    Node * head = NULL;
    Node * tail = NULL;
    while( c1.size() != 0 ){
        Node * temp = new Node;
        temp->setVal(c1.front());
        temp->setNext(NULL);
        c1.pop_front();
        if( head == NULL ){
            head = temp;
            tail = temp;
        } else {
            tail->setNext(temp);
            tail = tail->getNext();
        }
    }

    return *head;
}

Node addForwardLists(Node a, Node b) {
    Node * ptr1;
    Node * ptr2;

    ptr1 = &a;
    ptr2 = &b;

    list<int> a1;
    list<int> b1;

    while( ptr1 != NULL ){
        a1.push_front(ptr1->getVal()-'0');
        ptr1 = ptr1->getNext();
    }
    cout<<endl;
    while( ptr2 != NULL ){
        b1.push_front(ptr2->getVal()-'0');
        ptr2 = ptr2->getNext();
    }

    int num1 = 0;
    int num2 = 0;
    int sum = 0;
    while( a1.size() != 0 ){
        int n = a1.back();
        a1.pop_back();
        num1 *= 10;
        num1 += n;
    }
    while( b1.size() != 0 ){
        int n = b1.back();
        b1.pop_back();
        num2 *= 10;
        num2 += n;
    }
    sum = num1+num2;

    list<int> c1;
    while( sum != 0 ){
        c1.push_front((sum%10) + '0');
        sum -= sum%10;
        sum /= 10;
    }

    Node * head = NULL;
    Node * tail = NULL;
    while( c1.size() != 0 ){
        Node * temp = new Node;
        temp->setVal(c1.front());
        temp->setNext(NULL);
        c1.pop_front();
        if( head == NULL ){
            head = temp;
            tail = temp;
        } else {
            tail->setNext(temp);
            tail = tail->getNext();
        }
    }

    return *head;
}

/*
Problem 2.6
Palindrome: Implement a function to check if a linked list is a palindrome.
*/
bool isPalindrome(Node n){
    Node * start;
    start = &n;
    int count = 0;
    while( start != NULL ){
        count++;
        start = start->getNext();
    }

    start = &n;

    list<char> c;
    for( int i = 0; i < count/2; i++ ){
        c.push_back(start->getVal());
        start = start->getNext();
    }
    if( count % 2 != 0 ){
        start = start->getNext();
    }
    bool ret = true;
    for( int i = 0; i < count/2; i++ ){
        if( c.back() != start->getVal() ){
            ret = false;
            break;
        }
        c.pop_back();
        start = start->getNext();
    }
    return ret;
}

/*
Problem 2.7
Intersection: Given two (singly) linked lists, determine if the
two lists intersect. Return the intersecting node. Note that the
intersection is defined based on reference, not value. That is, if
the kth node of the first linked list is the exact same node (by
reference) as the jth node of the second linked list, then they
are intersecting.
*/
Node intersection(Node m, Node n){
    Node * ret = NULL;
    Node * m_front;
    Node * n_front;
    m_front = &m;
    n_front = &n;
    while( m_front != NULL ){
        n_front = &n;
        while( n_front != NULL ){
            if( n_front == m_front ){
                ret = n_front;
                return *ret;
            }
            n_front = n_front->getNext();
        }
        m_front = m_front->getNext();
    }
    return *ret;
}

/*
Problem 2.8
Loop Detection: Given a circular linked list, implement an algorithm that
returns the node at the beginning of the loop.
DEFINITION
Circular linked list: A (corrupt) linked list in which a node's next pointer
points to an earlier node, so as to make a loop in the linked list.
EXAMPLE
Input: A -> B -> C -> D -> E -> C([thesameCasearlier) Output: C
*/
Node loopDetection(Node n){
    Node * n_start = &n;
    Node * ret = NULL;
    map<Node *, bool> map;

    while( n_start != NULL ){
        if( map.find(n_start) != map.end() ){
            ret = n_start;
            break;
        } else {
            map.insert(make_pair(n_start, true));
        }
        n_start = n_start->getNext();
    }
    return *ret;
}
