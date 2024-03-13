#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Dir_X[4] = {0, 0, 1, -1};
int Dir_Y[4] = {1, -1, 0, 0};

vector<string> grid;
vector<vector<bool>> visited(100, vector<bool>(100, false));
vector<vector<bool>> RG_visited(100, vector<bool>(100, false));
int N;

vector<int> area;
vector<int> RG_area;

void RG_bfs(int x, int y) {
    char color = grid[x][y];
    int num = 0;
    queue<pair<int, int>> next;
    next.push({x, y});
    num++;
    RG_visited[x][y] = true;
    
    switch (color)
    {
    case 'R':
    case 'G':
        while(!next.empty()) {
        int cx = next.front().first;
        int cy = next.front().second;

        next.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + Dir_X[i];
            int ny = cy + Dir_Y[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N)  continue;
            if(RG_visited[nx][ny]) continue;
            if(grid[nx][ny] == 'B')   continue;

            next.push({nx, ny});
            RG_visited[nx][ny] = true;
            num++;
        }
    }
        break;    
    
    case 'B':
        while(!next.empty()) {
        int cx = next.front().first;
        int cy = next.front().second;

        next.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + Dir_X[i];
            int ny = cy + Dir_Y[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N)  continue;
            if(RG_visited[nx][ny]) continue;
            if(grid[nx][ny] != color)   continue;

            next.push({nx, ny});
            RG_visited[nx][ny] = true;
            num++;
        }
    }
        break;
    }
    RG_area.push_back(num);
}
void bfs(int x, int y) {
    char color = grid[x][y];
    int num = 0;
    queue<pair<int, int>> next;
    next.push({x, y});
    num++;
    visited[x][y] = true;

    while(!next.empty()) {
        int cx = next.front().first;
        int cy = next.front().second;

        next.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + Dir_X[i];
            int ny = cy + Dir_Y[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N)  continue;
            if(visited[nx][ny]) continue;
            if(grid[nx][ny] != color)   continue;

            next.push({nx, ny});
            visited[nx][ny] = true;
            num++;
        }
    }
    area.push_back(num);
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        string temp;   cin >> temp;
        grid.push_back(temp);
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visited[i][j])   continue;
            bfs(i, j);
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(RG_visited[i][j])   continue;
            RG_bfs(i, j);
        }
    }
    cout << area.size() << " " << RG_area.size();

    return 0;
}