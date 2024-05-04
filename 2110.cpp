#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<long long> house;

int main() {
    cin >> N >> C;
    for(int i = 0; i < N; i++) {
        long long tmp;
        cin >> tmp;
        house.push_back(tmp);
    }
    sort(house.begin(), house.end());
    long long start = 1;
    // 최소 거리 = 1
    long long end = house[N - 1] - house[0];
    // 최대 거리 = 시작 집 ~ 끝 집 거리
    long long ans = 0;
    while(start <= end) {
        long long mid = (start + end) / 2;
        // 공유기를 설치하는 데 사용할 최소 거리

        long long prev = house[0];
        int cnt = 1;
        for(int i = 1; i < N; i++) {
            if(house[i] - prev >= mid) {
                // 순회를 돌며 사용할 거리 이상인 집이 보이면 설치
                cnt++;
                prev = house[i];
            }
        }

        if(cnt >= C) {
            // 설치한 공유기 개수가 C보다 많으면 사용할 거리를 좀 더 늘려서 사용(지금도 정답으로 사용 가능하지만 최적의 해를 찾아야함)
            ans = max(ans, mid);
            start = mid + 1;
        }
        else if(cnt < C) {
            // 설치한 공유기 개수가 부족하면 사용할 거리를 줄여야함
            end = mid - 1;
        }
    }
    cout << ans;

    return 0;
}