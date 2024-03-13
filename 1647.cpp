#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 999999999

using namespace std;

int N, M;

vector<pair<int, int>> edge[100001];
vector<bool> visited(100001, false);
vector<int> chosen;

void Prim(int start) {
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < edge[start].size(); i++) {
        int next = edge[start][i].first;
        int cost = edge[start][i].second;
        
        pq.push({-cost, next});
    }
    visited[start] = true;
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(!visited[cur]) {
            visited[cur] = true;
            chosen.push_back(cost);
            for(int i = 0; i < edge[cur].size(); i++) {
                int ncost = edge[cur][i].second;
                int next = edge[cur][i].first;
                if(!visited[next])  pq.push({-ncost, next});
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b, c;    cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    Prim(1);
    int idx = max_element(chosen.begin(), chosen.end()) - chosen.begin();
    chosen.erase(chosen.begin() + idx);
    int answer = 0;
    for(auto cost : chosen) answer += cost;
    cout << answer;

    return 0;
}