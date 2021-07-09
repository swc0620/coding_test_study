def solution(s):
    sign = 1
    if s[0] == '-':
        s = s[1:]
        sign = -1
    answer = int(s) * sign
    return answer