#include <iostream>
#include <vector>
#include <algorithm>
#define INF 999999999

using namespace std;

int N, M;
vector<vector<int>> dist(101, vector<int>(101, INF));
vector<int> bacon(101);

void floyd(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                int temp = dist[j][i] + dist[i][k];
                if(temp < dist[j][k]) {
                    dist[j][k] = temp;
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    for(int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }

    floyd(N);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            bacon[i] += dist[i][j];
        }
    }

    cout << min_element(bacon.begin() + 1, bacon.begin() + N + 1) - bacon.begin();

    return 0;
}