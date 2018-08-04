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

int main() {
    // 3.1: Three in One
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

    // 3.2: Stack Min
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
    cout<<"stack: ";
    m.printStack();
}

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
    cout<<"Stack 1: ";
    printStack(1);
    cout<<endl;

    cout<<"Stack 2: ";
    printStack(2);
    cout<<endl;

    cout<<"Stack 3: ";
    printStack(3);
    cout<<endl;
}

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
