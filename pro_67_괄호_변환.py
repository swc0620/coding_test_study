def isUCorrect(p):
    stack = []
    for s in p:
        if s == '(':
            stack.append(s)
        elif s == ')':
            if stack:
                stack.pop()
            else:
                return False
    if stack:
        return False
    return True

def isUBalanced(p):
    l_cnt = 0
    r_cnt = 0
    u = ''
    v = ''
    stack = []
    iscorrect = True
    if p == '':
        return p
    for idx, s in enumerate(p):
        if s == '(':
            l_cnt += 1
            stack.append(s)
        elif s == ')':
            r_cnt += 1
            if stack:
                stack.pop()
            else:
                iscorrect = False
        u += s
        if l_cnt == r_cnt:
            v = p[idx+1:]
            break
    else:
        if stack:
            iscorrect = False
    if iscorrect:
        return u + isUBalanced(v)
    else:
        temp = '('
        temp += isUBalanced(v)
        temp += ')'
        u = u[1:-1]
        new_u = ''
        for idx in range(len(u)):
            if u[idx] == '(':
                new_u += ')'
            elif u[idx] == ')':
                new_u += '('
        return temp + new_u

def solution(p):
    answer = ''
    if isUCorrect(p):
        return p 
    return isUBalanced(p)

# print(solution(input()))