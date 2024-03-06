import sys
from collections import deque

N, M = map(int, input().split())
dq = deque(range(1, N + 1))

target = list(map(int, input().split()))

answer = 0

for i in target :
    if i == dq[0] :
        dq.popleft()
        continue
    size = len(dq)
    mid = int(size / 2)
    idx = 0
    for index in range(size) :
        if dq[index] == i :
            idx = index
    if size % 2 == 1 :
        if idx <= mid :
            while dq[0] != i :
                dq.rotate(-1)
                answer += 1
            dq.popleft()
        else :
            while dq[0] != i :
                dq.rotate(1)
                answer += 1
            dq.popleft()
    else :
        if idx < mid :
            while dq[0] != i :
                dq.rotate(-1)
                answer += 1
            dq.popleft()
        else :
            while dq[0] != i :
                dq.rotate(1)
                answer += 1
            dq.popleft()

print(answer)