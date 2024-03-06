import sys

def bfs(V, visited) :
    q= list()
    q.append(V)
    visited[V] = True

    while q:
        cur = q[0]
        q.pop(0)
        print(cur, end=' ')
        for node in edge[cur] :
            if visited[node] :
                continue
            q.append(node)
            visited[node] = True

def dfs(V, visited) :
    visited[V] = True
    print(V, end=' ')
    for node in edge[V] :
        if visited[node] :
            continue
        dfs(node, visited)


N, M, V = map(int, input().split())

edge = [[] for _ in range(N + 1)]

for _ in range(M) :
    a, b = map(int, input().split())
    edge[a].append(b)
    edge[b].append(a)

for i in edge :
    i.sort()

visited1 = [False for i in range(N + 1)]
visited2 = [False for i in range(N + 1)]
dfs(V, visited1)
print()
bfs(V, visited2)
