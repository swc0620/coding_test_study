import sys

def change_direction(move, second, direction):
    if second in move.keys():
        if direction == 0:
            if move[second] == 'L':
                direction = 2
            else:
                direction = 3
        elif direction == 1:
            if move[second] == 'L':
                direction = 3
            else:
                direction = 2
        elif direction == 2:
            if move[second] == 'L':
                direction = 1
            else:
                direction = 0
        elif direction == 3:
            if move[second] == 'L':
                direction = 0
            else:
                direction = 1
    return direction

N = int(sys.stdin.readline())
K = int(sys.stdin.readline())

game_board = [[0] * N for _ in range(N)]

for _ in range(K):
    x, y = map(int, sys.stdin.readline().strip().split())
    game_board[x-1][y-1] = 1

L = int(sys.stdin.readline())
move = {}

for _ in range(L):
    x, y = sys.stdin.readline().strip().split()
    x = int(x)
    move[x] = y

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
direction = 3
second = 1

snake = [(0, 0)]

while True:
    head_x, head_y = snake[0]
    tail_x, tail_y = snake[-1]

    new_x = head_x + dx[direction]
    new_y = head_y + dy[direction]

    if (new_x, new_y) in snake[1:] or (new_x < 0 or new_y < 0 or new_x > N-1 or new_y > N-1):
        print(second)
        break

    if len(snake) > 1:
        for index in range(len(snake)-1, 0, -1):
            snake[index] = snake[index - 1]

    if game_board[new_x][new_y] == 1:
        game_board[new_x][new_y] = 0
        snake.append((tail_x, tail_y))
        pass

    snake[0] = (new_x, new_y)

    direction = change_direction(move, second, direction)

    second += 1


    
