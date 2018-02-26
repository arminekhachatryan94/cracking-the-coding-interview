/*
count number of duplicate integers in an array

input: array of integers
output: integer representing the number of duplicates

INCOMPLETE
*/

var a = [6,1,1,2,2,2,3,6,6,8,9,10,10];

a.sort( function(a,b) {
    return a-b;
});

a = a.join('');

var len = a.length;
console.log(len);

console.log(a);

for( var i = a[0]; i <= a[len-1]; i++ ){
    var regex = new RegExp(i, "gi");
    
    var num = a.match(regex).length;
    console.log(num);
    /*
    if( num > 1 ){
        console.log(i + ": " + num);
    }
    */
}

var regexstring = "whatever";
var regexp = new RegExp(i, "gi");
var str = "whateverTest";
var str2 = str.replace(regexp, "other");
document.write(str2);


