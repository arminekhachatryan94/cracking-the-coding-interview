/*
Problem 1.7
Rotate Matrix: Given an image represented by an NxN matrix,
where each pixel in the image is 4 bytes, write a method to
rotate the image by 90 degrees. (an you do this in place?
*/

var d = document.getElementById("p7");
d.innerHTML += '<h2>Problem 7</h2>';

var a = [
    // 0 1 2 3
    [[0x7b,0x4c,0xcd], [0x15,0x77,0x98], [0xe2,0xba,0xf8], [0xef,0x3d,0xa5]],
    [[0x66,0xb7,0x54], [0x7b,0x4c,0xcd], [0x15,0x77,0x98], [0xe2,0xba,0xf8]],
    [[0xe1,0x89,0xa5], [0x66,0xb7,0x54], [0x7b,0x4c,0xcd], [0x15,0x77,0x98]],
    [[0xc0,0x2d,0x49], [0xe1,0x89,0xa5], [0x66,0xb7,0x54], [0x7b,0x4c,0xcd]]
];

var num_rows = a.length;
var num_cols = a[0].length;

rotateMatrix90(a);

function rotateMatrix90(matrix) {
    // print original matrix
    d.innerHTML += '<div>Original Matrix:</div>';
    printMatrix(matrix);
    
    // transpose
    for( var i = 0; i < num_rows; i++ ){
        for( var j = i; j < num_cols; j++ ){
            var temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    
    // reverse elements of every column
    var r = (num_rows - (num_rows%2))/2;
    for( var i = 0; i < r; i++ ){
        for( var j = 0; j < num_cols; j++ ){
            var temp = matrix[i][j];
            matrix[i][j] = matrix[num_rows-i-1][j];
            matrix[num_rows-i-1][j] = temp;
        }
    }
    
    // print reversed (90 degrees rotated)
    d.innerHTML += '<div>Rotated Matrix by 90 degrees:</div>';
    printMatrix(matrix);
}

function printMatrix(matrix) {
    for( var i = 0; i < num_rows; i++ ){
        for( var j = 0; j < num_cols; j++ ){
            d.innerHTML += '<div style="height:20px; width:20px; background:rgb(' + a[i][j] + '); display:inline-block;"></div>';
        }
        d.innerHTML += '<br>';
    }
}
