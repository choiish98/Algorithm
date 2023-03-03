# Insertion Sort

삽입 정렬



## Introduction

- **Problem**
  - Given an input sequence of n numbers, the sorting problem is to find a permutation of the input sequence sorted in nondecreasing order
- **Example**
  - input: 6, 1, 7, 6, 4
  - output: 1, 4, 6, 6, 7
- Insertion Sort proceeds from **left to right**. 
- The current element is **compared with all left elements** and inserted into left side.



## Algorithm

- **Figures**

![1](C:\Users\choi\OneDrive - UNIST\바탕 화면\Class\Advanced Algorithms\week 1\1.png)

Repeat for all elements



- **Pseudo Code**

```pseudocode
procedure Insertion-Sort(A[1 ... N])
	for j <- 2, n do
		key <- A[j]
		i <- j - 1
		
		while i > 0 and A[i] > key do
			A[i + 1] <- A[i]
			i <- i - 1
			
        A[i + 1] <- key
```



## Proof of Correctness

- Strategy: **loop invariant**
  - loop invariant for Insertion Sort
    : At the start of each iteration of the for loop, the subarray consists of the elements original array in sorted order.
  - **Initialization**: It is true prior to the first iteration of the loop. 
  - **Maintenance**: If it is true before an iteration of the loop, it remains true before the next iteration. 
  - **Termination**: When the loop terminates, the invariant gives us a useful property that helps show that the algorithm is correct.



## Analysis

time complex

```pseudocode
procedure Insertion-Sort(A[1 ... N])		times		cost
	for j <- 2, n do						n			c2
		key <- A[j]							n-1			c3
		i <- j - 1							n-1			c4
		
		while i > 0 and A[i] > key do		sigma tj	c5
			A[i + 1] <- A[i]				sigma tj	c6
			i <- i - 1						sigma tj	c7
			
        A[i + 1] <- key						n-1			c8
```



- running time is 

  ![2](C:\Users\choi\OneDrive - UNIST\바탕 화면\Class\Advanced Algorithms\week 1\1.png)

- If the input is already sorted, then tj = 1 for all j. (best-case)
  ![2](C:\Users\choi\OneDrive - UNIST\바탕 화면\Class\Advanced Algorithms\week 1\2.png)

  ![3](C:\Users\choi\OneDrive - UNIST\바탕 화면\Class\Advanced Algorithms\week 1\3.png)

- Suppose that the input array is sorted in decreasing order, then tj = j for all j. (worst-case)

  ![4](C:\Users\choi\OneDrive - UNIST\바탕 화면\Class\Advanced Algorithms\week 1\4.png)

  