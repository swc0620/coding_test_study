from collections import deque

def solution(s):
    answer = 0
    queue = deque(s)
    
    for i in range(len(s)):
        tmp = queue.popleft()
        queue.append(tmp)
        if checkPairs(queue) == True:
            answer+=1
            
    return answer

def checkPairs(queue):
    stack = []
    
    for c in queue:
        if c == '(' or c == '{' or c == '[':
            stack.append(c)
        else:
            if len(stack) == 0:
                return False
            x = stack.pop()
            
            # 밑 코드는 괄호 짝 검사
            if c == ')' and x != '(':
                return False
            elif c == ')' and x != '(':
                return False
            elif c == '}' and x != '{':
                return False
            
    return len(stack) == 0
