def solution(s):
    answer = True
    if len(s) == 4 or len(s) == 6:
        for i in s:
            if ord(i) < 48 or 57 < ord(i):
                answer = False
                break
    else:
        answer = False
    return answer

# print(solution(input()))