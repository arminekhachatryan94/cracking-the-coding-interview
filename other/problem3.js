/*
 Given a zero-indexed array A of N integers, return any
 of the indexes P of the element, which left sums of its
 left elements and right elements are equal. Sum of zero
 element is assumed to be equal to 0. This can happen if
 P = 0 or if P = N-1. For example,
 A = {-1, 3, -4, 5, 1, -6, 2, 1},
 indexes 1, 3, and 7 are valid outputs.
*/

document.write('<h2>Problem 3</h2>')
var A = [-1, 3, -4, 5, 1, -6, 2, 1];

var leftSum = 0;
var rightSum = 0;
document.write('A = [ ');
for( var i = 0; i < A.length; i++ ){
    rightSum += A[i];
    document.write(A[i]);
    if( i < A.length - 1 ){
        document.write(', ');
    }
}
document.write(' ]');

for( var i = 0; i < A.length; i++ ){
    if( i == 0 ){
        rightSum -= A[i];
    } else {
        leftSum += A[i-1];
        rightSum -= A[i];
    }
    document.write( '<div>[' + i + "]: leftSum=" + leftSum + ' rightSum=' + rightSum + (leftSum == rightSum ? ' true' : ' false') + '</div>');
}
