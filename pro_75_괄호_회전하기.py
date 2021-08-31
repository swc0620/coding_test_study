def checkBalanced(temp):
    stack = []
    for i in temp:
        if i == '(' or i == '{' or i == '[':
            stack.append(i)
        else:
            if i == ')' and stack and stack[-1] == '(':
                stack.pop()
            elif i == '}' and stack and stack[-1] == '{':
                stack.pop()
            elif i == ']' and stack and stack[-1] == '[':
                stack.pop()
            else:
                return False
    
    if stack:
        return False
    return True

def solution(s):
    answer = 0
    s_s = []
    temp = s
    for i in range(len(s)):
        temp = temp[1:] + temp[0]
        if checkBalanced(temp):
            answer += 1
    return answer

# print(solution(input()))