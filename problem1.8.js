/*
Problem 1.8
Zero Matrix: Write an algorithm such that
if an element in an MxN matrix is 0, its
entire row and column are set to O.
*/

function Zero( row, col ) {
    this.row = row;
    this.col = col;
};

var matrix = [
    [1, 2, 0, 5],
    [3, 4, 3, 1],
    [0, 1, 1, 1]
];

var z = [];

document.write('Before:');
for( var i = 0; i < matrix.length; i++ ){
    document.write('<div>');
    for( var j = 0; j < matrix[i].length; j++ ){
        document.write(matrix[i][j] + ' '); // print before matrix on document
        if( matrix[i][j] == 0 ){
            var b = new Zero(i,j);
            z.push(b);
        }
    }
    document.write('</div>');
}


document.write('<br>After:');
for( var i = 0; i < z.length; i++ ){
    // rows
    for( var j = 0; j < matrix.length; j++ ){
        matrix[j][z[i].col] = 0;
    }
    
    // columns
    for( var k = 0; k < matrix[0].length; k++ ){
        matrix[z[i].row][k] = 0;
    }
}


// print after matrix on document
for( var i = 0; i < matrix.length; i++ ){
    document.write('<div>')
    for( var j = 0; j < matrix[i].length; j++ ){
        document.write(matrix[i][j] + ' ');
    }
    document.write('</div>');
}

console.log(matrix);
