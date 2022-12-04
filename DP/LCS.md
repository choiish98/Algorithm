# LCS

**Longest Common Subsequence**

<br>

## Define

- Given two strings `X` and `Y`, the longest common subsequence (LCS) problem is to find a longest subsequence common to both `X` and `Y`. 
- Has applications to DNA similarity testing. (alphabet is {`A`,`C`,`G`,`T`}) 
- Example: `ABCDEFG` and `XZACKDFWGH` have `ACDFG` as a longest common subsequence.

<br>

## Approach to the LCS

### Brute-force

- Enumerate all subsequences of X.
- Test which ones are also subsequences of Y.
- Pick the longest one.

- Analysis
  - If X is of length n, then it has 2^n subsequences.
  - This is an exponential-time algorithm.

<br>

### Dynamic-Programming 

- Define L[i,j] to be the length of the longest common subsequence of X[0..i] and Y[0..j]. 
- Allow for -1 as an index, so L[-1,k] = 0 and L[k,-1]=0, to indicate that the null part of X or Y has no match with the other. 
- Then we can define L[i,j] in the general case as follows: 
  1. If x[i]=y[j], then L[i,j] = L[i-1,j-1] + 1 (we can add this match) 
  2. If x[i]≠y[j], then L[i,j] = max{L[i-1,j], L[i,j-1]} (we have no match here)

<br>

![fig 1](C:\Users\SH.C\OneDrive - UNIST\바탕 화면\CS\Algorithm\LCS\fig 1.png)

## Analysis of LCS Algorithm

- We have two nested loops.
  - The outer one iterates `n` times.
  - The inner one iterates `m` times.
  - A constant amount of work is done inside each iteration of the inner loop.
  - Thus, the total running time is `O(nm)`.
- Answer is contained in L[n,m] (and the subsequence can be recovered from the L table).

<br>

## Pseudo-Code

```
Input: Strings X and Y with n and m elements, respectively
Output: For i = 0,…,n-1, j = 0, ... , m-1, 
		The length L[i, j] of a longest string that is a subsequence of both the string X[0..i] = x0x1x2…xi and the string Y [0.. j] = y0y1y2…yj

Algorithm LCS(X,Y ):
for i =1 to n-1 do
	L[i,-1] = 0
for j =0 to m-1 do
	L[-1,j] = 0
for i =0 to n-1 do
	for j =0 to m-1 do
		if xi = yj then
			L[i, j] = L[i-1, j-1] + 1
		else
			L[i, j] = max{L[i-1, j] , L[i, j-1]}
return array L
```

