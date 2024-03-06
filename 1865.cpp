#include <iostream>
#include <vector>
#include <algorithm>
#define INF (int)1e9

using namespace std;

vector<string> answer;

void solve() {
    int N, M, W;
    bool cycle;
    cin >> N >> M >> W;
    vector<pair<int, int>> route[501];
    for(int i = 0; i < M; i++) {
        int S, E, T;
        cin >> S >> E >> T;
        route[S].push_back({E, T});
        route[E].push_back({S, T});
    }
    for(int i = 0; i < W; i++) {
        int S, E, T;
        cin >> S >> E >> T;
        route[S].push_back({E, -T});
    }
    vector<int> dist(N + 1, INF);
    dist[1] = 0;
    for(int i = 1; i <= N; i++) {
        // 매 반복마다
        for(int j = 1; j <= N; j++) {
            // 모든 노드에서의 edge를 탐색
            for(int k = 0; k < route[j].size(); k++) {
                int next = route[j][k].first;
                int cost = route[j][k].second;

                if(dist[next] > dist[j] + cost) {
                    dist[next] = dist[j] + cost;

                    if(i == N) {
                        answer.push_back("YES");
                        return;
                    }
                }
            }
        }
    }
    answer.push_back("NO");
}

int main() {
    int TC;
    cin >> TC;
    for(int i = 0; i < TC; i++) {
        solve();
    }

    for(auto a : answer) {
        cout << a << "\n";
    }

    return 0;
}