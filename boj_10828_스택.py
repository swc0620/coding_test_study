import sys
N = int(input())

stack = []
while N > 0:
    command = sys.stdin.readline().split()
    if command[0] == "push":
        X = command[1]
        stack.append(X)
    elif command[0] == "pop":
        if len(stack) > 0:
            print(stack[-1])
            stack = stack[:-1]
        else:
            print(-1)
    elif command[0] == "size":
        print(len(stack))
    elif command[0] == "empty":
        if len(stack) > 0:
            print(0)
        else:
            print(1)
    else:
        if len(stack) > 0:
            print(stack[-1])
        else:
            print(-1)
    N -= 1