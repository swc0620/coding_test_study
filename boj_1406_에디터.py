import sys

stack1 = list(sys.stdin.readline()[:-1])

stack2 = []

M = int(sys.stdin.readline())
while M > 0:
    command = sys.stdin.readline()[:-1].split()
    if command[0] == "P":
        stack1.append(command[1])
    elif command[0] == "L":
        if stack1:
            stack2.append(stack1.pop())
    elif command[0] == "D":
        if stack2:
            stack1.append(stack2.pop())
    else:
        if stack1:
            stack1.pop()
    M -= 1

print("".join(stack1)+"".join(reversed(stack2)))