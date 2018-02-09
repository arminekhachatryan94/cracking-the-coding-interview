/*
Problem 1.4
Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

EXAMPLE
Input: Tact Coa
Output: True (permutations: "taco cat". "atco cta". etc.)
*/

var a = "aaatttbbb";
a = a.split("").sort().join("");
console.log(a);

var b = a[0];
var odds = 0;
var count = 1;

for( var i = 1; i < a.length; i++ ){
    if( i+1 == a.length ){
        if( a[i] != b ){ // last element is odd
            odds++;
        }
        else{
            count++;
        }
        if( count % 2 == 1 ){
            odds++;
        }
    } else{
        if( a[i] == b ){
            count++;
        }
        else{
            if( count % 2 == 1 ){
               odds++;
            }
            b = a[i];
            count = 1;
        }
    }
    console.log("i: " + i + ", a[i]: " + a[i] + " count: " + count);
}

console.log("odds: " + odds);
if( odds > 1 ){
    console.log( "not a permutation of a palindrome" );
}
else {
    console.log( "permutation of a palindrome" );
}