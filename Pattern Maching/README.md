# Pattern Maching
**패턴 매칭 알고리즘**

- brute-force
- Rabin-Karp
- KMP
- Boyer-Moore

# Pattern Matching

<br>

>  Given strings **T (text) and P (pattern)**, the pattern matching problem consists of **finding a substring** of T equal to P.

<br>

## Brute-Force Pattern Matching

- The brute-force pattern matching algorithm compares the pattern `P` with the text `T` for each possible shift of `P` relative to `T`, until either
  - a match is found, or 
  - all placements of the pattern have been tried. 
- Brute-force pattern matching runs in time `O(nm)`. 
- Example of worst case: 
  - `T = aaa … ah`
  - `P = aaah`
  - may occur in images and DNA sequences. 
  - unlikely in English text.

<br>

### Pseudo-Code

```
Algorithm BruteForceMatch(T, P):
	Input text T of size n and pattern
		P of size m
	Output starting index of a
		substring of T equal to P or -1
		if no such substring exists
	for i ¬ 0 to n - m
		{ test shift i of the pattern }
		j ¬ 0
		while j < m Ù T[i + j] = P[j]
			j ¬ j + 1
		if j = m
			return i {match at i}
		else
			break while loop {mismatch}
	return -1 {no match anywhere}
```

<br>

## Boyer-Moore Heuristics

- The Boyer-Moore’s pattern matching algorithm is based on two heuristics.
- **Looking-glass heuristic**: Compare P with a subsequence of T moving backwards. 
- **Character-jump heuristic**: When a mismatch occurs at `T[i] = c`.
- If `P` contains `c`, shift `P` to align the last occurrence of `c` in `P` with `T[i]`. 
- Else, shift `P` to align `P`[0] with `T`[i + 1].

<br>

- Example

![fig 1](C:\Users\SH.C\OneDrive - UNIST\바탕 화면\CS\Algorithm\Pattern Maching\fig 1.png)

<br>

### Last-Occurrence Function

- Boyer-Moore’s algorithm pre-processes the pattern `P` and the alphabet `S` to build the last-occurrence function `L` mapping `S` to integers, where `L(c)` is defined as 

  - the largest index `i` such that `P`[i] = c or 
  - -1 if no such index exists. 

- Example: 

  - `S = {a, b, c, d}` 
  - `P = abacab` 

  ![fig 2](C:\Users\SH.C\OneDrive - UNIST\바탕 화면\CS\Algorithm\Pattern Maching\fig 2.png)

  

- The last-occurrence function can be represented by an array indexed by the numeric codes of the characters. 

- The last-occurrence function can be computed in time `O(m + s)`, where `m` is the size of `P` and s is the size of `S`.

<br>

### Analysis

- Boyer-Moore’s algorithm runs in time `O(nm + s)`. 
- Example of worst case: 
- `T = aaa … a` 
- `P = baaa` 
- The worst case may occur in images and DNA sequences but is unlikely in English text.
- Boyer-Moore’s algorithm is significantly faster than the brute-force algorithm on English text.

<br>

![fig 4](C:\Users\SH.C\OneDrive - UNIST\바탕 화면\CS\Algorithm\Pattern Maching\fig 4.png)

<br>

### Pseudo-Code

![fig 3](C:\Users\SH.C\OneDrive - UNIST\바탕 화면\CS\Algorithm\Pattern Maching\fig 3.png)

```
Algorithm BoyerMooreMatch(T, P, S):
	L ¬ lastOccurenceFunction(P, S )
	i ¬ m - 1
	j ¬ m - 1
	repeat
		if T[i] = P[j]
			if j = 0
				return i { match at i }
			else
				i ¬ i - 1
				j ¬ j - 1
		else
			{ character-jump }
			l ¬ L[T[i]]
			i ¬ i + m – min(j, 1 + l)
			j ¬ m - 1
	until i > n - 1
	return -1 { no match }
```

<br>

## KMP

**Knuth-Morris-Pratt’s algorithm**

<br>

- Knuth-Morris-Pratt’s algorithm compares the pattern to the text in **left-to-right**, but shifts the pattern more intelligently than the brute-force algorithm.
- When a mismatch occurs, what is the **most** we can shift the pattern so as to avoid redundant comparisons? 
- Answer: the largest prefix of `P[0..j]` that is a suffix of `P[1..j]`.

<br>

![fig 5](C:\Users\SH.C\OneDrive - UNIST\바탕 화면\CS\Algorithm\Pattern Maching\fig 5.png)

<br>

### Failure Function

- Knuth-Morris-Pratt’s algorithm pre-processes the pattern to find matches of prefixes of the pattern with the pattern itself.
- The **failure function F(j)** is defined as the size of the largest prefix of `P[0..j]` that is also a suffix of `P[1..j]``.
- Knuth-Morris-Pratt’s algorithm modifies the brute-force algorithm so that if a mismatch occurs at `P[j != T[i]` we set `j <- F(j - 1)`.

<br>

![fig 6](C:\Users\SH.C\OneDrive - UNIST\바탕 화면\CS\Algorithm\Pattern Maching\fig 6.png)

<br>

### Algorithm

- The failure function can be represented by an array and can be computed in `O(m)` time.
- At each iteration of the while-loop, either 
  - `i` increases by one, or 
  - the shift amount i - j increases by at least one. (observe that `F(j - 1) < j`) 
  - Hence, there are no more than 2`n` iterations of the while-loop.
  - Thus, KMP’s algorithm runs in optimal time `O(m + n)`.

<br>

### Pseudo-Code

- **normal**

```
Algorithm KMPMatch(T, P):
	F ¬ failureFunction(P)
	i ¬ 0
	j ¬ 0
	while i < n
		if T[i] = P[j]
			if j = m - 1
				return i - j { match }
			else
				i ¬ i + 1
				j ¬ j + 1
		else
			if j > 0
				j ¬ F[j - 1]
			else
				i ¬ i + 1
	return -1 { no match }
```

<br>

- **failure function**

The failure function can be represented by an array and can be computed in `O(m)` time.

The construction is similar to the KMP algorithm itself.

At each iteration of the while-loop, either 

​	i increases by one, or 

​	the shift amount `i - j` increases by at least one. (observe that `F(j - 1) < j`) 

Hence, there are no more than 2m iterations of the while-loop.

```
Algorithm failureFunction(P):
	F[0] ¬ 0
	i ¬ 1
	j ¬ 0
	while i < m
		if P[i] = P[j]
			{we have matched j + 1 chars}
			F[i] ¬ j + 1
			i ¬ i + 1
			j ¬ j + 1
		else if j > 0 then
			{use failure function to shift P}
			j ¬ F[j - 1]
		else
			F[i] ¬ 0 { no match }
			i ¬ i + 1
```

