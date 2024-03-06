#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 999999999

using namespace std;

int N, M;
vector<int> edge[101];
vector<vector<int>> dist(101, vector<int>(101, INF));
vector<int> bacon(101);

void dijkstra(int node) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, node});

    while(!pq.empty()) {
        int cur = pq.top().second;
        int cost = -pq.top().first;

        pq.pop();

        for(int i = 0; i < edge[cur].size(); i++) {
            int next = edge[cur][i];

            if(dist[node][next] > cost + 1) {
                dist[node][next] = cost + 1;
                pq.push({-dist[node][next], next});
            }
        }
    }
    int total = 0;
    for(int i = 1; i <= N; i++) {
        total += dist[node][i];
    }
    bacon[node] = total;
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }
    for(int i = 1; i <= N; i++) {
        dijkstra(i);
    }

    cout << min_element(bacon.begin() + 1, bacon.begin() + N + 1) - bacon.begin();

    return 0;
}