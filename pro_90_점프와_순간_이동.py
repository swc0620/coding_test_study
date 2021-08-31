def solution(n):
    ans = 0
    while True:
        if n <= 0:
            return ans
        n, r = divmod(n, 2)
        if r == 1:
            ans += 1

# print(solution(int(input())))