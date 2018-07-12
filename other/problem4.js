/*
A building has 100 floors. One of the floors is the highest floor an egg can be dropped from without breaking.
If an egg is dropped from above that floor, it will break. If it is dropped from that floor or below, it will be completely undamaged and you can drop the egg again.

Given two eggs, find the highest floor an egg can be dropped from without breaking, with as few drops as possible.
*/

document.write('<h2>Problem 4</h2>');
document.write(`<b>A building has 100 floors. One of the floors is the highest floor an egg can be dropped from without breaking.
If an egg is dropped from above that floor, it will break. If it is dropped from that floor or below, it will be completely undamaged and you can drop the egg again.

Given two eggs, find the highest floor an egg can be dropped from without breaking, with as few drops as possible.</b>
<br>`);

// highest floor the egg can be safely dropped from
var highest = Math.floor(Math.random() * 100) + 1; // random number between 1 - 100
document.write(highest + '<br>');

// true means eggs are not broken;
var egg1 = true;
var egg2 = true;

var a = 100;
a = Math.round(a/2);
var safe = 1;
var broken = 100;

findHighestFloor();

// worst case
function findHighestFloor(){
    if( egg1 ){
        egg1 = dropEgg(a);
        if( egg1 ){
            safe = a;
            a = Math.round(a + a/2);
        } else {
            broken = a;
        }
        // document.write(a + ' ');
        findHighestFloor();
    } else if( egg2 ){
        document.write('<br>safe: ' + safe + ', broken: ' + broken + '<br>')
        for( var i = safe; i < broken; i++ ){
            egg2 = dropEgg(i);
            if( !egg2 ){
                document.write(i-1 + ' is the highest floor.');
                break;
            }
        }
    } else {
        document.write('; all eggs are broken');
    }
}

function dropEgg(floor) {
    if( floor <= highest ){
        return true;
    } else {
        return false;
    }
}