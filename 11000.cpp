#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> course;
priority_queue<int, vector<int>, greater<int>> endtime;

int main() {
    int N;  cin >> N;
    for(int i = 0; i < N; i++) {
        int S, T;   cin >> S >> T;
        course.push({S, T});
    }
    int answer = 1;
    int end = course.top().second;
    endtime.push(end);
    course.pop();
    while(!course.empty()) {
        int start = course.top().first;
        int end = course.top().second;
        course.pop();
        //cout << "이번 강의 시작하는 시간 : " << start << endl;
        //cout << "가장 빨리 끝나는 강의 시간 : " << endtime.top() << endl;
        if(endtime.top() <= start) {
            //cout << "그거보다 빨리 끝나니까 그 강의실 사용\n";
            endtime.pop();
            endtime.push(end);
        }
        else{
            //cout << "더 빨리 끝나는 강의가 없어서 강의실 추가\n";
            answer++;
            endtime.push(end);
        }
    }
    cout << answer;

    return 0;
}