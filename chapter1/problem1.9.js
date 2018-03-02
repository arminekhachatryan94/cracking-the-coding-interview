/*
Problem 1.9
String Rotation: Assume you have a method isSubstring
which checks if one word is a substring of another.
Given two strings, 51 and 52, write code to check
if 52 is a rotation of 51 using only one call to
isSubstring (e.g.,"waterbottle" is a rotation of
"erbottlewat").
*/

var d = document.getElementById("p9");
d.innerHTML += '<h2>Problem 9</h2>';

var str = "waterbottle";
var str2 = "erbottlewat";
d.innerHTML += '<div>String 1: ' + str + '</div>';
d.innerHTML += '<div>String 2: ' + str2 + '</div>';

var result = stringRotation(str, str2);
d.innerHTML += '<div>String Rotation: ' + result + '</div>';

function stringRotation( str1, str2 ) {
    var order1 = str1.order;
    var order2 = str2.order;

    if( str1 == str2 ){
        return true;
    }
    else{
        var ret = false;

        // both strings are same length & have same characters
        if( (str1.length == str2.length) && (order1 == order2) ){
            for( var i = 0; i < str1.length - 1; i++ ) {
                // rotate once
                str1 = str1.substring(1, str1.length) + str1[0];

                // check if matches
                if( str1 == str2 ) {
                    ret = true;
                    break;
                }
            }
            return ret;
        }
        else{
            return false;
        }
    }
};