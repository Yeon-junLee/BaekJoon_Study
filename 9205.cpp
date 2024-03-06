#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int GetDistance(pair<int, int> p1, pair<int, int> p2) {
    return abs(p2.first - p1.first) + abs(p2.second - p1.second);
}

string bfs(int hx, int hy, int fx, int fy, vector<pair<int, int>> combini, vector<bool> visited) {
    queue<pair<int, int>> place;
    place.push({hx, hy});
    int N = combini.size();

    while(!place.empty()) {
        int curx = place.front().first;
        int cury = place.front().second;

        place.pop();

        if(curx == fx && cury == fy) {
            return "happy";
        }

        for(int i = 0; i < N; i++) {
            if(visited[i])  continue;
            int nx = combini[i].first;
            int ny = combini[i].second;
            if(GetDistance({curx, cury}, {nx, ny}) > 1000)  continue;
            visited[i] = true;
            place.push({nx, ny});
        }
    }
 
    return "sad";
}

int main() {
    int t;
    cin >> t;
    vector<string> answer;
    for(int i = 0; i < t; i++) {
        int n;
        int hx, hy, fx, fy;
        vector<pair<int, int>> combini;
        cin>> n;
        cin >> hx >> hy;
        for(int j = 0; j < n; j++) {
            int x, y;
            cin >> x >> y;
            combini.push_back({x, y});
        }
        cin >> fx >> fy;
        combini.push_back({fx, fy});
        vector<bool> visited(n + 1, false);
        answer.push_back(bfs(hx, hy, fx, fy, combini, visited));
    }

    for(auto feeling : answer) {
        cout << feeling << "\n";
    }

    return 0;
}