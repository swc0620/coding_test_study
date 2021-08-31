def solution(s):
    stack = []
    for i in s:
        if not stack:
            stack.append(i)
        else:
            if stack[-1] == i:
                stack.pop()
            else:
                stack.append(i)
    if stack:
        answer = 0
    else:
        answer = 1

    return answer

print(solution(input()))