N = int(input())

for _ in range(N):
    ox = input()
    score = 0
    stack = []
    for idx, value in enumerate(ox):
        if value == 'O':
            stack.append('O')
            score += len(stack)
        else:
            stack = []
    print(score)