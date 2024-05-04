#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
    while(1) {
        cin >> n;
        if(n == 0)  break;
        vector<long long> height;
        for(int i = 0; i < n; i++) {
            long long tmp;  cin >> tmp;
            height.push_back(tmp);
        }
        
    }

    return 0;
}