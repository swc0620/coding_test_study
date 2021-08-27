def solution(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    
    dp = [0, 1]
    
    for i in range(2, n+1):
        dp.append((dp[i-1]+ dp[i-2]) % 1234567)
    return dp[n]