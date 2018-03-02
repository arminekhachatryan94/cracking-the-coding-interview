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

var d = document.getElementById("p5");
d.innerHTML += '<h2>Problem 5</h2>';

var s1 = "palt";
var s2 = "palet";
d.innerHTML += '<div>String 1: ' + s1 + '</div>';
d.innerHTML += '<div>String 2: ' + s2 + '</div>';

oneAway(s1,s2);



function oneAway(str1, str2) {
    str1 = str1.split("");
    str2 = str2.split("");
    
    if( str1 == str2 ){
        // console.log( "Zero edits away" );
        d.innerHTML += '<div>Zero edits away</div>';
    }
    else if( str1.length + 1 == str2.length ){
        var one_away = true;
        for( var i = 0; i < str1.length; i++ ){
            // console.log('i: ' + i);
            if( str1[i] != str2[i] && str1[i] == str2[i+1] ){
                str1.splice( i, 0, str2[i+1]);
                console.log('i:' + i + ' ' + str1 + " " + str2);
                if( str1 == str2 ){
                    one_away = true;
                    break;
                }
                break;
            }
            // console.log(str1 + " " + str2);
        }
        // console.log("i: " + i);
        // console.log("one away: " + one_away);
        if( one_away ){
            d.innerHTML += '<div>One away</div>';
        }
        else{
            d.innerHTML += '<div>Now one away</div>';
        }
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
        // console.log("i: " + i);
        console.log("one away: " + one_away);
        if( one_away ){
            d.innerHTML += '<div>One away</div>';
        }
        else{
            d.innerHTML += '<div>Not one away</div>';
        }
    }
    else{
        d.innerHTML += '<div>Not one away</div>';
        console.log('Not one away');
    }
}