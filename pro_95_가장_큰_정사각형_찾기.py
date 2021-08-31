def solution(board):
    answer = -1

    for i in range(1, len(board)):
        for j in range(1, len(board[0])):
            if board[i][j] == 1:
                board[i][j] = min(board[i-1][j-1], board[i][j-1], board[i-1][j]) + 1

    for row in board:
        answer = max(max(row), answer)

    return answer**2