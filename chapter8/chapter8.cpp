/*
Problem 8.7
Permutations without Dups: Write a method to compute
all permutations of a string of unique characters.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct MyComparison{
    bool operator()( string s1, string s2 ) {
        if(s1.length() == s2.length()){
            int count = 0;
            for( int i = 0; i < s1.length(); i++ ){
                if(s1[i] != s2[i]) {
                    return s1[i] > s2[i];
                } else {
                    count++;
                }
            }
            return s1.length() == s2.length();
        }
        else
            return s1.length() > s2.length();
    }
};

priority_queue< string, vector< string >, MyComparison > Permutation( string str );
void getPerms(string prefix, string remainder, priority_queue< string, vector< string >, MyComparison > & ret);

int main() {
    string p = "abc";

    priority_queue< string, vector< string >, MyComparison > perms = Permutation(p);
    
    while( perms.size() > 0 ){
        cout<<perms.top()<<" ";
        perms.pop();
    }
    cout<<endl;
}

priority_queue< string, vector< string >, MyComparison > Permutation( string str ){
    priority_queue< string, vector< string >, MyComparison > ret;
    
    getPerms("", str, ret);

    return ret;
}

void getPerms(string prefix, string remainder, priority_queue< string, vector< string >, MyComparison > & ret){
    int len = remainder.length();

    if( len == 0 ){
        ret.push(prefix);
    }
    
    for( int i = 0; i < len; i++ ){
        string before = remainder.substr(0, i);
        string after = remainder.substr(i+1, len);
        char c = remainder[i];
        getPerms(prefix + c, before + after, ret);
    }
}
