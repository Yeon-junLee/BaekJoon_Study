#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<pair<int, int>> P;
vector<pair<int, int>> Q;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if(a.second == b.second)    return a.first < b.first;
    return a.second < b.second;
}

int bruteforce(vector<pair<int, int>> P) {
    int dist = 99999999999999;
    for(int i = 0; i < P.size(); i++) {
        for(int j = i + 1; j < P.size(); j++) {
            int newd = pow(P[i].first - P[j].first, 2) + pow(P[i].second - P[j].second, 2);
            dist = min(dist, newd);
        }
    }

    return dist;
}

int ECP(vector<pair<int, int>> P, vector<pair<int, int>> Q) {
    int N = P.size();
    int mid;
    if(N % 2)   mid = N / 2 + 1;
    else        mid = N / 2;
    vector<pair<int, int>> Pl(P.begin(), P.begin() + mid);
    vector<pair<int, int>> Pr(P.begin() + mid + 1, P.end());
    vector<pair<int, int>> Ql(Q.begin(), Q.begin() + mid);
    vector<pair<int, int>> Qr(Q.begin() + mid + 1, Q.end());

    int dl = ECP(Pl, Ql);
    int dr = ECP(Pr, Qr);
    int d = min(dl, dr);
    int m = P[mid - 1].first;
    vector<pair<int, int>> S;

    for(auto coor : Q) {
        int x = coor.first;
        if(abs(x - m) < d) {
            S.push_back(coor);
        }
    }
    int dminsq = d * d;
    for(int i = 0; i < N - 1; i++) {
        int k = i + 1;
        while(k <= N - 1 && int(pow(S[k].second - S[i].second, 2)) < dminsq) {
            dminsq = min(int(pow(S[k].first - S[i].first, 2) + pow(S[k].second - S[i].second, 2)), dminsq);
            k++;
        }
    }

    return dminsq;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        int a, b;   cin >> a >> b;
        P.push_back({a, b});
        Q.push_back({a, b});
    }
    sort(P.begin(), P.end());
    sort(Q.begin(), Q.end(), cmp);
    
    if(N <= 2) {
        cout << bruteforce(P);
    }
    else {
        cout << ECP(P, Q);
    }

    return 0;
}