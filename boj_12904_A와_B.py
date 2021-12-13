import sys
input = sys.stdin.readline

S = list(input().rstrip())
T = list(input().rstrip())

flag = False
while T:
    if T[-1] == 'A':
        T.pop()
    else:
        T.pop()
        T.reverse()
    if T == S:
        flag = True
        break

if flag:
    print(1)
else:
    print(0)