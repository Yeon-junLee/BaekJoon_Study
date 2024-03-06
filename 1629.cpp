#include <iostream>
#include <vector>

using namespace std;

long long A, B, C;

int main() {
    cin >> A >> B >> C;

    long long answer = 1;

    // (A * A) % C = ((A % C) * (A % C)) % C
    // ((A * A) * A) % C = (((A % C) * (A % C)) * (A % C)) % C
 	//	                        ㄴ> == (A * A) % C

    while(B > 0) {
        if(B % 2) {
            answer *= A;
            answer %= C;
        }

        A *= A;
        A %= C;

        B /= 2;
    }

    cout << answer;

    return 0;
}