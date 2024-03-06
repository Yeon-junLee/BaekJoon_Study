#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int N;
vector<string> word;
vector<int> pos;
map<char, int> alpha;
map<char, int> weight;

bool cmp(const pair<char, int>& a, const pair<char, int>& b) {
    if(a.second == b.second)    return a.first > b.first;
    return a.second > b.second;
}

int main() {
    cin >> N;
    int answer = 0;
    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        word.push_back(tmp);
    }
    for(char i = 'A'; i <= 'Z'; i++) {
        weight[i] = 0;
    }
    for(int i = 0; i <= 9; i++) {
        pos.push_back(i);
    }
    for(int i = 0; i < N; i++) {
        int len = word[i].length();
        for(int j = 0; j < word[i].length(); j++) {
            weight[word[i][j]] += pow(10, len);
            len--;
        }
    }
    vector<pair<char, int>> vec(weight.begin(), weight.end());
    sort(vec.begin(), vec.end(), cmp);
    for(auto i : vec) {
        alpha[i.first] = pos.back();
        pos.pop_back();
    }
    
    vector<int> num(N);
    for(int i = 0; i < N; i++) {
        int leng = word[i].length();
        int n = 0;
        int idx = 0;
        while(leng > 0) {
            n += alpha[word[i][idx]] * pow(10, leng - 1);
            leng--;
            idx++;
        }
        num[i] = n;
    }
    for(auto i : num) {
        answer += i;
    }
    cout << answer;

    return 0;
}