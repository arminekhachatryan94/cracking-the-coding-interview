#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*
List of Depths: Given a binary tree, design an algorithm which creates
a linked list of all the nodes at each depth (e.g., if you have a tree
with depth D, you'll have Dlinked lists).
*/

struct Node{
    int label;
    Node * left;
    Node * right;
    Node(): left(NULL), right(NULL){};
};

Node * MinimalTree(vector<int> subArr);
list<Node> * ListOfDepths(Node * tree, int & length);
void Traverse(Node * tree, list<Node> * & depths, int depth, int & length);
void printList(list<Node> * depths, int length);

int main(){
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    vector<int> a(arr, arr+sizeof(arr)/sizeof(int));
    Node * tree = MinimalTree(a);

    int length = 0;
    list<Node> * d = ListOfDepths(tree, length);

    printList(d, length);
}

Node * MinimalTree(vector<int> subArr){
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

list<Node> * ListOfDepths(Node * tree, int & length){
    int depth = 0;
    list<Node> * DList;
    Traverse(tree, DList, depth, length);
    return DList;
}

void Traverse(Node * tree, list<Node> * & depths, int depth, int & length){
    if( tree != NULL ){
        if( length <= depth ){
            list<Node> * temp = new list<Node>[depth+1];
            for( int i = 0; i < length; i++ ){
                temp[i] = depths[i];
            }
            depths = temp;
            length = depth+1;
        }
        (*(depths+depth)).push_back(*tree);
        Traverse(tree->left, depths, depth+1, length);
        Traverse(tree->right, depths, depth+1, length);
    }
}

void printList(list<Node> * depths, int length){
    for( int i = 0; i < length; i++ ){
        cout<<"depth "<<i<<": ";
        for( int j = 0; j < (*(depths+i)).size(); j++ ){
            cout<<(*(depths+i)).front().label<<" ";
            (*(depths+i)).push_back((*(depths+i)).front());
            (*(depths+i)).pop_front();
        }
        cout<<endl;
    }
}
