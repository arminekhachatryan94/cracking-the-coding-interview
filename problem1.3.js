/*
Problem 1.3
URLify: Write a method to replace all spaces
in a string with '%20: You may assume that the string
has sufficient space at the end to hold the additional
characters, and that you are given the "true" length of
the string. (Note: If implementing in Java, please use a
character array so that you can perform this operation
in place.)

EXAMPLE
Input: "Mr John Smith "J 13
Output: "Mr%20J ohn%20Smith"
*/
var str = "Mr John Smith    ";
var len = 13;
var output = str.substr(0, len).split(' ').join('%20');
console.log(output);