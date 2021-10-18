from collections import deque

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

N = int(input())
_map = []
for _ in range(N):
    _map.append(list(map(int, input())))

def bfs(start, cnt):
    queue = deque()
    cnt += 1
    queue.append(start)
    x, y = start
    _map[x][y] = 0

    while queue:
        x, y = queue.popleft()
        for i in range(4):
            new_x = x + dx[i]
            new_y = y + dy[i]

            if 0 <= new_x < N and 0 <= new_y < N:
                if _map[new_x][new_y] != 0:
                    cnt += 1
                    queue.append((new_x, new_y))
                    _map[new_x][new_y] = 0
    return cnt
        
counts = []
village = 0

for x in range(N):
    for y in range(N):
        if _map[x][y] != 0:
            village += 1
            cnt = bfs((x, y), 0)
            counts.append(cnt)
print(village)
counts.sort()
for count in counts:
    print(count)