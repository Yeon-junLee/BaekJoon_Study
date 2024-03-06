#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> num(3, vector<int>(3, 0));
vector<vector<int>> mindp(3, vector<int>(3, 0));
vector<vector<int>> maxdp(3, vector<int>(3, 0));

int main() {
    cin >> N;
    cin >> num[0][0] >> num[0][1] >> num[0][2];

    for(int i = 0; i < 3; i++) {
        mindp[0][i] = num[0][i];
        maxdp[0][i] = num[0][i];
    }

    for(int i = 1; i < N; i++) {
        int before = (i - 1) % 3;
        int after = i % 3;
        cin >> num[after][0] >> num[after][1] >> num[after][2];

        mindp[after][0] = min(mindp[before][0] + num[after][0], mindp[before][1] + num[after][0]);
        mindp[after][1] = min(mindp[before][1] + num[after][1], min(mindp[before][0] + num[after][1], mindp[before][2] + num[after][1]));
        mindp[after][2] = min(mindp[before][2] + num[after][2], mindp[before][1] + num[after][2]);

        maxdp[after][0] = max(maxdp[before][0] + num[after][0], maxdp[before][1] + num[after][0]);
        maxdp[after][1] = max(maxdp[before][1] + num[after][1], max(maxdp[before][0] + num[after][1], maxdp[before][2] + num[after][1]));
        maxdp[after][2] = max(maxdp[before][2] + num[after][2], maxdp[before][1] + num[after][2]);
    }

    int r = (N - 1) % 3;
    cout << *max_element(maxdp[r].begin(), maxdp[r].end()) << " " << *min_element(mindp[r].begin(), mindp[r].end());

    return 0;
}