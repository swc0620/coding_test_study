def solution(n):
    answer = 0
    
    # m = int(n ** 0.5)
    for i in range(1, n + 1):
        if n % i == 0:
            answer += i # + (n / i)
    return answer
