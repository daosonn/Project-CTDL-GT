Dijkstra's Algorithm Implementation

Overview

Dijkstra's Algorithm is a popular graph traversal algorithm used to find the shortest path from a source vertex to all other vertices in a graph. This algorithm works on both directed and undirected graphs, provided that there are no negative weight edges.

Applications

Finding the shortest route in navigation systems.

Network routing protocols.

Solving optimization problems in graphs.

Time Complexity

The time complexity of Dijkstra's Algorithm is:

O((E + V) log V), where:

E is the number of edges.

V is the number of vertices.

Input Format

The input is provided as follows:

The first line contains three integers: n (number of vertices), m (number of edges), and s (source vertex).

The next m lines each contain three integers: u, v, and w, representing an edge from vertex u to vertex v with weight w.

Example Input

6 8 1
1 2 7
1 3 4
2 3 2
2 4 9
3 5 3
4 6 1
5 4 4
5 6 5

Output Format

The output consists of the shortest distance from the source vertex s to all other vertices, along with the path for each vertex.

Example Output

Khoang cach tu dinh 1 den dinh 1 la: 0. Duong di: 1
Khoang cach tu dinh 1 den dinh 2 la: 6. Duong di: 1 -> 3 -> 2
Khoang cach tu dinh 1 den dinh 3 la: 4. Duong di: 1 -> 3
Khoang cach tu dinh 1 den dinh 4 la: 11. Duong di: 1 -> 3 -> 5 -> 4
Khoang cach tu dinh 1 den dinh 5 la: 7. Duong di: 1 -> 3 -> 5
Khoang cach tu dinh 1 den dinh 6 la: 12. Duong di: 1 -> 3 -> 5 -> 6

H
