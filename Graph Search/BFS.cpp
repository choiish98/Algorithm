#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N = 5; // 노드
int R = 5; // 간선
vector<int> vec[N]; // 트리

void bfs(int start) {
  bool visited[10000]; // 방문 체크 배열
  memset(visited, false, sizeof(visited));
  queue<int> q; // 방문 체크 배열
  q.push(start);

  while(!q.empty()) {
    int cur = q.front();
    cout << "cur: " << cur << "\n";
    q.pop();

    for(int i : vec[cur]) { // 트리에 연결된 간선들
      if(!visited[i]) { // 방문하지 않았으면
        q.push(i); // 큐에 추가
        visited[d] = true; // 방문 체크
      }
    }
  }
}

int main() {
  for(int i = 0; i < R; i++) {
    // node 간선 추가 해주세요
  }

  bfs(start);
  cout << "bfs done \n";

  return 0;
}