from collections import deque

dx = [-1, -1, -1, 0, 1, 1, 1, 0]
dy = [-1, 0, 1, 1, 1, 0, -1, -1]

def bfs(start, visited):
    queue = deque()
    queue.append(start)
    visited.append(start)

    while queue:
        x, y = queue.popleft()
        for i in range(8):
            new_x = x + dx[i]
            new_y = y + dy[i]
            if 0 <= new_x < h and 0 <= new_y < w:
                if island_map[new_x][new_y] != 0 and (new_x, new_y) not in visited:
                    island_map[new_x][new_y] = 0
                    queue.append((new_x, new_y))
                    visited.append((new_x, new_y))


while True:
    w, h = map(int, input().split())
    if w == 0 and h == 0:
        break
    island_map = []
    for _ in range(h):
        row = list(map(int, input().split()))
        island_map.append(row)
        
    visited = []
    cnt = 0
    for i in range(h):
        for j in range(w):
            if island_map[i][j] != 0:
                bfs((i,j), [])
                cnt += 1
    print(cnt)