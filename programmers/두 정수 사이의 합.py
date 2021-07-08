def solution(a, b):
    answer = 0
    if a == b:
        answer = a
    else:
        for n in range(min(a, b), max(a, b) + 1):
            answer += n
    return answer
