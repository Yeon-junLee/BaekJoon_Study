#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T;

int main() {
    cin >> T;
    vector<int> answer;
    for(int i = 0; i < T; i++) {
        int N, K;
        cin >> N >> K;
        vector<vector<int>> built(N + 1);
        // 짓는 순서 담은 vector
        vector<vector<int>> should(N + 1);
        // 짓는데 필요한 건물 담은 vector
        vector<int> D(N + 1);
        // 각 건물 당 짓는 시간
        vector<int> in(N + 1, 0);
        // 각 건물의 진입 차수
        for(int j = 1; j <= N; j++) {
            cin >> D[j];
        }
        for(int j = 0; j < K; j++) {
            int a, b;
            cin >> a >> b;
            built[a].push_back(b);
            should[b].push_back(a);
            in[b]++;
        }
        int W;
        cin >> W;
        vector<int> B;
        // W를 짓는데 필요한 건물 목록 vector
        B.push_back(W);
        int idx = 0;
        while(1) {
            if(idx >= B.size()) {
                break;
            }
            int cur = B[idx];
            if(should[cur].size() == 0) {
                idx++;
                continue;
            }
            for(int i = 0; i < should[cur].size(); i++) {
                B.push_back(should[cur][i]);
            }
            idx++;
        }

        queue<pair<int, int>> building;
        // (건물 번호, 들어간 순서)
        for(int i = 1; i <= N; i++) {
            if(in[i] == 0) {
                building.push({i, 1});
                in[i]--;
            }
        }
        vector<int> time[1001];
        int complete_order;
        while(!building.empty()) {
            int cur = building.front().first;
            int order = building.front().second;
            building.pop();
            if(find(B.begin(), B.end(), cur) == B.end())    continue;
            else    time[order].push_back(D[cur]);

            if(cur == W) {
                complete_order = order;
                break;
            }

            for(int i = 0; i < built[cur].size(); i++) {
                in[built[cur][i]]--;
            }
            for(int i = 1; i < in.size(); i++) {
                if(in[i] == 0) {
                    building.push({i, order + 1});
                    in[i]--;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= complete_order; i++) {
            ans += *max_element(time[i].begin(), time[i].end());
        }
        answer.push_back(ans);
    }
    
    for(auto a : answer) {
        cout << a << "\n";
    }
    return 0;
}