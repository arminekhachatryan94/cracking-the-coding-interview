/*
Problem 1.5
One Away: There are three types of edits that
can be performed on strings: insert a character,
remove a character, or replace a character. Given
two strings, write a function to check if they are
one edit (or zero edits) away.

EXAMPLE
pale, ple -> true
pales. pale -> true
pale. bale -> true
pale. bake -> false
*/


var str1 = "palt";
var str2 = "palet";

str1.split("");
str2.split("");

if( str1 == str2 ){
    console.log( "Zero edits away" );
}
else if( str1.length + 1 == str2.length ){
    var one_away = false;
    for( var i = 0; i < str1.length; i++ ){
        console.log('i: ' + i);
        if( str1[i] != str2[i] && str1[i] == str2[i+1] ){
            str1.splice( i, 0, str2[i+1]);
            console.log(str1 + " " + str2);
            if( str1 == str2 ){
                one_away = true;
                break;
            }
            break;
        }
        /*
        if( i+1 == str1.length ){
            str1.splice( i, 0, str2[i+1]);
        }
        */
        
        
        console.log(str1 + " " + str2);
    }
    console.log("i: " + i);
    console.log("one away: " + one_away);
}
else if( str1.length == str2.length + 1 ){
    var one_away = false;
    for( var i = 0; i < str2.length; i++ ){
        if( str1[i] != str2[i] && str1[i+1] == str2[i] ){
            str2.splice( i, 0, str1[i+1]);
            console.log(str1 + " " + str2);
            if( str1 == str2 ){
                one_away = true;
                break;
            }
            break;
        }
        console.log(str1 + " " + str2);
    }
    console.log("i: " + i);
    console.log("one away: " + one_away);
}
else{
    console.log( "Not one away" );
}
