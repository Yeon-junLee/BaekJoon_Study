#include <iostream>
#include <vector>

using namespace std;

int N;
vector<bool> v(4000001, true);
vector<int> prime;

int main() {
    cin >> N;
    if(N == 1) {
        cout << 0;
        return 0;
    }

    int answer = 0;
    for(int i = 2; i * i <= N; i++) {
        if(v[i]) {
            for(int k = i * i; k <= N; k += i) {
                v[k] = false;
            }
        }
    }
    for(int i = 2; i <= N; i++) {
        if(v[i])    prime.push_back(i);
    }
    
    int lp = 0, rp = 0;
    int sum = prime[0];
    while(1) {
        if(lp > prime.size() - 1 || rp > prime.size() - 1) {
            break;
        }
        if(sum < N) {
            rp++;
            if(rp == prime.size()) {
                break;
            }
            sum += prime[rp];
        }
        else if(sum > N) {
            sum -= prime[lp];
            lp++;
        }
        else {
            answer++;
            sum -= prime[lp];
            lp++;
        }
    }

    cout << answer;

    return 0;
}