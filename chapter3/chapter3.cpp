#include <iostream>
#include <string>

using namespace std;

/*
Problem 3.1
Three in One: Describe how you could use a single array to implement three stacks.
*/
const int num_stacks = 3;
class TripleStack {
    public:
        TripleStack(int size);
        ~TripleStack();
        int push(int stack, char c);
        int pop(int stack);
        char top(int stack);
        int size(int stack);
        void printStack(int stack);
        void printStacks();
    private:
        char * stacks;
        int capacity;
        int * sizes;
};

/*
Problem 3.2
Stack Min: How would you design a stack which, in addition to push and pop, has a function min
which returns the minimum element? Push, pop and min should all operate in 0(1) time.
*/
class StackMin {
    public:
        StackMin(int size);
        ~StackMin();
        int push(int n);
        int pop();
        int top();
        int size();
        int min();
        void printStack();
    private:
        int * stack;
        int capacity;
        int stack_size;
        int minimum;
};

/*
Problem 3.3
Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
Therefore, in real life, we would likely start a new stack when the previous stack exceeds some
threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed
of several stacks and should create a new stack once the previous one exceeds capacity. SetOfStacks.push()
and SetOfStacks.pop() should behave identically to a single stack (that is, pop() should return the same
values as it would if there were just a single stack).
FOLLOW UP
Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.
*/
class Stack {
    public:
        Stack();
        Stack(int capacity);
        ~Stack();
        void setCapacity(int capacity);
        int push(char n);
        int pop();
        char top();
        int size();
        char removeBottom();
        void print();
    private:
        char * stack;
        int capacity;
        int stack_size;
        char bottom;
};
class SetOfStacks {
    public:
        SetOfStacks(char capacity); // capacity of a single stack
        ~SetOfStacks();
        int push(char n);
        int pop();
        char top();
        int size(int stack);
        int numStacks();
        int popAt(int stack);
        void addStack();
        void deleteStack(int stack);
        void leftShift(int stack);
        void printStacks();
    private:
        Stack * stacks;
        int capacity;
        int num_stacks;
};

/*
Problem 3.4
Queue via Stacks: Implement a MyQueue class which implements a queue using two stacks.
*/
class MyQueue {
    public:
        MyQueue(int capacity);
        ~MyQueue();
        int empty();
        char peek();
        int enqueue(char c);
        char dequeue();
        int size();
        void print();
    private:
        Stack stack1; // top is front of queue
        Stack stack2; // top is back of queue
        int capacity;
};

/*
Problem 3.5
Sort Stack: Write a program to sort a stack such that the smallest items are on the top.
You can use an additional temporary stack, but you may not copy the elements into any other
data structure (such as an array).The stack supports the following operations: push, pop,
peek, and isEmpty.
*/
class IntStack {
    public:
        IntStack();
        IntStack(int capacity);
        ~IntStack();
        void setCapacity(int capacity);
        int push(int n);
        int pop();
        int top();
        int size();
        void print();
    private:
        int * stack;
        int capacity;
        int stack_size;
};
class SortStack{
    public:
        SortStack(int capacity);
        ~SortStack();
        int push(int c);
        int pop();
        int peek();
        bool isEmpty();
        void print();
    private:
        IntStack s1;
        int capacity;
};

void ColorText( int color, string text );

