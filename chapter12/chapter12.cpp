#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
Last K Lines: Write a method to print the last K lines of an input file using C++.
*/
void LastKLines(string path, int K);

int main(){
    string path = "12.1_input.txt";
    LastKLines(path, 10);
}

void LastKLines(string path, int K){
    ifstream input(path);
    if( !input ){
        cout<<"Error opening input file"<<endl;
        exit(1);
    } else {
        // count number of lines in input file
        int num_lines = 0;
        string line;
        while (getline(input, line)) {
            num_lines++;
        }

        // go back to beginning of input file
        input.clear();
        input.seekg(0, ios::beg);

        // print last K lines
        int index = 0;
        while (getline(input, line)) {
            if( num_lines <= K || index >= num_lines-K){
                cout<<line<<endl;
            }
            index++;
        }

        input.close();
    }
}
