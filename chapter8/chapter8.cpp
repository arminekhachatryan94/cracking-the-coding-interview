#include <iostream>
using namespace std;
/*
Triple Step: A child is running up a staircase with n steps
and can hop either 1 step, 2 steps, or 3 steps at a time.
Implement a method to count how many possible ways the child
can run up the stairs.
*/
int TripleStep(int n); // recursive

int main() {
    int n = 4;
    cout<<TripleStep(n)<<endl;
}

int TripleStep(int n){
    if( n == 0 || n == 1 ){
        return 1;
    } else if( n == 2 ){
        return 2;
    } else {
        return TripleStep(n-1) + TripleStep(n-2) + TripleStep(n-3);
    }
}

/*
__ __ __ __
____ ____
____ __ __
__ __ ____
__ ____ __
______ __
__ ______
*/