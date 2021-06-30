import sys

while True:
    line = sys.stdin.readline().rstrip()

    if line == ".":
        break

    true_flag = 1
    stack = []

    for i in range(len(line)):
        if line[i] == "(":
            stack.append("(")
        elif line[i] == ")":
            if stack and stack[-1] == "(":
                stack.pop()
            else:
                true_flag = 0
                break
        elif line[i] == "[":
            stack.append("[")
        elif line[i] == "]":
            if stack and stack[-1] == "[":
                stack.pop()
            else:
                true_flag = 0
                break

    if true_flag and not stack:
        print("yes")
    else: 
        print("no")
