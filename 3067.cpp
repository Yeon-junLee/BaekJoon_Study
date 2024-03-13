#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;  cin >> T;
    vector<int> answer;
    while(T--) {
        int N;  cin >> N;
        vector<int> coin(N);
        for(int i = 0; i < N; i++) {
            cin >> coin[i];
        }
        int M;  cin >> M;
        vector<int> DP(M + 1);
        DP[0] = 1;
        for(int i = 0; i < N; i++) {
            for(int j = coin[i]; j <= M; j++) {
                DP[j] += DP[j - coin[i]];
                // j - coin[i] 원에서 coin[i] 를 더하는 경우를 더해줌
            }
        }
        answer.push_back(DP[M]);
    }
    for(auto i : answer) {
        cout << i << endl;
    }

    return 0;
}