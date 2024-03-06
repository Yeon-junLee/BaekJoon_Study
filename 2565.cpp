#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> elec;

int main() {
    cin >> N;
    int a, b;
    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        elec.push_back({a, b});
    }
    sort(elec.begin(), elec.end());

    vector<int> B;
    for(int i = 0; i < N; i++) {
        B.push_back(elec[i].second);
    }

    vector<int> DP(N, 0);
    // i번째 index에서 B가 증가하는 최대 길이 (LIS 알고리즘)
    for(int i = 0; i < N; i++) {
        DP[i] = 1;
        for(int j = 0; j < i; j++) {
            if(B[j] < B[i]) {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
    }
    cout << N - *max_element(DP.begin(), DP.end());

    return 0;
}