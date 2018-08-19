#include <iostream>
#include <vector>
using namespace std;

/*
Minimal Tree: Given a sorted (increasing order) array with unique
integer elements, write an algorithm to create a binary search tree
with minimal height.
*/

struct Node{
    int label;
    Node * left;
    Node * right;
    Node(): left(NULL), right(NULL){};
};

Node * MinimalTree( vector<int> subArr);
void printTree(Node * tree);

int main(){
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    vector<int> a(arr, arr+sizeof(arr)/sizeof(int));
    Node * tree = MinimalTree(a);
    printTree(tree);
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
