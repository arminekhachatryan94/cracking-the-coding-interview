#include <iostream>
using namespace std;

void mergesort(int * arr, int size);
void recursion(int * arr, int * temp, int left_start, int right_end);
void mergeLeftRight(int * arr, int * temp, int left_start, int right_end);

void print(int * a, int size);

int main(){
    int a[] = {50, 70, 10, 3, 6, 1, 2, 25, 10};
    int * arr = a;
    print(a, 9);
    mergesort(a, 9);
    print(a, 9);
}

void mergesort(int * arr, int size){
    int * temp = new int[size];
    recursion(arr, temp, 0, size-1);
    arr = temp;
}

void recursion(int * arr, int * temp, int left_start, int right_end){
    if( left_start < right_end ){
        int middle = (left_start + right_end)/2;
        recursion(arr, temp, left_start, middle);
        recursion(arr, temp, middle+1, right_end);
        mergeLeftRight(arr, temp, left_start, right_end);
    } else {
        ;
    }
}

void mergeLeftRight(int * arr, int * temp, int left_start, int right_end){
    int left_end = (left_start+right_end)/2;
    int right_start = (left_start+right_end)/2 + 1;
    
    int left = left_start;
    int right = right_start;
    
    for( int index = left_start; index <= right_end; index++ ){
        if( right <= right_end && left <= left_end ){
            if( *(arr+left) < *(arr+right) ){
                *(temp+index) = *(arr+left);
                left++;
            } else {
                *(temp+index) = *(arr+right);
                right++;
            }
        } else if( right <= right_end && left > left_end ){
            *(temp+index) = *(arr+right);
            right++;
        } else if( left <= left_end && right > right_end ){
            *(temp+index) = *(arr+left);
            left++;
        }
    }
    
    for( int i = left_start; i <= right_end; i++ ){
        *(arr+i) = *(temp+i);
    }
}

void print(int * a, int size){
    for( int i = 0; i < size; i++ ){
        cout<<a[i]<<" ";
    }
    cout<<endl;

}
