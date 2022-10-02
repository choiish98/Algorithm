# 플로이드-워셜

**그래프 이론**

**그래프 탐색**

**최단 경로**

<br>

## 정의

> 플로이드-워셜 알고리즘(Floyd-Warshall Algorithm)은 변의 가중치가 음이거나 양인 (음수 사이클은 없는) 가중 그래프에서 최단 경로들을 찾는 알고리즘이다.
>
> 알고리즘을 한 번 수행하면 모든 꼭짓점 쌍 간의 최단 경로의 길이(가중치의 합)을 찾는다.

<br>

### 특징

- 한 번의 실행으로 **모든 노드 간의 최단 경로**를 구할 수 있다.
- **음의 간선**도 사용할 수 있다.
- 핵심은 **거쳐가는 정점**을 기준으로 알고리즘을 수행하는 것이다.
- **다이나믹 프로그래밍**에 의거하여 수행한다.
- 시간 복잡도: `O(n^3)`
- 시간 복잡도가 높아 **그래프가 작을 때** 사용 가능하다.

<br>

## 과정

<br>

![4-Figure2-1](https://user-images.githubusercontent.com/56579239/193438473-757dbf88-c774-4791-9a8d-ac413bb37d90.png)

<br>

- 라운드로 구성되어, 라운드마다 **중간 노드**를 선택한다.
- 중간 노드를 거쳐가는 방법으로 모든 노드 간의 **경로를 측정**한다.
- 기존의 경로와 중간 노드를 거치는 방법 중 더 **짧은 경로를 선택**한다.
- 모든 노드에 대해 반복한다.

<br>

### Pseudo Code

<img src="https://user-images.githubusercontent.com/56579239/193438474-f60d9cd5-188a-446c-b36c-c17b74480dcf.png" alt="1oHRA" style="zoom:50%;" />

<br>

<br>

<h6>참고 자료</h6>

- [Wiki](https://namu.wiki/w/%ED%94%8C%EB%A1%9C%EC%9D%B4%EB%93%9C-%EC%9B%8C%EC%85%9C%20%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)
- [안경잡이 개발자](https://blog.naver.com/ndb796/221234427842)
- [print(cozak92)](https://velog.io/@roo333/Floyd-Warshall-Algorithm)