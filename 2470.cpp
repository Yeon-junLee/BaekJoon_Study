#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int idxl, idxr;
int MIN = 2000000000;
vector<int> sol(100000);

void b_search(int n) {
    int l = 0, r = n - 1;

    while(l <= r) {
        if(sol[l] + sol[r] == 0) {
            idxl = l;
            idxr = r;
            break;
        }
        else if(sol[l] + sol[r] > 0) {
            if(sol[l] + sol[r] < MIN) {
                MIN = sol[l] + sol[r];
                idxl = l;
                idxr = r;
            }
            r--;
        }
        else if(sol[l] + sol[r] < 0) {
            if(abs(sol[l] + sol[r]) < MIN) {
                MIN = abs(sol[l] + sol[r]);
                idxl = l;
                idxr = r;
            }
            l++;
        }
        if(l == r) {
            r--;
        }
    }
}

int main() {
    cin >> N;
    int plus = 0;
    for(int i = 0; i < N; i++) {
        cin >> sol[i];
        if(sol[i] > 0 && plus == 0) {
            plus = i;
        }
    }
    sort(sol.begin(), sol.begin() + N);
    
    if(sol[N - 1] <= 0) {
        cout << sol[N - 2] << " " << sol[N - 1];
        return 0;
    }
    if(sol[0] >= 0) {
        cout << sol[0] << " " << sol[1];
        return 0;
    }
    
    b_search(N);

    cout << sol[idxl] << " " << sol[idxr];

    return 0;
}