int main() {
    // 3.1: Three in One
    ColorText(34, "3.1 - Three in One:"); cout<<endl;
    TripleStack stack(3);
    stack.push(3, '1');
    stack.push(3, '2');
    stack.push(3, '3');
    stack.push(1, 'a');
    stack.push(1, 'b');
    stack.push(1, 'c');
    stack.push(1, 'd');
    stack.push(2, '5');
    stack.push(2, '7');
    stack.push(2, '9');
    stack.printStacks();
    cout<<stack.top(1)<<endl;
    stack.pop(1);
    stack.pop(2);
    stack.pop(3);
    stack.printStacks();

    cout<<endl<<endl;

    // 3.2: Stack Min
    ColorText(34, "3.2 - Stack Min:"); cout<<endl;
    StackMin m(5);
    if( m.min() == '\0' ){
        cout<<"NULL"<<endl;
    } else {
        cout<<m.min()<<endl;
    }
    if( m.top() == '\0' ){
        cout<<"top: NULL"<<endl;
    } else{
        cout<<"top: "<<m.top()<<endl;
    }
    m.push(5);
    cout<<"top: "<<m.top()<<endl;
    m.push(4);
    cout<<"tpp: "<<m.top()<<endl;
    m.push(3);
    cout<<"top: "<<m.top()<<endl;
    m.push(2);
    cout<<"top: "<<m.top()<<endl;
    m.push(1);
    cout<<"top: "<<m.top()<<endl;
    cout<<"min: "<<m.min()<<endl;
    m.pop();
    cout<<"min: "<<m.min()<<endl;
    m.pop();
    cout<<"min: "<<m.min()<<endl;
    m.pop();
    cout<<"min: "<<m.min()<<endl;
    m.pop();
    cout<<"min: "<<m.min()<<endl;
    m.pop();
    if( m.min() == '\0' ){
        cout<<"min: NULL"<<endl;
    } else {
        cout<<"min: "<<m.min()<<endl;
    }
    ColorText(33, "Stack: ");
    m.printStack();

    cout<<endl<<endl;
   
    // 3.3: Stack of Plates
    ColorText(34, "3.3 - Stack of Plates:"); cout<<endl;
    SetOfStacks s(5);
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');
    s.push('f');
    s.pop();
    s.pop();
    s.push('z');
    s.push('g');
    s.push('h');
    s.push('i');
    s.push('j');
    s.push('k');
    s.push('q');
    cout<<"top: "<<s.top()<<endl;
    s.printStacks();
    s.popAt(0);
    cout<<endl;
    s.printStacks();
    s.popAt(0);
    cout<<endl;
    s.printStacks();
    s.popAt(0);
    cout<<endl;
    s.printStacks();

    cout<<endl<<endl;

    // 3.4: Queue via Stacks
    ColorText(34, "3.4 - Queue via Stacks:"); cout<<endl;
    MyQueue q(6);
    q.enqueue('a');
    cout<<"top: "<<q.peek()<<endl;
    q.print();
    q.enqueue('b');
    cout<<"top: "<<q.peek()<<endl;
    q.print();
    q.enqueue('c');
    cout<<"top: "<<q.peek()<<endl;
    q.print();
    q.dequeue();
    cout<<"top: "<<q.peek()<<endl;
    q.print();

    cout<<endl<<endl;

    // 3.5: Sort Stack
    ColorText(34, "3.5 - Sort Stack:"); cout<<endl;
    SortStack t(5);
    t.push(1);
    t.print();
    t.push(5);
    t.print();
    t.push(5);
    t.print();
    t.push(2);
    t.print();
    t.push(10);
    t.print();
    cout<<"top: "<<t.peek()<<endl;
    cout<<"isEmpty: "<<t.isEmpty()<<endl;
    t.pop();
    t.print();
    t.pop();
    t.print();
    t.pop();
    t.print();
    t.pop();
    t.print();
    cout<<"isEmpty: "<<t.isEmpty()<<endl;
}

/*
Colors  | Text  | Background
------------------------------
Black   |   30  |   40
Red     |   31  |   41
Green   |   32  |   42
Yellow  |   33  |   43
Blue    |   34  |   44
Magenta |   35  |   45
Cyan    |   36  |   46
White   |   37  |   47
*/
void ColorText( int color, string text ){
    cout<<"\033[1;"<<color<<"m"<<text<<"\033[0m";
}

/* TripleStack constructor, destructor, and member function definitions */

TripleStack::TripleStack(int size){
    this->capacity = size;
    stacks = new char[size*num_stacks];
    sizes = new int[3];
    for( int i = 0; i < num_stacks; i++ ){
        *(sizes+i) = 0;
    }
    for( int i = 0; i < size*num_stacks; i++ ){
        *(stacks+i) = -1;
    }
}

TripleStack::~TripleStack(){
    delete stacks;
    delete sizes;
}

int TripleStack::push(int stack, char c){
    int size = this->size(stack);
    if( stack <= num_stacks ){
        if( size < this->capacity ){
            *(stacks+((stack-1)*num_stacks)+size) = c;
            *(sizes+stack-1) += 1;
            return 1;
        } else {
            return -1; // stack is full
        }
    } else {
        return 0; // stack number doesn't exist
    }
}

int TripleStack::pop(int stack){
    int size = this->size(stack);
    if( size == 0 ){
        return -1; // stack is empty
    } else {
        *(stacks+((stack-1)*num_stacks)+size-1) = -1;
        *(sizes+stack-1) -= 1;
        return 1;
    }
}

char TripleStack::top(int stack){
    int size = this->size(stack);
    if( size == 0 ){
        return -1; // stack is empty
    } else {
        return *(stacks+((stack-1)*num_stacks)+size-1);
    }
}

