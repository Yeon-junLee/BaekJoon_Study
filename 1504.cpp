#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 99999999


using namespace std;

int N, E;
int v1, v2;

vector<pair<int, int>> edge[801];
vector<vector<int>> dist(801, vector<int>(801, INF));

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start][start] = 0;

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(int i = 0; i < edge[cur].size(); i++) {
            int next = edge[cur][i].first;
            int ncost = edge[cur][i].second;

            if(dist[start][next] > cost + ncost) {
                dist[start][next] = cost + ncost;
                pq.push({-dist[start][next], next});
            }
        }
    }
}

int main() {
    cin >> N >> E;
    long long answer = 0;
    for(int i = 0; i < E; i++) {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        edge[n1].push_back({n2, w});
        edge[n2].push_back({n1, w});
    }
    cin >> v1 >> v2;

    dijkstra(1);
    dijkstra(v1);
    dijkstra(v2);

    answer = min(dist[1][v1] + dist[v1][v2] + dist[v2][N], dist[1][v2] + dist[v2][v1] + dist[v1][N]);
    if(answer >= INF) cout << -1;
    else    cout << answer;

    return 0;
}