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

var output = URLify(str);
// console.log(output);


var d = document.getElementById("p3");
d.innerHTML += '<h2>Problem 3</h2>';
d.innerHTML += '<span>String: "';

for( var i = 0; i < str.length; i++ ){
    if( str[i] == ' '){
        // console.log('space');
        d.innerHTML += '&nbsp;';
    }
    else{
        d.innerHTML += str[i];
    }
}
d.innerHTML += '", Length: ' + len + '</span>';
d.innerHTML += '<div>Outputs: "' + output + '"</div>';



function URLify(str) {
    return str.substr(0, len).split(' ').join('%20');
}