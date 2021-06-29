import sys
K = int(input())

stack = []

while K > 0:
    num = int(sys.stdin.readline())
    if not stack:
        stack.append(num)
    else:
        if num == 0:
            stack.pop()
        else:
            stack.append(num)
    K -= 1

print(sum(stack))