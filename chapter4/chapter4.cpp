#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int label;
    Node * left;
    Node * right;
    Node(): left(NULL), right(NULL){};
};

Node * MinimalTree( vector<int> subArr);

int main(){
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    vector<int> a(arr, arr+sizeof(arr)/sizeof(int));
    Node * tree = MinimalTree(a);
}

Node * MinimalTree( vector<int> subArr){
    int size = subArr.size();
    Node * tree;
    tree = new Node;
    tree->label = subArr[size/2];

    vector<int> left(subArr.begin(), subArr.begin() + size/2);
    vector<int> right(subArr.begin() + size/2 + 1, subArr.begin() + size);
    if( left.size() > 0 ){
        tree->left = new Node;
        tree->left = MinimalTree(left);
    } else {
        tree->left = NULL;
    }
    if( right.size() > 0 ){
        tree->right = new Node;
        tree->right = MinimalTree(right);
    } else {
        tree->right = NULL;
    }

    return tree;
}
