/*
Problem 1.4
Palindrome Permutation: Given a string, write a
function to check if it is a permutation of a palindrome.
A palindrome is a word or phrase that is the same forwards
and backwards. A permutation is a rearrangement of letters.
The palindrome does not need to be limited to just dictionary words.

EXAMPLE
Input: Tact Coa
Output: True (permutations: "taco cat". "atco cta". etc.)
*/

var d = document.getElementById("p4");
d.innerHTML += '<h2>Problem 4</h2>';

var a = "aaatttbbb";
d.innerHTML += '<div>String: "' + a + '"</div>';

var result = palindromePermutation(a);
d.innerHTML += '<div>Permutation of a Palindrome: ' + result + '</div>';



function palindromePermutation(str){    
    str = str.split("").sort().join("");
    // console.log(str);

    var b = str[0];
    var odds = 0;
    var count = 1;

    for( var i = 1; i < a.length; i++ ){
        if( i+1 == str.length ){
            if( str[i] != b ){ // last element is odd
                odds++;
            }
            else{
                count++;
            }
            if( count % 2 == 1 ){
                odds++;
            }
        } else{
            if( str[i] == b ){
                count++;
            }
            else{
                if( count % 2 == 1 ){
                   odds++;
                }
                b = str[i];
                count = 1;
            }
        }
        // console.log("i: " + i + ", a[i]: " + a[i] + " count: " + count);
    }

    // console.log("odds: " + odds);
    if( odds > 1 ){
        return false; // not palindrome
    }
    else {
        return true; // palindrome
    }
}