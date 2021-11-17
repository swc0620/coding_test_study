N = int(input())

dp = [[0,0] for _ in range(N+1)]

for i in range(1, N+1):
    score = int(input())

    if i == 1:
        dp[i][0] = score
        dp[i][1] = score
    elif i == 2:
        dp[i][0] = dp[i-1][1] + score
        dp[i][1] = score
    else:
        dp[i][0] = dp[i-1][1] + score
        dp[i][1] = max(dp[i-2]) + score
    
print(max(dp[N]))
