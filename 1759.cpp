#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int L, C;
vector<char> alpha;
vector<bool> used;
vector<char> password;
map<char, bool> vowel;

void print();

// 자음 2개 이상, 모음 1개 이상 체크
bool check(vector<char> password) {
    int cnt = 0;
    for(auto a : password) {
        if(vowel[a])    cnt++;
    }
    bool result = true;
    if(cnt < 1) {
        result = false;
    }
    if(L - cnt < 2) {
        result = false;
    }
    return result;
}

// 증가하는 순서인지 확인
bool check2(vector<char> password) {
    for(int i = 0; i < L - 1; i++) {
        if(password[i] > password[i + 1])   return false;
    }
    return true;
}

// 백트래킹
void backtrack(int len) {
    if(len == L) {
        if(!check(password))    return;
        if(!check2(password))   return;

        for(auto a : password)  cout << a;
        cout << "\n";
        return;
    }

    for(int i = 0; i < C; i++) {
        if(used[i]) continue;
        if(len >= 1) {
            if(password[len - 1] > alpha[i])    continue;
        }
        used[i] = true;
        password.push_back(alpha[i]);
        backtrack(len + 1);
        password.pop_back();
        used[i] = false;
    }
}

int main() {
    cin >> L >> C;
    used.resize(C);
    for(int i = 0; i < C; i++) {
        char temp;
        cin >> temp;
        alpha.push_back(temp);
    }
    for(char i = 'a'; i <= 'z'; i++) {
        if(i == 'a') {
            vowel[i] = true;
        }
        else if(i == 'e') {
            vowel[i] = true;
        }
        else if(i == 'i') {
            vowel[i] = true;
        }
        else if(i == 'o') {
            vowel[i] = true;
        }
        else if(i == 'u') {
            vowel[i] = true;
        }
        else {
            vowel[i] = false;
        }
    }

    sort(alpha.begin(), alpha.end());
    backtrack(0);

    return 0;
}