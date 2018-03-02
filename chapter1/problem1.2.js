/*
Problem 1.2
Check Permutation: Given two strings, write a method
to decide if one is a permutation of the other.
*/

var d = document.getElementById("p1");

d.innerHTML += '<h2>Problem 2</h2>';

var a = "cat";
var b = "act";
d.innerHTML += '<div>String 1: "' + a + '"</div>';
d.innerHTML += '<div>String 2: "' + b + '"</div>';

var permutation = checkPermutation(a,b);
d.innerHTML += '<div>Permutation: ' + permutation + '</div>';



function checkPermutation(str1, str2) {
    str1 = str1.split("").sort().join("");
    str2 = str2.split("").sort().join("");

    if( str1 == str2 ){
        return true;
    }
    else{
        return false;
    }
}