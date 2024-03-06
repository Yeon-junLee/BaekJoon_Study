#include <iostream>
#include <vector>
#include <algorithm>
#define INF 99999999

using namespace std;

int N, K;

vector<int> value(101, 0);
vector<int> dp(10001, INF);

int main() {
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> value[i];
        dp[value[i]] = 1;
    }
    for(int i = 1; i <=  K; i++) {
        for(int j = 1; j <= N; j++) {
            if(i - value[j] < 0)    continue;

            dp[i] = min(dp[i], dp[i - value[j]] + dp[value[j]]);
        }
    }

    if(dp[K] >= INF)    cout << - 1;
    else                cout << dp[K];

    return 0;
}