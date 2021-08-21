def solution(s):
    answer = True
    stack = []
    for p in s:
        if p == '(':
            stack.append(p)
        else:
            if stack:
                stack.pop()
            else:
                answer = False
                break
    if stack:
        answer = False

    return answer