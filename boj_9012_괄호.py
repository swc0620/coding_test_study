import sys
N = int(input())

while N > 0:
    paren = list(sys.stdin.readline())
    paren = paren[:-1]
    stack = []
    passed = 1
    for i in range(len(paren)):
        if paren[i] == "(":
            stack.append(paren[i])
        else:
            if len(stack) > 0:
                stack = stack[:-1]
            else:
                passed = 0
                print("NO")
                break
    if len(stack) > 0:
        passed = 0
        print("NO")
    if passed == 1:
        print("YES")
    N -= 1