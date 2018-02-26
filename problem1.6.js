/*
Problem 1.6
String Compression: Implement a method to perform
basic string compression using the counts of repeated
characters.
For example, the string aabcccccaaa would become a2b1c5a3.
If the "compressed" string would not become smaller than
the original string, your method should return the original
string. You can assume the string has only uppercase and
lowercase letters (a - z).
*/

var str = "aabcccccaaa";
var compressed = compressedString(str);
console.log(str);
console.log(compressed);

var str2 = "ABC";
var compressed2 = compressedString(str2);
console.log(str2);
console.log(compressed2);

function compressedString ( strn ) {

    var compressed = "";

    var letter = str[0];
    var count = 1;
    for( var i = 1; i < str.length; i++ ){
        if( str[i] == letter ){
            count++;
        }
        else{
            compressed += letter + count;
            letter = str[i];
            count = 1;
        }
    }
    compressed += letter + count;

    if( compressed.length < str.length ){
        return compressed;
    }
    else {
        return str;
    }
}