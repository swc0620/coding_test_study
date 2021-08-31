def solution(n):
    answer = 0
    num = i = 0
    while num <= n:
        i += 1
        num += i
    for j in range(1, i):
        if j % 2 == 1:
            if n / j == n // j:
                answer += 1
        else:
            q, r = divmod(n, j)
            if r == j / 2:
                answer += 1
    return answer

# print(solution(int(input())))