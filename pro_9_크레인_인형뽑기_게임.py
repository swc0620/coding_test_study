def return_doll(board, move):
    for row in board:
        if row[move-1] != 0:
            doll = row[move-1]
            row[move-1] = 0
            return board, doll
    return board, None

def solution(board, moves):
    answer = 0
    stack = []
    for move in moves:
        # print(stack)
        board, doll = return_doll(board, move)
        # print(doll)

        if stack and doll == stack[-1]:
            stack.pop()
            answer += 2
        elif not doll:
            pass
        else:
            stack.append(doll)
    return answer

# board = []
# for _ in range(5):
#     row = list(map(int, input().split(",")))
#     board.append(row)
# moves = list(map(int, input().split(",")))

# print(solution(board, moves))