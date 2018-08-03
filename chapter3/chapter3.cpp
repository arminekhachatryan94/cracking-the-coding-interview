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
        char capacity;
        int * sizes;
};

int main() {
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
