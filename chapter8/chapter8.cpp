/*
Problem 8.4
Power Set: Write a method to return all subsets of a set.
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct MyComparison{
    bool operator()( vector<char> v1, vector<char> v2 ) {
        if(v1.size() == v2.size()){
            int count = 0;
            for( int i = 0; i < v1.size(); i++ ){
                if(v1[i] != v2[i]) {
                    return v1[i] > v2[i];
                } else {
                    count++;
                }
            }
            return v1.size() == v2.size();
        }
        else
            return v1.size() > v2.size();
    }
};


priority_queue< vector<char>, vector< vector<char> >, MyComparison > Permutation( vector<char> v );

int main() {
    vector<char> p;
    p.push_back('a');
    p.push_back('b');
    p.push_back('c');

    priority_queue< vector<char>, vector< vector<char> >, MyComparison > power = Permutation(p);

    while( power.size() > 0 ){
        cout<<"( ";
        for( int i = 0; i < power.top().size(); i++ ){
            cout<<power.top()[i]<<" ";
        }
        cout<<")"<<endl;
        power.pop();
    }
    
}

priority_queue< vector<char>, vector< vector<char> >, MyComparison > Permutation( vector<char> v ){
    priority_queue< vector<char>, vector< vector<char> >, MyComparison > q;
    vector< vector<char> > s;
    // empty set
    vector<char> empty;
    s.push_back(empty);

    for( int i = 0; i < v.size(); i++ ){
        int size = s.size();
        for( int j = 0; j < size; j++ ){
            vector<char> temp_set = s[j];
            temp_set.push_back(v[i]);
            s.push_back(temp_set);
            q.push(temp_set);
        }
    }
    return q;
}
