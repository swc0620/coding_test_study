dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def check_safe(x, y, n, m):
    if 0 <= x < n and 0 <= y < m:
        return True
    return False

def bfs(maps):
    n = len(maps)
    m = len(maps[0])
    queue = [(0, 0, 1)]

    while queue:
        char_x, char_y, count = queue.pop(0)
        if maps[char_x][char_y] == 1:
            maps[char_x][char_y] = count+1
            for i in range(4):
                new_x = char_x + dx[i]
                new_y = char_y + dy[i]
                if check_safe(new_x, new_y, n, m) and maps[new_x][new_y] == 1:
                    queue.append((new_x, new_y, count+1))
        if char_x == n-1 and char_y == m-1:
            return count
    
    return -1

def solution(maps):
    return bfs(maps)

# maps = [list(map(int, input().split())) for _ in range(5)]
# print(solution(maps))