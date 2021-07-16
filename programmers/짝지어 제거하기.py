def solution(s):
    stack = []
    for i in range(len(s)):
        if not stack: # stack이 비어있을 경우
            stack.append(s[i])
        else:
            if s[i] == stack[-1]: # 새로운 s 문자열이 이전의 문자열과 같을 경우
                stack.pop()
            else:
                stack.append(s[i])
    if stack:
        return 0
    else:
        return 1
