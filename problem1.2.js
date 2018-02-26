/*
Problem 1.2
Check Permutation: Given two strings, write a method
to decide if one is a permutation of the other.
*/
var a = "cat";
a = a.split("").sort().join("");
var b = "act";
b = b.split("").sort().join("");

if( a == b ){
    "permutation";
}
