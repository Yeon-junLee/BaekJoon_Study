#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> num(100000, 0);
vector<int> psum(100000, 0);

int main() {
    cin >> N >> S;
    int answer = 99999999;
    for(int i = 1; i <= N; i++) {
        cin >> num[i];
        psum[i] = psum[i - 1] + num[i];
        if(num[i] >= S) {
            cout << 1;
            return 0;
        }
    }
    if(N == 1) {
        if(psum[1] == S) {
            cout << 1;
            return 0;
        }
        else {
            cout << 0;
            return 0;
        }
    }
    int left = N - 1, right = N;
    while(right > 1) {
        int sum = psum[right] - psum[left];
        if(sum >= S) {
            answer = answer > right - left ? right - left : answer;
            right--;

            if(right < left)    break;
        }
        else {
            if(left > 0)    left--;
            else    break;

            if(left < 0)    break;
        }
    }

    if(answer == 99999999)  cout << 0;
    else    cout << answer;

    return 0;
}