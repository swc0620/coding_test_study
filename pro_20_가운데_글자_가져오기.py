def solution(s):
    answer = ''
    if len(s) % 2 == 0:
        i = len(s) // 2
        return s[i-1:i+1]
    else:
        i = len(s) // 2
        return s[i]

# s = input()
# print(solution(s))