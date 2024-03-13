import sys

def comb(m : int, n : int) :
    dp = [[0 for j in range(m + 1)] for i in range(m + 1)]
    for i in range(m + 1) :
        for j in range(n + 1) :
            if i == j and j == 0 :
                dp[i][j] = 1
            else :
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
    
    return dp[m][n]

answer = list()
T = int(input())
for i in range(T) :
    n, m = map(int, input().split())
    print(comb(m, n))