int TripleStack::size(int stack){
    return *(sizes+stack-1);
}

void TripleStack::printStack(int stack){
    int start = capacity*(stack-1);
    for( int i = start; i < start+capacity; i++ ){
        if( *(stacks+i) != -1 ){
            cout<<*(stacks+i)<<" ";
        }
    }
}

void TripleStack::printStacks(){
    // cout<<"Stack 1: ";
    ColorText(33, "Stack 1: ");
    printStack(1);
    cout<<endl;

    ColorText(33, "Stack 2: ");
    printStack(2);
    cout<<endl;

    ColorText(33, "Stack 3: ");
    printStack(3);
    cout<<endl;
}

/* StackMin constructor, destructor, and member function definitions */

StackMin::StackMin(int size){
    this->capacity = size;
    this->stack_size = 0;
    this->minimum = -1;
    stack = new int[size];
    for( int i = 0; i < size; i++ ){
        *(stack+i) = '\0';
    }
}

StackMin::~StackMin(){
    delete stack;
    this->stack_size = 0;
    this->capacity = 0;
    this->minimum = '\0';
}

int StackMin::push(int n){
    if( this->size() < this->capacity ){
        *(stack+stack_size) = n;
        this->stack_size++;
        if( this->stack_size == 1 || n < this->minimum ){ // n is either the first element or it is less than the min
            this->minimum = n;
        }
        return 1; // successfully pushed n to the stack
    } else {
        return -1; // stack overflow
    }
}

int StackMin::pop(){
    if( this->size() > 0 ){ // if stack isn't empty
        int val = this->top();
        if( val == this->min() ){ // if value being popped is the min
            if( this->size() == 1 ){ // if value being popped is the last item on the stack
                this->minimum = '\0'; // new min is null because stack will be empty after item is popped
            } else { // if stack has more than 1 item, find the new min
                int new_min = *stack;
                for( int i = 1; i < this->size()-1; i++ ){
                    if( *(stack+i) < new_min ){
                        new_min = *(stack+i);
                    }
                }
                this->minimum = new_min;
            }
        }
        *(stack+this->size()-1) = '\0';
        this->stack_size--;
        return 1; // successfully popped and found new min
    } else { // stack is empty
        return '\0';
    }
}

int StackMin::top(){
    if( this->size() == 0 ){ // if stack is empty
        return '\0';
    } else {
        return *(stack+stack_size-1);
    }
}

int StackMin::size(){
    return this->stack_size;
}

int StackMin::min(){
    if( this->size() == 0 ){ // if stack is empty
        return '\0';
    } else {
        return this->minimum;
    }
}

void StackMin::printStack(){
    for( int i = 0; i < this->stack_size; i++ ){
        cout<<*(stack+i)<<" ";
    }
}

/* Stack constructor, destructor, and member function definitions */

Stack::Stack(){
    this->capacity = 0;
    this->stack_size = 0;
    this->bottom = '\0';
}

Stack::Stack(int capacity){
    stack = new char[capacity];
    this->capacity = capacity;
    this->stack_size = 0;
    for( int i = 0; i < capacity; i++ ){
        *(stack+i) = '\0';
    }
    this->bottom = '\0';
}

Stack::~Stack(){
    delete stack;
    this->capacity = 0;
    this->stack_size = 0;
    this->bottom = '\0';
}

void Stack::setCapacity(int capacity){
    stack = new char[capacity];
    this->capacity = capacity;
    this->stack_size = 0;
    for( int i = 0; i < capacity; i++ ){
        *(stack+i) = '\0';
    }
}

int Stack::push(char n){
    if( this->size() < this->capacity ){
        *(stack+this->size()) = n;
        this->stack_size++;
        if( this->size() == 1 ){
            this->bottom = n;
        }
        return 1;
    } else {
        return -1; // stack overflow
    }
}

int Stack::pop(){
    if( this->size() != 0 ){
        *(stack+this->size()-1) = '\0';
        this->stack_size--;
        if( this->size() == 0 ){
            this->bottom = '\0';
        }
        return 1;
    } else {
        return -1; // stack is empty
    }
}

char Stack::top(){
    if( this->size() != 0 ){
        return *(stack+this->size()-1);
    } else {
        return '\0'; // stack is empty
    }
}

int Stack::size(){
    return this->stack_size;
}

