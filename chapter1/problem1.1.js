/*
Problem 1.1
Is Unique: Implement an algorithm to determine
if a string has all unique characters. What if you
cannot use additional data structures?
*/

var a = "armine kh12;";

var d = document.getElementById("p1");

d.innerHTML += '<h2>Problem 1</h2>'
d.innerHTML += '<div> Original string: ' + a + '</div>'

var unique = isUnique(a);
d.innerHTML += '<div>Uniqueness: ' + unique + '</div>';



function isUnique(str) {
    str = str.split("").sort().join("");

    var unique = true;
    for( var i = 1; i < str.length; i++ ){
        if(str[i-1] == str[i]){
            unique = false;
            break;
        }
    }
    // console.log("uniqueness: " + unique);
    return unique;
}

