# Dynamic Programming

<br>

## Matrix Chain Product

<br>

### Matrix Multiplication

![1]()

- `A * B = d * e + e * f`

- `C[i, j] = SIGMA k = e-1 ~ 0 (A[i, k] * B[k, j])`

<br>

### Matrix Chain Product

![2]()

- There are many options because matrix multiplication is associative. 
- In other words, no matter how the product is parenthesized, the result obtained will remain the same. 
- For example, for four matrices A, B, C, and D, there are multiple possible options:
  - ((*AB*)*C*)*D* = (*A*(*BC*))*D* = (*AB*)(*CD*) = *A*((*BC*)*D*) = *A*(*B*(*CD*))

<br>

## Variable Approach

<br>

### Enumeration Approach

- Matrix Chain Product Algorithm
  - Try all possible ways to parenthesize `A = A0 * A1 * ... * An-1`.
  - Calculate number of ops for each one.
  - Pick the one that is best.
- Running time
  - The number of parenthesizations is equal to the number of binary trees with n nodes.
  - This is exponential.
  - It is called the Catalan number, and it is almost `4^n`.

<br>

### Greedy Approaches

- Repeatedly select the product that uses the most operations.
  - Counter-example
  - A is 10 * 5
  - B is 5 * 10
  - C is 10 * 5
  - D is 5 * 10
  - Greedy idea is gives (A * B) * (C * D), which takes 500 + 1000 + 500 = 2000 ops.
  - A * ((B * C) * D) takes 500 + 250 + 250 = 1000 ops.
- Repeatedly select the product that uses the fewest operations.
  - Counter-example
  - A is 101 * 11
  - B is 11 * 9
  - C is 9 * 100
  - D is 100 * 99
  - Greedy idea give a * ((B * C) * D), which takes 109989 + 9900 + 108900 = 228789 ops.
  - (A * B) * (C * D) takes 9999 + 89991 + 89100 = 189090 ops.

<br>

### Recursive Approach

- Define subproblems
  - Find the best parenthesization of `Ai * Ai+1 * ... * Aj`.
  - Let `Ni,j` denote the number of operations done by this subproblem.
  - The optimal solution for whole problem is `N0,n-1`.
- Subproblem optimality
  - The optimal solution can be defined in terms of optimal subproblems.
  - There has to be a final multiplication (root of the expression tree) for the optimal solution.
  - The final multiply is at index i: `(A0 * .. * Ai) * (Ai+1 * ... * An-1)`.
  - Then the optimal solution `N0,n-1` is the sum of two optimal subproblems, `N0,i` and `Ni+1,n-1` plus the time for the last ultiply.
  - If the global optimum did not have these optimal subproblems, we could define an even better optimal solution.

<br>

### Characterizing Equation

- The global optimal has to be defined in terms of optimal subproblems, depending on where the final multiply is at.

- All possible places for that final multiply

  - Recall that `Ai` is a `di * di+1` dimensional matrix.

  - So, a characterizing equation for `Ni,j` is the following.

    ![3]()

- Note that subproblems are not independent -- **the subproblems overlap**.

<br>

## Dynamic Programming

- Since subproblems overlap, we don't use recursion.
- Instead, we construct optimal subproblems "bottom-up".
- `Ni,j`'s are easy, so start with them.
- Then do length 2, 3 .. subproblems, and so on.
- The running time is `O(n^3)`.

<br>

### Visualization

![4]()

- The bottom-up construction fills in the `N` array by diagonals.
- `Ni,j` gets values from previous entries in i-th row and j-th column. 
- Filling in each entry in the N table takes `O(n)` time. 
- Total run time: `O(n^3)`.
- Getting actual parenthesization can be done by remembering “k” for each N entry.

### Pseudo-Code

```
Algorithm matrixChain(S):
	Input: sequence S of n matrices to be multiplied
	Output: number of operations in an optimal paranethization of S

	for i <- 1 to n-1 do
		Ni,i <- 0
	for b <- 1 to n-1 do
		for i <- 0 to n-b-1 do
			j <- i+b
			Ni,j <- +infinity
			for k <- i to j-1 do
				Ni,j <- min{Ni,j , Ni,k +Nk+1,j +di dk+1 dj+1}
```

<br>

<br>

###### [참고자료]

- [프로그래밍에 대한 고찰](https://source-sc.tistory.com/24)