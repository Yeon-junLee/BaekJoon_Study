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

        queue<int> building;
        // 현재 지을 수 있는 건물
        for(int i = 1; i <= N; i++) {
            if(in[i] == 0) {
                if(find(B.begin(), B.end(), i) == B.end())  continue;
                building.push(i);
                in[i]--;
            }
        }
        
        int total = 0, left_time = 0;
        vector<int> time;
        while(1) {
            while(!building.empty()) {
                int cur = building.front();
                building.pop();
                time.push_back(D[cur]);
                for(int i = 0; i < built[cur].size(); i++) {
                    if(find(B.begin(), B.end(), built[cur][i]) == B.end())  continue;
                    in[built[cur][i]]--;
                }
            }
        }

    }


    for(auto ans : answer) cout << ans << "\n";
}

