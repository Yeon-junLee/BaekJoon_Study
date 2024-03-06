#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

int main() {
    cin >> N >> K;
    vector<pair<int, int>> obj;
    for(int i = 0; i < N; i++) {
        int W, V;
        cin >> W >> V;
        obj.push_back({W, V});
    }
    vector<vector<int>> dp(N + 1, vector<int>(K + 1));
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            // 현재 배낭에 들어갈 수 있는 무게가 j 일때
            // i 번째 물건에서의 검사
            int c_weight = obj[i - 1].first;
            int c_value = obj[i - 1].second;
            // i 번째 물건의 무게가 j 보다 작은 경우
            if(c_weight <= j) {
                dp[i][j] = max(dp[i - 1][j - c_weight] + c_value, dp[i - 1][j]);
                // 총 무게가 j - c_weight 일때의 value + c_value와 i -1 번째의 최대 value를 비교
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    cout << dp[N][K];

    return 0;
}