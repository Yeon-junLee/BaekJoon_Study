#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// pattern
//
// ***
// * *
// ***
//

int N;

void recursive(int x, int y, int n) {
    if((x / n) % 3 == 1 && (y / n) % 3 == 1) {
        cout << " ";
    }
    else {
        if(n == 1)  cout << "*";
        else        recursive(x, y, n / 3);
    }
}

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            recursive(i, j, N);
        }
        cout << "\n";
    }

    return 0;
}