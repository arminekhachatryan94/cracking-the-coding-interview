#include <iostream>
using namespace std;

void quicksort(int * arr, int size);
void recursion( int * arr, int left, int right);
int partition(int * arr, int left, int right, int pivot);

void print(int * a, int size);

int main(){
    int arr[] = {15, 3, 2, 1, 9, 5, 7, 8, 6};
    int * a = arr;
    int * p = new int[9];
    for( int i = 0; i < 9; i++ ){
        *(p+i) = *(a+i);
    }
    cout<<"quick sort"<<endl;
    print(a, 9);
    quicksort(a, 9);
    print(a, 9);

    cout<<"c++ sort"<<endl;
    print(p, 9);
    sort(p, p + 9);
    print(p, 9);
}

void quicksort(int * arr, int size){
    recursion(arr, 0, size-1);
}
/*
void recursion( int * arr, int left, int right){
    if( left < right ){
        int pivot = (left+right)/2;
        cout<<"pivot: "<<*(arr+pivot)<<endl;
        int l = left;
        int r = right;
        while( l+1 < r ){
            if( *(arr+l) < *(arr+pivot) ){
                l++;
            }
            if( *(arr+r) > *(arr+pivot) ){
                r--;
            }
            if( *(arr+l) >= *(arr+pivot) && *(arr+r) <= *(arr+pivot) ){
                int temp = *(arr+l);
                *(arr+l) = *(arr+r);
                *(arr+r) = temp;
                l++;
                r--;
                print(arr, right-left+1);
            }
        }
        
        int middle = (left+right)/2;
        recursion(arr, left, middle);
        recursion(arr, middle+1, right);
    }
}
*/

void recursion(int * arr, int left, int right){
    if( left >= right ){
        return;
    }
    int pivot = *(arr+((left+right)/2));
    int middle = partition(arr, left, right, pivot);
    recursion(arr, left, middle-1);
    recursion(arr, middle, right);
}

int partition(int * arr, int left, int right, int pivot){
    while( left <= right ){
        while( *(arr+left) < pivot ){
            left++;
        }
        while( *(arr+right) > pivot ){
            right--;
        }
        if( left <= right ){
            int temp = *(arr+left);
            *(arr+left) = *(arr+right);
            *(arr+right) = temp;
            left++;
            right--;
        }
    }
    return left;
}

void print(int * a, int size){
    for( int i = 0; i < size; i++ ){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}