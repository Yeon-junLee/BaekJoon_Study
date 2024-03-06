#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int DirX[4] = {0, 0, 1, -1};
int DirY[4] = {1, -1, 0, 0};

vector<pair<int, int>> land;
vector<vector<int>> map;

int N, M, Max = 0;

void bfs(int x, int y, vector<vector<int>> visited) {
    queue<pair<int, int>> next;

    next.push({x, y});
    visited[x][y] = 1;

    while(!next.empty()) {
        int curx = next.front().first;
        int cury = next.front().second;


        next.pop();

        for(int i = 0; i < 4; i++) {
            int nextx = curx + DirX[i];
            int nexty = cury + DirY[i];

            if(nextx >= N || nextx < 0 || nexty >= M || nexty < 0)  continue;
            if(map[nextx][nexty] == 0 || visited[nextx][nexty] > 0)    continue;

            next.push({nextx, nexty});
            visited[nextx][nexty] = visited[curx][cury] + 1;
            Max = max(Max, visited[nextx][nexty]);
        }
    }
}

int main() {
    cin >> N >> M;
    vector<vector<int>> visited(N, vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        vector<int> temp;
        for(int j = 0; j < M; j++) {
            char t;
            cin >> t;
            if(t == 'L') {
                temp.push_back(1);
                land.push_back({i, j});
            }
            else {
                temp.push_back(0);
            }
        }
        map.push_back(temp);
    }

    for(auto l : land) {
        bfs(l.first, l.second, visited);
    }

    cout << Max - 1;

    return 0;
}