dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def check_safe(x, y):
    if 0 <= x < 5 and 0 <= y < 5:
        return True
    return False

def check_distancing(room_map, x, y):
    if check_safe(x-1, y):
        print(1)
        if room_map[x-1][y] == 'P':
            return False
        elif room_map[x-1][y] == 'O':
            if check_safe(x-2, y) and room_map[x-2][y] == 'P':
                return False
            if check_safe(x-1, y-1) and room_map[x-1][y-1] == 'P':
                return False
            if check_safe(x-1, y+1) and room_map[x-1][y+1] == 'P':
                return False
    if check_safe(x+1, y):
        print(2)
        if room_map[x+1][y] == 'P':
            return False
        elif room_map[x+1][y] == 'O':
            if check_safe(x+2, y) and room_map[x+2][y] == 'P':
                return False
            if check_safe(x+1, y-1) and room_map[x+1][y-1] == 'P':
                return False
            if check_safe(x+1, y+1) and room_map[x+1][y+1] == 'P':
                return False    
    if check_safe(x, y-1):
        print(3)
        if room_map[x][y-1] == 'P':
            return False
        elif room_map[x][y-1] == 'O':
            if check_safe(x, y-2) and room_map[x][y-2] == 'P':
                return False
            if check_safe(x-1, y-1) and room_map[x-1][y-1] == 'P':
                return False
            if check_safe(x+1, y-1) and room_map[x+1][y-1] == 'P':
                return False  
    if check_safe(x, y+1):
        print(4)
        if room_map[x][y+1] == 'P':
            return False
        elif room_map[x][y+1] == 'O':
            if check_safe(x, y+2) and room_map[x][y+2] == 'P':
                return False
            if check_safe(x-1, y+1) and room_map[x-1][y+1] == 'P':
                return False
            if check_safe(x+1, y+1) and room_map[x+1][y+1] == 'P':
                return False  
    return True

def bfs(room_map):
    checked = [[-1 for _ in range(5)] for _ in range(5)]
    queue = [(0, 0)]

    while queue:
        check_x, check_y = queue.pop(0)
        if checked[check_x][check_y] == -1:
            print(check_x, check_y)
            checked[check_x][check_y] = 1
            for i in range(4):
                new_x = check_x+dx[i]
                new_y = check_y+dy[i]

                if check_safe(new_x, new_y):
                    if room_map[new_x][new_y] == 'P':
                        if check_distancing(room_map, new_x, new_y):
                            queue.append((new_x, new_y))
                        else:
                            return 0
                    else:
                        queue.append((new_x, new_y))
    return 1

def solution(places):
    answer = []
    for place in places:
        room_map = []
        for row in place:
            room_map.append(list(row))
        answer.append(bfs(room_map))
    return answer

# places = [input().split() for _ in range(5)]
# print(solution(places))