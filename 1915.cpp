#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> square(1001, vector<int>(1001,0));

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string tmp; cin >> tmp;
        for(int j = 1; j <= m; j++) {
            square[i][j] = tmp[j - 1] - '0';
        }
    }
    int maxl = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(square[i][j] != 0) {
                square[i][j] = min({square[i - 1][j - 1], square[i - 1][j], square[i][j - 1]}) + 1;
            }
            maxl = max(maxl, square[i][j]);
        }
    }
    cout << maxl * maxl;
    return 0;
}