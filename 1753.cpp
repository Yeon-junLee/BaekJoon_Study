#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999

using namespace std;

int V, E, K;
vector<pair<int, int>> edge[20001];
vector<int> dist(20001, INF);

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        for(int i = 0; i < edge[cur].size(); i++) {
            int next = edge[cur][i].first;
            int ncost = edge[cur][i].second;

            if(dist[next] > cost + ncost) {
                dist[next] = cost + ncost;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main() {
    cin >> V >> E;
    cin >> K;
    for(int i = 0; i < E; i++) {
        int u, v, w;    cin >> u >> v >> w;
        edge[u].push_back({v, w});
    }
    dijkstra(K);
    for(int i = 1; i <= V; i++) {
        if(dist[i] == INF)  cout << "INF\n";
        else    cout << dist[i] << "\n";
    }

    return 0;
}