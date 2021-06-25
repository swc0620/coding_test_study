import sys
n = int(input())

numlist = [n-i for i in range(n)]
stack = []
result = []
while n > 0:
    num = int(sys.stdin.readline())
    if not stack:
        while num > numlist[-1]:
            stack.append(numlist.pop())
            result.append("+")
        stack.append(numlist.pop())
        result.append("+")
        stack.pop()
        result.append("-")
    else:
        if num > stack[-1]:
            while num > numlist[-1]:
                stack.append(numlist.pop())
                result.append("+")
            stack.append(numlist.pop())
            result.append("+")
            stack.pop()
            result.append("-")
        elif num == stack[-1]:
            stack.pop()
            result.append("-")
        else:
            print("NO")
            break
    n -= 1
    if n == 0:
        print("\n".join(result))