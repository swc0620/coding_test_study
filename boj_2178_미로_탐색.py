dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

N, M = map(int, input().split())
maze = []
for _ in range(N):
    row = list(map(int, list(input())))
    maze.append(row)
visited = [[0]*M for _ in range(N)]

def check_safe(x, y):
    if 0 <= x < N and 0 <= y < M:
        return True
    else:
        return False

def bfs(start_x, start_y):
    queue = [(start_x, start_y)]
    visited[start_x][start_y] = 1

    while queue:
        x, y = queue.pop(0)

        if x == N-1 and y == M-1:
            print(visited[N-1][M-1])
            break

        for i in range(4):
            new_x = x + dx[i]
            new_y = y + dy[i]
            if check_safe(new_x, new_y):
                if visited[new_x][new_y] == 0 and maze[new_x][new_y] == 1:
                    visited[new_x][new_y] = visited[x][y] + 1
                    queue.append((new_x, new_y))
    
bfs(0, 0)