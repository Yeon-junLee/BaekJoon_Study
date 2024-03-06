#include <iostream>
#include <vector>

using namespace std;

int N, K;

vector<vector<long long>> dp(201, vector<long long>(201, 0));

int main() {
    cin >> N >> K;
    // 중복 조합 : N개의 의자가 있을 때 0개 이상을 가진 조각 K개로 나누는 거
    // 다시 생각해보면 N개의 의자 사이에 K - 1개의 나눔 판을 중복해서 끼워넣는 방법의 수
    dp[0][0] = 1;
    for(int i = 1; i <= K; i++) {
        dp[0][i] = 1;
        dp[1][i] = i;
    }
    for(int i = 0; i <= N; i++) {
        dp[i][1] = 1;
    }

    // dp[N][K] = dp[N][K-1] + dp[N-1][K-1] + dp[N-2][K-1] + ... + dp[1][K-1] + dp[0][K-1]
    for(int i = 2; i <= K; i++) {
        for(int j = 2; j <= N; j++) {
            for(int k = 0; k <= j; k++) {
                dp[j][i] += dp[j - k][i - 1];
                dp[j][i] %= 1000000000;
            }
        }
    }
    // K > 0 이어야됨

    cout << dp[N][K] % 1000000000;

    return 0;
}