import sys

K, N = map(int, input().split())
lan = list()
for i in range(K) :
    tmp = int(input())
    lan.append(tmp)
mi = 1
ma = int(max(lan))
answer = 0

while mi <= ma :
    mid = (mi + ma) // 2
    total = 0
    total = sum(l // mid for l in lan)
    if total >= N :
        mi = mid + 1
    else :
        ma = mid - 1
print(ma)