#include <iostream>
using namespace std;

/*
Reverse String: Implement a function void reverse(char* str)
in C or C++ which reverses a null-terminated string.
*/
void reverseString(char * str);

int main(){
    string s = "Hello World.";
    char * str = new char[s.size()];
    s.copy(str, s.size());
    
    reverseString(str);

    cout<<str<<endl;
}

void reverseString(char * str){
    int size = strlen(str);
    for( int i = 0; i < size/2; i++ ){
        char temp = str[i];
        str[i] = str[size-i-1];
        str[size-i-1] = temp;
    }
}
