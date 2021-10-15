# union-find algorithm
import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline

n, m = map(int, input().split())
parent = [i for i in range(n+1)]

def find(x):
    if parent[x] == x:
        return x
    
    parent[x] = find(parent[x])
    return parent[x]

def union(x, y):
    x = find(x)
    y = find(y)

    if x < y:
        parent[y] = x
    else:
        parent[x] = y

for _ in range(m):
    command, num1, num2 = map(int, input().split())
    if command == 0:
        union(num1, num2)
    elif command == 1:
        if find(num1) == find(num2):
            sys.stdout.write("YES\n")
        else:
            sys.stdout.write("NO\n")