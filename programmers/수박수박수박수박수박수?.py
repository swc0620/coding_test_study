def solution(n):
    pattern = '수박'
    if n % 2 == 0: # 짝수
        answer = pattern * (n // 2)
    else:
        answer = pattern * (n // 2) + '수'
    return answer
