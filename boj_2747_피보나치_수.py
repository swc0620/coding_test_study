n = int(input())

dp = [0, 1, 1]

if n == 1:
    print(1)
elif n == 2:
    print(1)
else:
    i = 2
    while i <= n:
        dp.append(dp[i] + dp[i-1])
        i += 1
    print(dp[n])
