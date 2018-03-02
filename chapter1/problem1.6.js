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

var d = document.getElementById("p6");
d.innerHTML += '<h2>Problem 6</h2>';

var str = "aabcccccaaa";
var compressed = compressedString(str);
d.innerHTML += '<div>String 1: ' + str + '</div>';
d.innerHTML += '<div>Compressed String 1: ' + compressed + '</div>';
// console.log(str);
// console.log(compressed);

var str2 = "ABC";
var compressed2 = compressedString(str2);
d.innerHTML += '<div>String 2: ' + str2 + '</div>';
d.innerHTML += '<div>Compressed String 2: ' + compressed2 + '</div>';
// console.log(str2);
// console.log(compressed2);

function compressedString( strn ) {

    var compressed = "";

    var letter = strn[0];
    var count = 1;
    for( var i = 1; i < strn.length; i++ ){
        if( strn[i] == letter ){
            count++;
        }
        else{
            compressed += letter + count;
            letter = strn[i];
            count = 1;
        }
    }
    compressed += letter + count;

    if( compressed.length < strn.length ){
        return compressed;
    }
    else {
        return strn;
    }
}