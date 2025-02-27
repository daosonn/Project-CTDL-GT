# Dijkstra's Algorithm Implementation

## Overview

Dijkstra's Algorithm is a popular graph traversal algorithm used to find the shortest path from a source vertex to all other vertices in a graph. This algorithm works on both directed and undirected graphs, provided that there are no negative weight edges.

### Applications

- Finding the shortest route in navigation systems.
- Network routing protocols.
- Solving optimization problems in graphs.

### Time Complexity

The time complexity of Dijkstra's Algorithm is:

- **O((E + V) log V)**, where:
    - `E` is the number of edges.
    - `V` is the number of vertices.

## Input Format

The input is provided as follows:

1. The first line contains three integers: `n` (number of vertices), `m` (number of edges), and `s` (source vertex).
2. The next `m` lines each contain three integers: `u`, `v`, and `w`, representing an edge from vertex `u` to vertex `v` with weight `w`.

### Example Input

```
6 8 1
1 2 7
1 3 12
2 3 2
2 4 9
3 5 10
4 6 1
5 4 4
5 6 5
```

## Output Format

The output consists of the shortest distance from the source vertex `s` to all other vertices, along with the path for each vertex.

### Example Output

```
Khoang cach tu dinh 1 den dinh 1 la: 0. Duong di: 1
Khoang cach tu dinh 1 den dinh 2 la: 7. Duong di: 1 -> 2
Khoang cach tu dinh 1 den dinh 3 la: 9. Duong di: 1 -> 2 -> 3
Khoang cach tu dinh 1 den dinh 4 la: 16. Duong di: 1 -> 2 -> 4
Khoang cach tu dinh 1 den dinh 5 la: 19. Duong di: 1 -> 2 -> 3 -> 5
Khoang cach tu dinh 1 den dinh 6 la: 17. Duong di: 1 -> 2 -> 4 -> 6
```
