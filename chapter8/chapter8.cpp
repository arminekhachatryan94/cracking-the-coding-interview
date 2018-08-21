/*
Magic Index: A magic index in an array A[1. .. n-1] is defined to be an index such that A[ i]
i. Given a sorted array of distinct integers, write a method to find a magic index, if one exists, in array A.
FOLLOW UP
What if the values are not distinct?
*/
#include <iostream>
using namespace std;

int MagicIndex( int * a, int size );
int recurse( int * a, int size, int index );

int main(){
    int arr[] = { 0, 1, 2, 3, 5, 6, 7, 8, 10 };
    int * a = arr;
    cout<<MagicIndex(a, 9)<<endl;
}

int MagicIndex( int * a, int size ){
    if( size == 0 ){
        return -1;
    } else {
        return recurse(a, 0, size-1);
    }
}

int recurse( int * a, int start, int end ){
    if( end < start ){
        return -1;
    }

    int middle = (start+end)/2;

    if( *(a+middle) == middle ){
        cout<<middle<<endl;
        return middle;
    } else if( *(a+middle) > middle ){
        return recurse(a, start, middle-1);
    } else {
        return recurse(a, middle+1, end);
    }
}
