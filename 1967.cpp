#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> tree[10001];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int p, c, w;    cin >> p >> c >> w;
        tree[p].push_back({c, w});
    }
    //leaf-to-leaf 가중치의 최댓값
    

    return 0;
}