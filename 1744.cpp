#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main() {
    cin >> N;
    vector<int> num(N);
    for(int i = 0; i < N; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    for(auto a : num)   cout << a << endl;
    long long answer = 0;
    vector<bool> check(N, false);
    int minus = -1;
    if(num[N - 1] > 0) {
        for(int i = N - 1; i >= 1; i -= 2) {
            if(num[i] * num[i - 1] <= 0 || check[i] || check[i - 1]) {
                if(num[i] > 0) {
                    answer += num[i];
                    check[i] = true;
                    minus = i - 1;
                }
                else    minus = i;
                break;
            }
            if(num[i] * num[i - 1] > 0 && num[i] < 0) {
                minus = i;
                break;
            }
            check[i] = true;
            check[i - 1] = true;
            if(num[i] + num[i - 1] > num[i] * num[i - 1])   answer += num[i] + num[i - 1];
            else    answer += num[i] * num[i - 1];
        }
    }
    else {
        minus = N - 1;
    }
    if(minus >= 0) {
        for(int i = 0; i <= minus; i += 2) {
            if(i + 1 >= N)  break;
            if(num[i] * num[i + 1] < 0 || check[i] || check[i + 1]) break;
            check[i] = true;
            check[i + 1] = true;
            answer += num[i] * num[i + 1];
        }
    }
    for(int i = 0; i < N; i++) {
        if(!check[i]) {
            check[i] = true;
            answer += num[i];
        }
    }
    cout << answer;
    return 0;
}