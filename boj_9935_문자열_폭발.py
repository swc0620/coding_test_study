import sys
from collections import deque

input = sys.stdin.readline

S = list(input().rstrip())
bomb = list(input().rstrip())

stack = deque()

for s in S:
    stack.append(s)

    if len(stack) >= len(bomb):
        flag = True

        for i in range(len(bomb)):
            if stack[len(stack)-len(bomb)+i] != bomb[i]:
                flag = False

        if flag == True:
            for _ in range(len(bomb)):
                stack.pop()
if stack:
    print(("").join(stack))
else:
    print("FRULA")