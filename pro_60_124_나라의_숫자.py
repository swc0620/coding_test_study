def solution(n):
    answer = ''
    while n > 0:
        q, r = divmod(n, 3)
        if r == 0:
            answer = '4' + answer
            q -= 1
        elif r == 1:
            answer = '1' + answer
        elif r == 2:
            answer = '2' + answer
        
        n = q
    return answer