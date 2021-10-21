T = int(input())
dp = [(0, 0)]*41
dp[0] = (1, 0)
dp[1] = (0, 1)

def fibonacci(N):
    if dp[N] != (0, 0):
        return dp[N]
    x1, y1 = fibonacci(N-1)
    x2, y2 = fibonacci(N-2)
    dp[N] = (x1 + x2, y1 + y2)
    return dp[N]


for _ in range(T):
    N = int(input())
    x, y = fibonacci(N)
    print(x, y)