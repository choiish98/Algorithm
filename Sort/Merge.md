# Merge Sort

<br>

## Define

- Merge-sort is sorting algorithm based on the divide-and-conquer paradigm.
- Like heap-sort   
  - It uses a comparator.
  - It has `O(n log n)` running time.
- Unlike heap-sort
  - It does not use an auxiliary priority queue.
  - It accesses data in a sequential manner. (suitable to sort data on a disk)

<br>

## Analysis of Merge-Sort

- An execution of merge-sort is depicted by a binary tree.
- Each node represents a recursive call of merge-sort and stores.
  - Unsorted sequence before the execution and its partition.
  - Sorted sequence at the end of execution.
- The root is the initial call.
- The leaves are calls on subsequence of size 0 or 1.

<br>

![fig 1](C:\Users\SH.C\OneDrive - UNIST\바탕 화면\CS\Algorithm\merge sort\fig 1.png)

<br>

- The height `h` of merge-sort tree is `O(log n)`.
  - at each recursive call we divide in half the sequence.
- The overall amount or work done at the nodes of depth `i` is `O(n)`
  - we partition and merge `2^i` sequences of size `n/2^i`
  - we make `2^i+1` recursive calls.
- Thus, the total running time of merge-sort is `O(n log n)`

<br>

![fig 2](C:\Users\SH.C\OneDrive - UNIST\바탕 화면\CS\Algorithm\merge sort\fig 2.png)

<br>

## How It Works

Merge-sort on an input sequence S with n elements consists of three steps


1. **Divide**: partition S into two sequences `S1` and `S2` of about `n/2` elements each.
2. **Recur**: recursively sort `S1` and `S2`.
3. **Conquer**: merge `S1` and `S2` into a unique sort sequence.

<br>


## Pseudo-Code

- sort with a sequence S and comparator C

```
Algorithm mergeSort(S, C)
    Input sequence S with n
        elements, comparator C
    Output sequence S sorted
        according to C
    if S.size() > 1
        (S1, S2) ¬ partition(S, n/2)
        mergeSort(S1, C)
        mergeSort(S2, C)
        S <- merge(S1, S2)
```

<br>

- sort with two sorted sequence

```
Algorithm merge(A, B)
    Input sequences A and B with
        n/2 elements each
    Output sorted sequence of A È B
    S <- empty sequence
    while ¬A.empty() Ù ¬B.empty()
        if A.front() < B.front()
            S.addBack(A.front()); A.eraseFront();
        else
            S.addBack(B.front()); B.eraseFront();
    while ¬A.empty()
        S.addBack(A.front()); A.eraseFront();
    while ¬B.empty()
        S.addBack(B.front()); B.eraseFront();
    return S
```