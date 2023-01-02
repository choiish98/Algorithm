# TSP

**Traveling Salesman Problem**

<br>

> Hamiltonian Path, Hamiltonian Cycle
>
> Depth-First Search
>
> Dynamic Programming
>
> Bit masking

<br>

## Definitions

The TSP is to obtain the Hamiltonian cycle from a full graph.

<br>

The Hamiltonian path is the path that visits all nodes with the least weight, without duplicating the same node in the weighted graph.

And the Hamiltonian cycle means the cycle of the Hamiltonian path.

<br>

Thus, the TSP does not visit the same node in a full graph, but obtains a cycle of visiting all nodes with the least weight.

<br>

## Algorithms

### 1. visiting nodes

You can draw a tree by circulating from the starting node to the movable node in the graph.

The number of node visits using this tree is obtained in a short time through DFS.

<br>

### 2. Minimum costs

The easiest way to solve this problem is by Brute Force.

A recursive approach is used to solve every case of visiting each node that can be visited by the starting node

This is an inefficient solution of the time complexity `O(2^n)` because recursive is used.

<br>

In this case, efficient solving is generally performed using **DP using memorization**, which can be easily thought of.

Minimize operations on overlapping nodes with principles such as Fibonacci in the number of trees of cases.

Therefore, the TSP can be solved with the time complexity `O(n)`.

Recurrence relation: ```dp[cur][visited] = min(dp[cur][visited], dp[next][visited | (1 << next)] + graph[cur][next])```

<br>

### 3. check visit

However, in terms of spatial complexity, simply using DP has a large overhead.

When the number of nodes in the graph is n, the number of leaf nodes may be the number of cases, and according to the characteristics of the tree, the number of leaf nodes is 2^n.

That is, the spatial complexity still has 2^n.

<br>

To solve this problem, solving using **bit masking** is performed.

It is simply to reduce the spatial complexity to n by representing the number of cases of 2^n in n bits.

<br>

## Pseudo-Code

<img src="C:\Users\choi\OneDrive - UNIST\바탕 화면\CS\Algorithm\외판원 순회\1.png" alt="1" style="zoom:67%;" />

<br>

## Example

- [백준 2098 외판원 순회](https://www.acmicpc.net/problem/2098)