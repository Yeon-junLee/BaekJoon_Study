import sys

def DP(N) :
    if N == 1 :
        print(1)
        return
    elif N == 2 :
        print(2)
        return
    elif N == 3 :
        print(3)
        return
    dp = [0 for _ in range(N + 1)]
    dp[1] = 1
    dp[2] = 2
    dp[3] = 3
    for i in range(4, N + 1) :
        dp[i] = dp[i - 1] + 1
        for j in range(1, i + 1) :
            if i - j * j < 0 :
                break
            if dp[i - j * j] + 1 < dp[i]:
                dp[i] = dp[i - j * j] + 1
    print(dp[N])
    
N = int(input())
DP(N)