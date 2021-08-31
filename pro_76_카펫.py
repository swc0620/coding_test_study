def solution(brown, yellow):
    divisors = []
    for i in range(1, int(yellow**0.5) + 1):
        if yellow % i == 0:
            col = i
            row = yellow // i

            if (row + col) * 2 + 4 == brown:
                return [row+2, col+2]

# print(solution(int(input()), int(input())))