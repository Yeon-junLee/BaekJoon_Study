#include <iostream>
#include <vector>
#include <queue>
#define INF 99999999

using namespace std;

int N, M;
vector<pair<int, int>> route[1001];
vector<int> dist(1001, INF);
vector<bool> visited(1001, false);

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(visited[cur])    continue;
        visited[cur] = true;

        for(int i = 0; i < route[cur].size(); i++) {
            int next = route[cur][i].first;
            int ncost = route[cur][i].second;

            if(dist[next] > cost + ncost) {
                dist[next] = cost + ncost;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main() {
    cin >> N;
    cin >> M;
    for(int i = 0; i < M; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        route[a].push_back({b, cost});
    }
    int start, end;
    cin >> start >> end;
    dijkstra(start);

    cout << dist[end];

    return 0;
}