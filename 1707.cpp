#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> color(20001, 0);

bool bfs(int start, vector<int> graph[]) {
    queue<int> node;
    node.push(start);

    while(!node.empty()) {
        int cur = node.front();
        int now_color = color[cur];
        node.pop();

        int next_color = now_color % 2 + 1;

        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if(!color[next]) {
                node.push(next);
                color[next] = next_color;
            }
            else if(color[next] != next_color) {
                return false;
            }
        }
    }
    return true;
}

string input(int V, int E) {
    vector<int> graph[20001];
    for(int i = 0; i < E; i++) {
        int a, b;   cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= V; i++) {
        if(color[i])  continue;
        bool check = bfs(i, graph);
        if(!check)  return "NO";
    }
    return "YES";
}

int main() {
    int K;  cin >> K;
    vector<string> answer;
    while(K--) {
        int V, E;   cin >> V >> E;
        answer.push_back(input(V, E));
        for(int i = 1; i <= V; i++) {
            color[i] = 0;
        }
    }
    for(auto ans : answer) cout << ans << "\n";

    return 0;
}