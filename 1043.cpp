#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<bool> knum(51, false);
vector<vector<bool>> meet(51, vector<bool>(51, false));
vector<bool> visited(51, false);
vector<vector<int>> party;
queue<int> q;

void bfs() {
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        visited[now] = true;
        knum[now] = true;

        for(int i = 1; i <= N; i++) {
            if(meet[now][i] && !visited[i]) {
                q.push(i);
            }
        }
    }
}

int main() {
    int answer = 0;
    cin >> N >> M;
    party.resize(M);
    int know;
    cin >> know;
    if(know == 0) {
        // 진실 아는 사람이 없으면 바로 파티 개수 출력
        cout << M;
        return 0;
    }
    else {
        // knum에서 진실 아는 사람의 번호 true로 만듦
        for(int i = 0; i < know; i++) {
            int k;
            cin >> k;
            knum[k] = true;
            q.push(k);
        }
    }
    
    for(int i = 0; i < M; i++) {
        int num;
        cin >> num;
        for(int j = 0; j < num; j++) {
            // i번째 파티에 참석하는 사람을 party[i]에 저장
            int person;
            cin >> person;
            party[i].push_back(person);
        }

        // 만났는지 meet을 통해 정보 저장
        // 만났으면 true, 안만났으면 false
        for(int j = 0; j < num; j++) {
            for(int k = 0; k < num; k++) {
                if(j != k) {
                    meet[party[i][j]][party[i][k]] = true;
                    meet[party[i][k]][party[i][j]] = true;
                }
            }
        }
    }

    bfs();

    for(int i = 0; i < party.size(); i++) {
        bool can = true;
        for(int j = 0; j < party[i].size(); j++) {
            if(knum[party[i][j]]) {
                can = false;
                break;
            }
        }
        if(can) {
            answer++;
        }
    }

    cout << answer;
    return 0;
}