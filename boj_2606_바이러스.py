N = int(input())
E = int(input())
network = [[0] * N for _ in range(N)]
for _ in range(E):
    start, end = map(int, input().split())
    network[start-1][end-1] = 1
    network[end-1][start-1] = 1

def dfs(x):
    for i in range(N):
        if network[x][i] == 1 and i not in visited:
            visited.append(i)
            dfs(i)
    return visited

visited = [0]
dfs(0)
print(len(visited)-1)