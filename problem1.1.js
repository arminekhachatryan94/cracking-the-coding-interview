/*
Problem 1.1
Is Unique: Implement an algorithm to determine
if a string has all unique characters. What if you
cannot use additional data structures?
*/

var str = "armine kh12;";

str = str.split("").sort().join("");

var unique = true;
for( var i = 1; i < str.length; i++ ){
    if(str[i-1] == str[i]){
        unique = false;
        break;
    }
}

console.log("uniqueness: " + unique);

