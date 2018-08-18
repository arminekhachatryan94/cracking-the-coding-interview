/*
Consider an undirected tree with N nodes, numbered from 1 to N. Each node has a label associated with it, which is an integer value. Different nodes can have the same label. Write a function that, given a zero indexed array A of length N, where A[j] is the label value of the (j + 1)-th node in the tree and a zero-indexed array E of length K = (N – 1) * 2 in which the edges of the tree are described, returns the length of the longest path such that all the nodes on that path have the same label. The length is the number of edges in that path.

Example:

A = [1, 1, 1, 2, 2]
E = [1, 2, 1, 3, 2, 4, 2, 5]

This tree is shown below. A node follows the form label, value.

----------1, 1

-----1, 2        1, 3

2, 4      2, 5
The function should return 2, because the longest path is 2->1->3, and there are 2 edges in this path.

Assume that 1 <= N <= 1000 and each element of the array A is an integer in the range [1, 1000000000].
*/

document.write('<h2>Problem 6</h2>');

A = [1, 1, 1, 2, 2]
E = [1, 2, 1, 3, 2, 4, 2, 5];

function longestPath(A, E){
    var Nodes = [];
    for( var i = 0; i < E.length; i+=2 ){
        edges.push(new Array(E[i], E[i+1]));
    }
    return edges;
}

function printEdges(edges) {
    for( var i = 0; i < edges.length; i++ ){
        document.write('(' + edges[i][0] + ', ' + edges[i][1] + ')');
        document.write('<br>');
    }
}
