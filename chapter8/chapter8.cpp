/*
Problem 8.5
Recursive Multiply: Write a recursive function to multiply two
positive integers without using the * operator (or / operator).
You can use addition, subtraction, and bit shifting, but you
should minimize the number of those operations.
*/

#include <iostream>
using namespace std;

int multiply(int x, int y);
// int recursion( int factor, int round );
int recursion(int min, int max);

int main() {
    cout<<multiply(10, 10)<<endl;
}

int multiply(int x, int y){
    int min;
    int max;
    if( abs(x) < abs(y) ){ // use x;
        min = abs(x);
        max = abs(y);
    } else {
        min = abs(y);
        max = abs(x);
    }
    
    // int product = recursion(max, min);
    int product = recursion(min, max);

    /* if negative numbers */
    if( (x < 0 && y > 0) || (x > 0 && y < 0) ){
        product = 0 - product;
    }
    return product;
}

/*
int recursion( int factor, int round ){
    if( round == 1 ){
        return factor;
    } else {
        return factor + recursion(factor, --round);
    }
}
*/

int recursion(int min, int max){
    if( min == 0 ){
        return 0;
    } else if( min == 1 ){
        return max;
    }

    int s = min >> 1;
    int half = recursion(s, max); // half product

    if( min % 2 == 0 ){
        return half + half;
    } else {
        return half + half + max;
    }
}
