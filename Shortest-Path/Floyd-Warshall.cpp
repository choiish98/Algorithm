#include <iostream>
#include <algorithm>
#define INF 1 << 20
using namespace std;

int n, m;          // 노드 개수, 간선 개수
int d[1000][1000]; // 최단 경로 배열

void floyd_warshall()
{
    for (int m = 1; m <= n; m++)         // 중간 노드
        for (int s = 1; s <= n; s++)     // 시작 노드
            for (int e = 1; e <= n; e++) // 마지막 노드
                // 최단 경로 업데이트
                d[s][e] = min(d[s][e], d[s][m] + d[m][e]);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j) // 자신으로 가는 길은 0
                d[i][j] = INF;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }

    floyd_warshall();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << d[i][j] << " ";
        cout << "\n";
    }
}