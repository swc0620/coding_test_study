n = int(input())

dp = [None, 1, 2]
if n <= 2:
    print(dp[n])
else:
    i = 3
    while i <= n:
        dp.append((dp[i-1] + dp[i-2]) % 10007)
        i += 1
    print(dp[n] % 10007)