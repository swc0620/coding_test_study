dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def check_safe(pos):
    if pos[0] < -5 or pos[0] > 5:
        return False
    if pos[1] < -5 or pos[1] > 5:
        return False
    return True

def solution(dirs):
    answer = 0
    lines = []
    curr = [0, 0]
    for way in dirs:
        if way == 'U':
            new = [curr[0] + dx[0], curr[1] + dy[0]]
            if check_safe(new):
                if (curr[0], curr[1], curr[0] + dx[0], curr[1] + dy[0]) not in lines and (curr[0] + dx[0], curr[1] + dy[0], curr[0], curr[1]) not in lines:
                    lines.append((curr[0], curr[1], curr[0] + dx[0], curr[1] + dy[0]))
                curr = new
        elif way == 'R':
            new = [curr[0] + dx[1], curr[1] + dy[1]]
            if check_safe(new):
                if (curr[0], curr[1], curr[0] + dx[1], curr[1] + dy[1]) not in lines and (curr[0] + dx[1], curr[1] + dy[1], curr[0], curr[1]) not in lines:
                    lines.append((curr[0], curr[1], curr[0] + dx[1], curr[1] + dy[1]))
                curr = new
        elif way == 'D':
            new = [curr[0] + dx[2], curr[1] + dy[2]]
            if check_safe(new):
                if (curr[0], curr[1], curr[0] + dx[2], curr[1] + dy[2]) not in lines and (curr[0] + dx[2], curr[1] + dy[2], curr[0], curr[1]) not in lines:
                    lines.append((curr[0], curr[1], curr[0] + dx[2], curr[1] + dy[2]))
                curr = new
        elif way == 'L':
            new = [curr[0] + dx[3], curr[1] + dy[3]]
            if check_safe(new):
                if (curr[0], curr[1], curr[0] + dx[3], curr[1] + dy[3]) not in lines and (curr[0] + dx[3], curr[1] + dy[3], curr[0], curr[1]) not in lines:
                    lines.append((curr[0], curr[1], curr[0] + dx[3], curr[1] + dy[3]))
                curr = new
    
    return len(lines)

dirs = input()
print(solution(dirs))