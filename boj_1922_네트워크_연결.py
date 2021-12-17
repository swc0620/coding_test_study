import sys
input = sys.stdin.readline

N = int(input())
M = int(input())

parent = [i for i in range(N+2)]

def find(u):
    if u != parent[u]:
        parent[u] = find(parent[u])
    return parent[u]

def union(u, v):
    u_root = find(u)
    v_root = find(v)
    parent[u_root] = v_root

graph = []
for _ in range(M):
    a, b, c = map(int, input().rstrip().split())
    graph.append((a, b, c))
graph.sort(key=lambda x: -x[2])

res = 0
num = 1
while num < N:
    a, b, cost = graph.pop()
    if find(a) != find(b):
        union(a, b)
        res += cost
        num += 1
print(res)