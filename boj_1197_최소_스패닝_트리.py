import sys
input = sys.stdin.readline
V, S = map(int, input().strip().split())

edge = []
for _ in range(S):
    a, b, w = map(int, input().strip().split())
    edge.append((w, a, b))

edge.sort(key=lambda x: x[0])

parent = list(range(V + 1))


def union(a, b):
    a = find(a)
    b = find(b)

    if b < a:
        parent[a] = b
    else:
        parent[b] = a


def find(a):
    if a == parent[a]:
        return a
    parent[a] = find(parent[a])
    return parent[a]


cnt = 0
for w, s, e in edge:
    if find(s) != find(e):
        union(s, e)
        cnt += w

print(cnt)