dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
    
def BST(x, y, room):
    visited = [[0 for _ in range(5)] for _ in range(5)]
    man_len = 0
    tmp1 = [[x, y]]
    tmp2 = [0]
    
    while len(tmp1) > 0:
        x = tmp1[0][0]
        y = tmp1[0][1]
        tmp1.remove(tmp1[0])
        visited[x][y] = 1
        man_len = tmp2[0]
        tmp2.remove(tmp2[0])
        
        if man_len == 2: # 맨해튼 거리 2 초과이므로 더 이상 진행할 필요 없음
            return 1
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < 5 and 0 <= ny < 5:
                if visited[nx][ny] == 0:
                    if room[nx][ny] == 'P':
                        return 0
                    elif room[nx][ny] == 'O':
                        tmp1.append([nx, ny])
                        tmp2.append(man_len + 1)
    return 1

def solution(places):
    answer = []
    for room in places:
        stop = False
        for x in range(5):
            for y in range(5):
                if room[x][y] == 'P':
                    if BST(x, y, room) == 0:
                        stop = True
                        break
            if stop == True:
                break
        if stop == True:
            answer.append(0)
        else:
            answer.append(1)
    return answer
