#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<pair<int, int>> con[1001];
vector<bool> visited(1001, false);

int Prim() {
    int answer = 0;
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < con[1].size(); i++) {
        int next = con[1][i].first;
        int cost = con[1][i].second;

        pq.push({-cost, next});
    }
    visited[1] = true;
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(!visited[cur]) {
            visited[cur] = true;
            answer += cost;
            for(int i = 0; i < con[cur].size(); i++) {
                int ncost = con[cur][i].second;
                int next = con[cur][i].first;
                if(!visited[next]) {
                    pq.push({-ncost, next});
                }
            }
        }
    }

    return answer;
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b, c;    cin >> a >> b >> c;
        con[a].push_back({b, c});
        con[b].push_back({a, c});
    }
    int answer = Prim();
    cout << answer;

    return 0;
}