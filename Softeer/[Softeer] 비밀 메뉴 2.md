# [Softeer] 비밀 메뉴 2

**DP**

**LCS**

<br>

> 21년 재직자 대회 본선  (난이도 3)

<br>

### 문제 및 입출력

![제목 없음](https://user-images.githubusercontent.com/56579239/194010532-3826da97-b17d-487a-860f-e09c2cff8441.png)

<br>

### 문제 접근

이 문제는 DP의 **memoization**을 활용하여 풀어야 하는 문제이다.

<Br>

두 문자열을 비교하여 연속하는 최장 부분 수열을 골라내야 한다.

이분 탐색을 이용하여 부분 수열을 탐색하면,

시간 복잡도 `O(N^2 * logN)`이기 때문에 시간 초과에 걸리게 된다.

<br>

이 문제와 같이 부분 수열과 관련된 알고리즘을 생각해보면, **LCS**를 떠올리게 될 것이다.

LCS는 연속하지 않은 부분도 고려하여, 최장 공통 부분 수열을 찾는 알고리즘이다.

여기서 연속할 때만 고려하게 되면, 

문제에서 요구하는 연속하는 최장 공통 부분 수열이다.

<br>

LCS를 일치할 때만 증가하는 방식으로 구현하면 시간 복잡도 `O(N^2)`으로 풀이할 수 있다.

이를 고려하여 구현하면 아래와 같다.

<br>

### 구현

```cpp
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
  int N, M, K, s1[3002], s2[3002];
  int dp[3001][3001] = {
      0,
  };
  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++)
    cin >> s1[i];
  for (int i = 1; i <= M; i++)
    cin >> s2[i];

  int max = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (s1[i] == s2[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
	  }
	  if (dp[i][j] > max) max = dp[i][j];
	}
  }
  
  cout << max;
  return 0;
}
```

