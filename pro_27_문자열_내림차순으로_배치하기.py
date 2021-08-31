def solution(s):
    sorted_s = sorted(s)
    answer = ''
    for i in sorted_s:
        answer += i
    return answer[::-1]
# print(solution(input()))