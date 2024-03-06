#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int N, M;

vector<vector<int>> graph;

vector<int> make_num(int x, int y, int dif_x, int dif_y) {
    vector<int> candidate;
    candidate.push_back(0);
    while(x < N && x >= 0 && y < M && y >= 0) {
        candidate.push_back(candidate.back() * 10 + graph[x][y]);
        x += dif_x;
        y += dif_y;
    }
    candidate.front()--;

    return candidate;
}

bool check_pw(int num) {
    int sq = sqrt(num);
    if(sq * sq == num)  return true;
    else    return false;
}

vector<int> brute() {
    vector<int> answer;
    for(int x = 0; x < N; x++) {
        for(int y = 0; y < M; y++) {
            for(int dif_x = -8; dif_x <= 8; dif_x++) {
                for(int dif_y = -8; dif_y <= 8; dif_y++) {
                    if(dif_x == 0 && dif_y == 0)    continue;

                    vector<int> candidate= make_num(x, y, dif_x, dif_y);
                    for(auto num : candidate) {
                        if(num < 0) continue;
                        if(check_pw(num))   answer.push_back(num);
                    }
                }
            }
        }
    }
    return answer;
}

int main() {
    cin >> N >> M;
    graph.resize(N);
    for(int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < M; j++) {
            graph[i].push_back(temp[j] - '0');
        }
    }

    vector<int> answer = brute();
    if(answer.empty())  cout << -1;
    else    cout << *max_element(answer.begin(), answer.end());

    return 0;
}