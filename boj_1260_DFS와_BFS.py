import sys
input = sys.stdin.readline

N, M, V = map(int, input().split())
edges = [[0] * (N+1) for _ in range(N+1)]

for _ in range(M):
    start, end = map(int, input().split())
    edges[start][end] = 1
    edges[end][start] = 1

def bfs(start):
    visited = [start]
    queue = [start]
    while queue:
        now = queue.pop(0)
        for i in range(len(edges[now])):
            if edges[now][i] == 1 and i not in visited:
                queue.append(i)
                visited.append(i)
    return visited

def dfs(start, visited):
    visited.append(start)
    for i in range(len(edges[start])):
        if edges[start][i] == 1 and i not in visited:
            dfs(i, visited)
    return visited

print(*dfs(V, []))
print(*bfs(V))

