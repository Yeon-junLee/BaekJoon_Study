#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;

int main() {
    cin >> N;
    vector<int> num(N);
    for(int i = 0; i < N; i++) {
        cin >> num[i];
    }
    cin >> S;

    int midx;
    // 가장 큰 값을 가진 위치
    int sorted = 0;
    while(S > 0) {
        if(sorted == N) break;
        if(S <= N) {
            midx = max_element(num.begin() + sorted, num.begin() + sorted + S + 1) - num.begin();
            if(midx == sorted) {
                sorted++;
                continue;
            }
            while(midx > sorted) {
                swap(num[midx - 1], num[midx]);
                midx--;
                S--;
            }
            sorted++;
        }
        else {
            midx = max_element(num.begin() + sorted, num.end()) - num.begin();
            while(midx > sorted) {
                swap(num[midx - 1], num[midx]);
                midx--;
                S--;
            }
            sorted++;
        }
    }
    for(auto n : num) {
        cout << n << " ";
    }

    return 0;
}