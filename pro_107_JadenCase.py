def solution(s):
    s = s.lower().split(" ")
    answer = ""
    for i in s:
        i = i.capitalize()
        answer += i + " "
    return answer[:-1]

# print(solution(input()))