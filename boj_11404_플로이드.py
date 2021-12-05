import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
graph = [[float('inf')] * n for _ in range(n)]

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a-1][b-1] = min(graph[a-1][b-1], c)

for k in range(n):
    graph[k][k] = 0
    for i in range(n):
        for j in range(n):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

for row in graph:
    for i in range(n):
        if row[i] == float('inf'):
            row[i] = 0
        print(row[i], end=" ")
    print()