char Stack::removeBottom(){
    if( this->size() == 0 ){
        return '\0';
    }
    char ret = this->bottom;
    for( int i = 1; i < this->size()+1; i++ ){
        *(stack+i-1) = *(stack+i);
    }
    *(stack+this->size()-1) = '\0';
    this->stack_size--;
    this->bottom = *(stack+0);
    return ret;
}

void Stack::print(){
    for( int i = 0; i < this->size(); i++ ){
        cout<<*(stack+i)<<" ";
    }
}

/* SetOfStacks constructor, destructor, and member function definitions */

SetOfStacks::SetOfStacks(char capacity){
    stacks = new Stack[1];
    (*(stacks+0)).setCapacity(capacity);
    this->capacity = capacity;
    this->num_stacks = 1;
}

SetOfStacks::~SetOfStacks(){
    delete [] stacks;
}

int SetOfStacks::push(char n){
    int _size = this->size(this->numStacks()-1);
    if( _size == this->capacity ){
        // add an empty stack to the set
        this->addStack();
    }
    // push to stack
    return (*(stacks+(this->numStacks()-1))).push(n);
}

int SetOfStacks::pop(){
    if( this->numStacks() == 0 ){ // no set of stacks
        return '\0';
    } else if( this->numStacks() == 1 && this->size(this->numStacks()-1) == 0 ){ // first and only stack on the set is empty
        return '\0';
    } else if( this->size(this->numStacks()-1) == 0 ){ // last stack on set is empty
        this->deleteStack(this->numStacks()-1);
    }
    
    return (*(stacks+this->numStacks()-1)).pop();
}

char SetOfStacks::top(){
    if( this->size(this->numStacks()-1) != 0 ){
        return (*(stacks+this->numStacks()-1)).top();
    } else { // last stack on the set is empty
        return '\0';
    }
}

int SetOfStacks::size(int stack){
    if( stack < this->capacity ){
        return (*(stacks+stack)).size();
    } else {
        return -1; // stack doesn't exist
    }
}

int SetOfStacks::numStacks(){
    return this->num_stacks;
}

int SetOfStacks::popAt(int stack){
    if( this->size(stack) == 0 ){
        return '\0';
    } else {
        // commented code below is an approach that
        // deletes stack if empty, but doesn't left shift
        // so, not every stack is guaranteed to be full
        /*
        int ret = (*(stacks+stack)).pop();
        if( this->size(stack) == 0 ){ // if this stack is empty, delete it from the set
            this->deleteStack(stack);
        }
        return ret;
        */
        
        // code below left shifts when an element is popped
        // every stack except the last one on the set is guaranteed to be full
        int ret = (*(stacks+stack)).pop();
        this->leftShift(stack);
        return ret;
    }
}

void SetOfStacks::addStack(){
    Stack * temp = new Stack[(this->numStacks()+1)];
    for( int i = 0; i < this->numStacks(); i++ ){
        *(temp+i) = *(stacks+i);
    }
    stacks = temp;
    this->num_stacks++;
    (*(stacks+(this->numStacks()-1))).setCapacity(this->capacity);
}

void SetOfStacks::deleteStack(int stack){
    Stack * temp = new Stack[(this->numStacks()-1)];
    for( int i = 0; i < this->numStacks(); i++ ){
        if( i < stack ){
            *(temp+i) = *(stacks+i);
        } else if( i > stack ){
            *(temp+i-1) = *(stacks+i);
        }
    }
    this->num_stacks--;
    stacks = temp;
}

void SetOfStacks::leftShift(int stack){
    for( int i = stack+1; i < this->numStacks(); i++ ){
        char bottom = (*(stacks+i)).removeBottom();
        (*(stacks+i-1)).push(bottom);
    }
    if( (*(stacks+this->numStacks()-1)).size() == 0 ){
        this->deleteStack(this->numStacks()-1);
    }
}

void SetOfStacks::printStacks(){
    for( int i = 0; i < this->numStacks(); i++ ){
        // cout<<"stack "<<i<<": ";
        ColorText(33, "Stack " + string(1, i+'0') + ": ");
        (*(stacks+i)).print();
        cout<<endl;
    }
}

/* MyQueue constructor, destructor, and member function definitions */

MyQueue::MyQueue(int capacity){
    this->capacity = capacity;
    this->stack1.setCapacity(capacity);
    this->stack2.setCapacity(capacity);
}

MyQueue::~MyQueue(){
    this->capacity = 0;
}

int MyQueue::empty(){
    if( this->stack1.size() == 0 && this->stack2.size() == 0 ){
        return true;
    }
    return false;
}

