#include <iostream>
#include <map>

using namespace std;

long long N, P, Q;
map<long long, long long> m;

long long dfs(long long N) {
    if(m.find(N) != m.end())    return m[N];
    return m[N] = dfs(N / P) + dfs(N / Q);
}

int main() {
    cin >> N >> P >> Q;
    m[0] = 1;
    cout << dfs(N);

    return 0;
}