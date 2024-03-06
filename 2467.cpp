#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<int> sol(100000);

int b_search(int target, int idx, int n) {
    int l = idx + 1, r = n - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(sol[mid] < target) {
            l = mid + 1;
        }
        else if(sol[mid] > target) {
            r = mid - 1;
        }
        else {
            return mid;
        }
    }
    return l;
}

int main() {
    cin >> N;
    int plus = 0;
    int MIN = 2000000000;
    int idxl, idxr;
    for(int i = 0; i < N; i++) {
        cin >> sol[i];
        if(sol[i] > 0 && plus == 0) {
            plus = i;
        }
    }
    if(sol[N - 1] <= 0) {
        cout << sol[N - 2] << " " << sol[N - 1];
        return 0;
    }
    if(sol[0] >= 0) {
        cout << sol[0] << " " << sol[1];
        return 0;
    }

    for(int i = 0; i < N; i++) {
        //cout << "현재 MIN : " << MIN << ", 현재 정답 인덱스 : " << idxl << ", " << idxr <<endl; 
        int t_idx = b_search(-sol[i], i, N);
        //cout << i << "번째 용액 : " << sol[i] << "의 target index : " << t_idx << endl;
        if(t_idx == i)  t_idx++;
        else if(t_idx == N) t_idx--;
        else {
            // t_idx가 정확하게 나오지 않아 그 이전 값들과 비교
            int another = t_idx - 1;
            int solution = sol[t_idx];
            if(another == i)    another--;
            if(abs(sol[another] + sol[i]) < abs(solution + sol[i])) {
                t_idx = another;
            }
        }
        //cout << "현재 용액의 합의 절댓값 : " << abs(sol[i] + sol[t_idx]) << endl;
        if(abs(sol[i] + sol[t_idx]) < MIN) {
            MIN = abs(sol[i] + sol[t_idx]);
            idxl = i;
            idxr = t_idx;
        }
    }

    cout << sol[idxl] << " " << sol[idxr];

    return 0;
}