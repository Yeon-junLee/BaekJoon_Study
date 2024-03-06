#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, answer = 0;
vector<vector<int>> map;
vector<vector<int>> dist(100, vector<int>(100, 99999999));
int DirX[4] = {0, 0, 1, -1};
int DirY[4] = {1, -1, 0, 0};


void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;

    while(!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        cout << "현재 x, y : " << curx << ", " << cury << endl;

        for(int i = 0; i < 4; i++) {
            int nextx = curx + DirX[i];
            int nexty = cury + DirY[i];
            cout << "Next x : " << nextx << ", Next y : " << nexty << endl;
            if(nextx >= N || nextx < 0 || nexty < 0 || nexty >= M)  continue;

            if(map[nextx][nexty] == 0) {
                if(dist[nextx][nexty] > dist[curx][cury]) {
                    dist[nextx][nexty] = dist[curx][cury];
                    q.push({nextx, nexty});
                }
            }

            else if(map[nextx][nexty] == 1) {
                if(dist[nextx][nexty] > dist[curx][cury] + 1) {
                    dist[nextx][nexty] = dist[curx][cury] + 1;
                    q.push({nextx, nexty});
                }
            }
        }
    }
}

int main() {
    cin >> M >> N;
    map.resize(N);
    for(int i = 0; i < N; i++) {
        vector<int> tmp;
        string temp;
        cin >> temp;
        for(int j = 0; j < M; j++) {
            if(temp[j] == '0')  tmp.push_back(0);
            else                tmp.push_back(1);
        }
        map.push_back(tmp);
    }

    for(auto vec : map) {
        for(auto a : vec) {
            cout << a << " ";
        }
        cout << endl;
    }

    bfs();

    cout << dist[N - 1][M - 1];

    return 0;
}