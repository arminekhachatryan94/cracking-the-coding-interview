/*
Power Set: Write a method to return all subsets of a set.
*/

#include <iostream>
#include <vector>
using namespace std;

vector< vector<char> > PowerSet( vector<char> v );

int main() {
    cout<<"hi";
    vector<char> p;
    p.push_back('a');
    p.push_back('b');
    p.push_back('c');

    
    vector< vector<char> > power = PowerSet(p);
    for( int i = 0; i < power.size(); i++ ){
        cout<<"( ";
        for( int j = 0; j < power[i].size(); j++ ){
            cout<<power[i][j]<<" ";
        }
        cout<<")"<<endl;
    }
}


vector< vector<char> > PowerSet( vector<char> v ){
    vector< vector<char> > s;
    // empty set
    vector<char> empty;
    s.push_back(empty);

    for( int i = 0; i < v.size(); i++ ){
        for( int j = 0; j < s.size(); j++ ){
            vector<char> temp_set = s[j];
            temp_set.push_back(v[i]);
            s.push_back(temp_set);
        }
    }
    return s;
}
