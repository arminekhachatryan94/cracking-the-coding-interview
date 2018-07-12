#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

bool isUnique( string str );
bool checkPermutation( string & s1, string & s2 );

int main (){
    cout<<endl;
    string s = "qwertyuo";
    cout<<"Solution 1.1"<<endl;
    cout<<s<<": "<<(isUnique(s)?"true":"false")<<endl<<endl;

    string s1 = "bar";
    string s2 = "tab";
    cout<<"Solution 1.2"<<endl;
    cout<<s1<<" "<<s2<<": "<<(checkPermutation(s1, s2)?"true":"false")<<endl<<endl;

    cout<<"Solution 1.3"<<endl;
}

/*
Problem 1.1
Is Unique: Implement an algorithm to determine
if a string has all unique characters. What if you
cannot use additional data structures?
*/
bool isUnique( string str ){
    /*
    0-127: standard ascii chars
    128-255: extended ascii chars
    */
    if( str.length() > 128 ){
        return false;
    } else {
        bool exists[128];
        for( int i = 0; i < str.length(); i++ ){
            int val = (int)str[i];
            if( exists[val] == true ){
                return false;
            } else {
                exists[val] = true;
            }
        }
        return true;
    }
}

/*
Problem 1.2
Check Permutation: Given two strings, write a method
to decide if one is a permutation of the other.
*/
bool checkPermutation( string & s1, string & s2 ){
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if( s1 == s2 ){
        return true;
    } else {
        return false;
    }
}
