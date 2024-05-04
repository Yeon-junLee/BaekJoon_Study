#include <iostream>
#include <vector>
#include <queue>
#define INF 100000000

using namespace std;

int V, E;
vector<pair<long long, long long>> graph[10001];
vector<bool> visited(10001, false);
long long answer = 0;

void Prim(int V) {
    int start = 1;

    priority_queue<pair<long long, long long>> next;
    next.push({0, 1});
    for(int i = 0; i < V; i++) {
        // 모든 노드가 포함되어야 하므로 V번 순회
        int cur = -1;
        while(!next.empty()) {
            cur = next.top().second;
            long long cost = -next.top().first;
            next.pop();
            if(!visited[cur]) {
                visited[cur] = true;
                answer += cost;
                break;
            }
        }
        for(int i = 0; i < graph[cur].size(); i++) {
            int node = graph[cur][i].first;
            long long ncost = graph[cur][i].second;
            if(!visited[node])  next.push({-ncost, node});
        }
    }
}

int main() {
    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    Prim(V); // 시작은 1번에서 한다고 생각
    
    cout << answer;

    return 0;
}