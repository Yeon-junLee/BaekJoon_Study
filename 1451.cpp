#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> square;

long long sum(int x1, int y1, int x2, int y2) {
    // square 벡터에서 (x1, y1)~(x2, y2) 까지의 합
    long long result = 0;
    for(int i = x1; i <= x2; i++) {
        for(int j = y1; j <= y2; j++) {
            result += square[i][j];
        }
    }
    return result;
}

void solve() {
    long long answer = 0;
    // x = i, y = j 기준으로 나눠짐
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int line_x = i, line_y = j;
            long long part1, part2, part3, part4;
            part1 = sum(0, 0, i, j);    // 왼쪽 위
            part2 = sum(0, j + 1, i, M - 1);    // 오른쪽 위
            part3 = sum(i + 1, 0, N - 1, j);    // 왼쪽 아래
            part4 = sum(0, 0, N - 1, M - 1) - part1 - part2 - part3;    // 오른쪽 아래   
            long long big1 = part1 + part2, big2 = part1 + part3, big3 = part2 + part4, big4 = part3 + part4;
            
            answer = max(answer, part1 * part2 * big4);
            answer = max(answer, big2 * part2 * part4);
            answer = max(answer, big1 * part3 * part4);
            answer = max(answer, big3 * part1 * part3);
        }
    }
    // 세로로 나누는 경우
    for(int i = 1; i <= M - 3; i++) {
        for(int j = i + 1; j <= M - 2; j++) {
            long long part1 = sum(0, 0, N - 1, i);
            long long part2 = sum(0, 0, N - 1, j) - part1;
            long long part3 = sum(0, 0, N - 1, M - 1) - part1 - part2;

            answer = max(answer, part1 * part2 * part3);
        }
    }
    // 가로로 나누는 경우
    for(int i = 1; i <= N - 3; i++) {
        for(int j = i + 1; j <= N - 2; j++) {
            long long part1 = sum(0, 0, i, M - 1);
            long long part2 = sum(0, 0, j, M - 1) - part1;
            long long part3 = sum(0, 0, N - 1, M - 1) - part1 - part2;

            answer = max(answer, part1 * part2 * part3);
        }
    }
    cout << answer;
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        vector<int> temp(M);
        for(int j = 0; j < M; j++) {
            temp[j] = tmp[j] - '0';
        }
        square.push_back(temp);
    }

    solve();

    return 0;
}