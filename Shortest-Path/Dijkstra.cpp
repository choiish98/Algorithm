#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int number = 6;                // 노드 수
vector<pair<int, int>> arr[7]; // 간선 수
int d[6];                      // 최소 비용

void dijkstra(int start)
{
    d[start] = 0; // 자신까지의 거리 = 0
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(start, 0));

    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();

        if (d[cur.first] < cur.second) // 최단 거리가 아닐 경우 스킵
            continue;

        for (pair<int, int> next : arr[cur.first])
        {
            if (cur.second + next.second < d[next.first])
            {
                d[next.first] = cur.second + next.second;
                pq.push(make_pair(next.first, next.second + cur.second));
            }
        }
    }
}

int main(void)
{
    for (int i = 1; i <= number; i++)
    {
        d[i] = 10000000; // 초기화
    }

    // 간선 추가 필요

    for (int i = 1; i <= number; i++)
        cout << d[i];
}