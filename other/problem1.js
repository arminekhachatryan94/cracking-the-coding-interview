/* incomplete */

/*
var a = [1, 2, 3, 4, -4, -3, -2, 8, 9, 11, 13, -2, -3, -4];

console.log("a: " + a);

var b = [];

var start = a[0];
for( var i = 2; i < a.length; i++ ){
    // console.log(a[i]);
    if( (a[i-2]+1 == a[i-1]) && (a[i-1]+1 == a[i]) ){ // ascending
        if( i-2 == 0 ){
            
        }
        console.log(a[i] + " ascending");
    }
    else if( (a[i-2]-1 == a[i-1]) && (a[i-1]-1 == a[i]) ){ // descending
        if( i-2 == 0 ){
            
        }
        console.log(a[i] + " descending");
    }
    else{
        var temp = start + "-" + a[i-1];
        b.push(temp);
        start = a[i];
        // console.log("start: " + start);
    }
}
for( var i = 0; i < b.length; i++ ){
    var temp = b[i];
    var len = b[i].length;
    len -= 1;
    
    var p1 = temp.substr(0, len/2);
    var p2 = temp.substr( len/2 + 1, b[i].length);
    // console.log("p1: " + p1);
    // console.log("p2: " + p2);
    if( p1 == p2 ){
        b[i] = p1;
    }
}

console.log("b: " + b);
*/