def solution(n, m):
    answer = []
    
    # x = min(n, m)
    # y = max(n, m)
    
    def gdc(n, m):
        while m > 0:
            n, m = m, n % m

        answer.append(n)
    
    gdc(n, m)
    
    lcm = answer[0] * (n // answer[0]) * (m // answer[0])
    answer.append(lcm)
    
    return answer
