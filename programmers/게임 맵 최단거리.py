from collections import deque
def solution(maps):
    answer = -1
    n, m = len(maps), len(maps[0])
    s, e = (0, 0), (n - 1, m - 1)
    
    visit = [[0] * m for _ in range(n)]
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    
    q = deque()
    q.append(s)
    while q:
        x, y = q.popleft()
        if (x, y) == e: 
            return visit[x][y] + 1

        for i in range(4):
            xx = x + dx[i]
            yy = y + dy[i]
            if 0 > xx or n <= xx or 0 > yy or m <= yy: continue
            if not maps[xx][yy]: continue
            if visit[xx][yy]: continue
            visit[xx][yy] = visit[x][y] + 1
            q.append((xx, yy))

    return answer
