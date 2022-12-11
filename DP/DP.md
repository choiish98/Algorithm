# Dynamic Programming

<br>

## Matrix Chain Multiplication

> when A = 20 x 2, B = 2 x 30, C = 30 x 12, D = 12 x 8,
>
> what is A * B * C * D = ?
>
> no matter order, conclusion is always same.
>
> so we need to find optimal way.

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

  - So, a characterizing equation for `Ni,j` is the following:

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

```pseudocode
Algorithm matrixChain(S):
	Input: sequence S of n matrices to be multiplied
	Output: number of operations in an optimal paranethization of S

	for i <- 1 to n-1 do
		Ni,i <- 0 					// table 초기화
	for b <- 1 to n-1 do			// 비교할 길이
		for i <- 0 to n-b-1 do		// 0부터 n-1까지 비교할 길이만큼
			j <- i+b				// 비교할 길이만큼의 j
			Ni,j <- +infinity
			for k <- i to j-1 do	// 비교할 대상의 최대 k 찾기
				Ni,j <- min{Ni,j , Ni,k +Nk+1,j +di dk+1 dj+1}
```

<br>

## Example

**What is the best way to multiply a chain of matrices with dimensions that are 10×5, 5×2, 2×20, 20×12, 12×4, and 4×60?**

- M1 = 10 * 5, M2 = 5 * 2, M3 = 2 * 20, M4 = 20 * 12, M5 = 12 * 4, M6 = 4 * 60
- d1 = 10, d2 = 5, d3 = 2, d4= 20, d5 = 12, d6= 4, d7 = 60
- N[i , j] = N[i, k] + N[k+1, j] + di + dk+1, dj+1
- B = 1
  - N[1, 2] = 100
  - N[2, 3] = 200
  - N[3, 4] = 480
  - N[4, 5] = 960
  - N[5, 6] = 2880
- B = 2
  - N[1, 3] = 500
  - N[2, 4] = 600
  - N[3, 5] = 576
  - N[4, 6] = 5760
- B = 3
  - N[1, 4] = 820
  - N[2, 5] = 616
  - N[3, 6] = 
- B = 4
  - N[1, 5] = 816
  - N[2, 6] = 1655
- B = 5
  - N[1, 6] = 2356

<br>

###### [참고자료]

- [프로그래밍에 대한 고찰](https://source-sc.tistory.com/24)