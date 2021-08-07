def check_safe(i, j, m, n):
    if 0 <= i < m and 0 <= j < n:
        return True
    return False

def mark_true(flags, board):
    for flag in flags:
        i, j = flag
        board[i][j] = 0
        board[i+1][j] = 0
        board[i][j+1] = 0
        board[i+1][j+1] = 0
    return board

def move_key(m, n, board, flags):
    for j in range(n):
        for i in range(m):
            for k in range(i, m):
                if board[k][j] == 0:
                    break
            else:
                continue
            if i == k:
                continue
            for x in range(k, i, -1):
                board[x][j] = board[x-1][j]
            board[i][j] = 0
    return board


def solution(m, n, board):
    answer = 0
    board = [list(row) for row in board]
    while True:
        flags = []
        for i in range(m):
            for j in range(n):
                character = board[i][j]
                if character == 0:
                    continue
                if not check_safe(i+1, j, m, n) or not check_safe(i, j+1, m, n) or not check_safe(i+1, j+1, m, n):
                    continue
                if board[i+1][j] != character or board[i][j+1] != character or board[i+1][j+1] != character:
                    continue
                flags.append((i, j))
        if not flags:
            break
        board = mark_true(flags, board)
        board = move_key(m, n, board, flags)

    for i in range(m):
        for j in range(n):
            if board[i][j] == 0:
                answer += 1
    return answer

# m = int(input())
# n = int(input())
# board = input().split()
# print(solution(m, n, board))