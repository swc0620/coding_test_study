import sys
stick = list(sys.stdin.readline()[:-1])

stack = []
count = 0

for i in range(len(stick)):
    if i != 0:
        prev = stick[i-1]
    curr = stick[i]
    if curr == "(":
        stack.append(curr)
    else:
        if prev == "(":
            stack.pop()
            if stack:
                count += len(stack)
        else:
            stack.pop()
            count += 1

print(count)

