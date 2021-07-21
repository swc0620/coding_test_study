def solution(n, a, b):
    answer = 0
    # 토너먼트이므로 a와 b는 반드시 만난다는 것을 이용 -> n 파라미터는 필요가 없음
    while True:
        answer += 1
        a = int(a / 2 + 0.5)
        b = int(b / 2 + 0.5)
        
        if a == b:
            break
    return answer
