# Quick Sort

>  Quick-sort is a randomized sorting algorithm based on the divide-and-conquer paradigm.

<br>

## Analysis of Merge-Sort

- An execution of merge-sort is depicted by a binary tree.
- Each node represents a recursive call of quick-sort and stores.
  - Unsorted sequence before the execution and its pivot.
  - Sorted sequence at the end of the execution.
- The root is the initial call.
- The leaves are calls on subsequence of size 0 or 1.

<br>

![fig 1](C:\Users\SH.C\OneDrive - UNIST\바탕 화면\CS\Algorithm\merge sort\fig 1.png)

<br>

- We partition an input sequence as follows
  - We remove, in turn, each element `y` from `S` and 
  - We insert y into `L`, `E` or `G`, depending on the result of the comparison with the pivot `x` .
- Each insertion and removal is at the beginning or at the end of a sequence, and hence takes `O(1)` time .
- Thus, the partition step of quick-sort takes `O(n)` time.

<br>

## How It Works

Quick-sort on an input sequence `S` with n elements consists of three steps


1. **Divide**: pick a random element `x` (called pivot) and partition `S` into
   - `L` elements less than `x`.
   - `E` elements equal `x`.
   - `G` elements greater than `x`.
2. **Recur**: sort `L` and `G`.
3. **Conquer**: join `L`, `E` and `G`.

<br>


## Pseudo-Code

- sort with a sequence S and comparator C

```
Algorithm partition(S, p)
	Input sequence S, position p of pivot
	Output subsequences L, E, G of the
		elements of S less than, equal to,
		or greater than the pivot, resp.
	L, E, G <- empty sequences
	x <- S.erase(p)
	while ¬S.empty()
		y ¬ S.eraseFront()
		if y < x
			L.insertBack(y)
		else if y = x
			E.insertBack(y)
		else { y > x }
			G.insertBack(y)
	return L, E, G
```

<br>

## Worst-case Running Time

- The worst case for quick-sort occurs when the pivot is the unique minimum or maximum element.

- One of `L` and `G` has size `n` - 1 and the other has size 0 

  - The running time is proportional to the sum 

    `n + (n - 1) + … + 2 + 1` 

- Thus, the worst-case running time of quick-sort is `O(n2)`

<br>

fig

<br>

## Expected Running Time

- Consider a recursive call of quick-sort on a sequence of size s 
  - **Good call**: the sizes of L and G are each less than 3s/4 
  - **Bad call**: one of L and G has size greater than 3s/4

<br>

![fig 2](C:\Users\SH.C\OneDrive - UNIST\바탕 화면\CS\Algorithm\Quick Sort\fig 2.png)

<br>

- A call is **good** with probability 1/2 
  - 1/2 of the possible pivots cause good calls:

![fig 3](C:\Users\SH.C\OneDrive - UNIST\바탕 화면\CS\Algorithm\Quick Sort\fig 3.png)

- **Probabilistic Fact**: The expected number of coin tosses required in order to get `k` heads is `2k` 
- For a node of depth `i`, we expect 
  - `i/2` ancestors are good calls 
  - The size of the input sequence for the current call is at most `(3/4)i/2n`.
- Therefore, we have 
  - n For a node of depth `2log4/3n`, the expected input size is one.
  - The expected height of the quick-sort tree is `O(log n)`.
- The amount or work done at the nodes of the same depth is `O(n)`.
- Thus, the expected running time of quick-sort is `O(n log n)`.

<br>

![fig 4](C:\Users\SH.C\OneDrive - UNIST\바탕 화면\CS\Algorithm\Quick Sort\fig 4.png)