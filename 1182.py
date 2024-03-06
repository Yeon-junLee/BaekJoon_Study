import sys

def backtrack(i : int, SUM : int) :
    global answer
    if i >= N :
        return
    SUM += Set[i]
    if SUM == S :
        answer += 1
    backtrack(i + 1, SUM - Set[i])
    ### i번째 요소 제외하고 확인
    backtrack(i + 1, SUM)
    ### i번째 요소 포함하고 확인

N, S = map(int, input().split())

Set = list(map(int, input().split()))

answer = 0
backtrack(0, 0)
print(answer)