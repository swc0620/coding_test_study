from collections import deque

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

T = int(input())
for _ in range(T):
    M, N, K = map(int, input().split())
    field = [[0] * N for _ in range(M)]

    for _ in range(K):
        X, Y = map(int, input().split())
        field[X][Y] = 1

    def bfs(start):
        queue = deque()
        queue.append(start)
        while queue:
            x, y = queue.popleft()
            for k in range(4):
                new_x = x + dx[k]
                new_y = y + dy[k]
                if 0 <= new_x < M and 0 <= new_y < N:
                    if field[new_x][new_y] == 1:
                        field[new_x][new_y] = 0
                        queue.append((new_x, new_y))

    cnt = 0
    for i in range(M):
        for j in range(N):
            if field[i][j] == 1:
                cnt += 1
                bfs((i, j))
    print(cnt)