char MyQueue::peek(){
    if( this->empty() ){ // queue is empty
        return '\0';
    } else { // top of stack1 is front of queue
        if( this->stack2.size() > this->stack1.size() ){ // set stack1 if not already set
            while( this->stack2.top() != '\0' ){
                this->stack1.push(this->stack2.top());
                this->stack2.pop();
            }
        }
        return this->stack1.top();
    }
}

int MyQueue::enqueue(char c){
    if( this->size() == this->capacity ){ // queue overflow
        return '\0';
    } else { // top of stack2 is back of queue
        if( this->stack1.size() > this->stack2.size() ){ // set stack2 if not already set
            while( this->stack1.top() != '\0' ){
                this->stack2.push(this->stack1.top());
                this->stack1.pop();
            }
        }
        return this->stack2.push(c);
    }
}

char MyQueue::dequeue(){
    if( this->size() == this->capacity ){ // queue overflow
        return '\0';
    } else { // top of stack1 is front of queue
        if( this->stack2.size() > this->stack1.size() ){ // set stack1 if not already set
            while( this->stack2.top() != '\0' ){
                this->stack1.push(this->stack2.top());
                this->stack2.pop();
            }
        }
        return this->stack1.pop();
    }
}

int MyQueue::size(){
    if( this->stack1.size() > this->stack2.size() ){ // stack1 is set & not empty
        return this->stack1.size();
    } else if( this->stack2.size() > this->stack1.size() ){ // stack2 is set & not empty
        return this->stack2.size();
    } else { // both stacks are empty
        return 0;
    }
}

void MyQueue::print(){
    ColorText(33, "Queue: ");
    if( this->stack1.size() > this->stack2.size() ){ // set stack2 if not already set
        while( this->stack1.top() != '\0' ){
            this->stack2.push(this->stack1.top());
            this->stack1.pop();
        }
    }
    cout<<"<-[ ";
    this->stack2.print();
    cout<<"]<-"<<endl;
}

/* IntStack constructor, destructor, and member function definitions */

IntStack::IntStack(){
    this->capacity = 0;
    this->stack_size = 0;
}

IntStack::IntStack(int capacity){
    stack = new int[capacity];
    this->capacity = capacity;
    this->stack_size = 0;
    for( int i = 0; i < capacity; i++ ){
        *(stack+i) = '\0';
    }
}

IntStack::~IntStack(){
    delete stack;
    this->capacity = 0;
    this->stack_size = 0;
}

void IntStack::setCapacity(int capacity){
    stack = new int[capacity];
    this->capacity = capacity;
    this->stack_size = 0;
    for( int i = 0; i < capacity; i++ ){
        *(stack+i) = '\0';
    }
}

int IntStack::push(int n){
    if( this->size() < this->capacity ){
        *(stack+this->size()) = n;
        this->stack_size++;
        return 1;
    } else {
        return -1; // stack overflow
    }
}

int IntStack::pop(){
    if( this->size() != 0 ){
        *(stack+this->size()-1) = '\0';
        this->stack_size--;
        return 1;
    } else {
        return -1; // stack is empty
    }
}

int IntStack::top(){
    if( this->size() != 0 ){
        return *(stack+this->size()-1);
    } else {
        return '\0'; // stack is empty
    }
}

int IntStack::size(){
    return this->stack_size;
}

void IntStack::print(){
    for( int i = 0; i < this->size(); i++ ){
        cout<<*(stack+i)<<" ";
    }
}

/* SortStack constructor, destructor, and member function definitions */

SortStack::SortStack(int capacity){
    this->capacity = capacity;
    this->s1.setCapacity(capacity);
}

SortStack::~SortStack(){
    this->capacity = 0;
    this->s1.setCapacity(0);
}

int SortStack::push(int c){
    if( this->s1.size() == this->capacity ){
        return -1;
    } else {
        IntStack temp(this->capacity);
        while( this->s1.top() <= c && this->s1.size() != 0 ){
            temp.push(this->s1.top());
            this->s1.pop();
        }
        s1.push(c);
        while( temp.size() != 0 ){
            this->s1.push(temp.top());
            temp.pop();
        }
        return 1;
    }
} // 4 3 3 1

int SortStack::pop(){
    return this->s1.pop();
}

int SortStack::peek(){
    return this->s1.pop();
}

bool SortStack::isEmpty(){
    if( this->s1.size() == 0 ){
        return true;
    }
    return false;
}

void SortStack::print(){
    ColorText(33, "Sorted Stack: ");
    this->s1.print();
    cout<<endl;
}